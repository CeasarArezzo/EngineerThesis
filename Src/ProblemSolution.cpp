#include <algorithm>
#include "ProblemSolution.h"

#include <iostream>

using std::max;

size_t calculateCompletionTime(ProblemInstance* pI, vector<size_t>* solution, size_t job, size_t machine);

size_t calculateMakespan2(ProblemInstance* pI, vector<size_t> solution)
{
	return calculateCompletionTime(pI, &solution, solution.size() - 1, pI->noOfMachines - 1);
}

size_t calculateCompletionTime(ProblemInstance* pI, vector<size_t>* solution, size_t job, size_t machine)
{
	if (job == 0 && machine == 0)
	{
		return pI->procTime[solution->at(job)][machine];
	}
	else if (job == 0) //machine > 0
	{
		return calculateCompletionTime(pI, solution, job, machine - 1) + pI->procTime[solution->at(job)][machine];
	}
	else if (machine == 0) //job > 0
	{
		return calculateCompletionTime(pI, solution, job - 1, machine) + pI->procTime[solution->at(job)][machine];
	}
	else //job > 0 && machine > 0
	{
		return max(calculateCompletionTime(pI, solution, job - 1, machine),
			calculateCompletionTime(pI, solution, job, machine - 1)) + pI->procTime[solution->at(job)][machine];
	}
}

size_t calculateMakespan(ProblemInstance* pI, vector<size_t> solution)
{
	vector<vector<size_t>> partMakespan(solution.size(), vector<size_t>(pI->noOfMachines, 0));
	partMakespan.at(0).at(0) = pI->procTime[solution.at(0)][0];
	for (size_t mchn = 1; mchn < pI->noOfMachines; mchn++)
	{
		partMakespan.at(0).at(mchn) = partMakespan.at(0).at(mchn - 1) + pI->procTime[solution.at(0)][mchn];
	}
	for (size_t job = 1; job < solution.size(); job++)
	{
		partMakespan.at(job).at(0) = partMakespan.at(job - 1).at(0) + pI->procTime[solution.at(job)][0];
		for (size_t mchn = 1; mchn < pI->noOfMachines; mchn++)
		{
			partMakespan.at(job).at(mchn) = max(partMakespan.at(job).at(mchn - 1),
				partMakespan.at(job - 1).at(mchn)) + pI->procTime[solution.at(job)][mchn];
		}
	}
	/*for (size_t job = 0; job < solution.size(); job++)
	{
		for (size_t mchn = 0; mchn < pI->noOfMachines; mchn++)
		{
			std::cout << partMakespan.at(job).at(mchn) << " ";
		}
		std::cout << "\n";
	}*/
	return partMakespan.at(solution.size() - 1).at(pI->noOfMachines - 1);
}