#include "NehSolver.h"
#include <queue>
#include <utility>
using std::pair;

typedef pair<size_t, size_t> pi;

size_t getMakespanWithInsert(ProblemInstance* pI, vector<size_t> solution, size_t insertIndex, size_t insertValue);

vector<size_t> NehSolver::solve(ProblemInstance* pI)
{
	std::priority_queue< pair<size_t, size_t>> unsortedTasks;
	for (size_t job = 0; job < pI->noOfJobs; job++)
	{
		size_t sum = 0;
		for (size_t mchn = 0; mchn < pI->noOfMachines; mchn++)
		{
			sum += pI->procTime[job][mchn];
		}
		unsortedTasks.push(std::make_pair(sum, job));
	}
	vector<size_t> solution;
	while(!unsortedTasks.empty())
	{
		size_t nextTask = unsortedTasks.top().second;
		size_t currBest = UINT_MAX;
		size_t currBestValue = UINT_MAX;
		for (size_t pos = 0; pos <= solution.size(); pos++)
		{
			size_t currValue = getMakespanWithInsert(pI, solution, pos, nextTask);
			//std::cout << unsortedTasks.size() << " " << solution.size() << "\n";
			if (currValue < currBestValue)
			{
				currBestValue = currValue;
				currBest = pos;
			}
		}
		solution.insert(solution.begin() + currBest, nextTask);
		unsortedTasks.pop();
	}
	return solution;
}

size_t NehSolver::getMakespanWithInsert(ProblemInstance* pI, vector<size_t> solution, size_t insertIndex, size_t insertValue)
{
	solution.insert(solution.begin() + insertIndex, insertValue);
	return calculateMakespan(pI, solution);
}