#include <algorithm>
#include "ProblemSolution.h"

#include <iostream>

using std::max;

size_t calculateCompletionTime(ProblemInstance* pI, vector<size_t>* solution, size_t job, size_t machine);

size_t calculateMakespan(ProblemInstance* pI, vector<size_t> solution)
{
	return calculateCompletionTime(pI, &solution, pI->noOfJobs - 1, pI->noOfMachines - 1);
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