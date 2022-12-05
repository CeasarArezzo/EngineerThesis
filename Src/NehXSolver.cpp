#include "NehXSolver.h"
#include <iostream>
#include "util.h"

vector<size_t> NehXSolver::solve(ProblemInstance* pI)
{
	vector<size_t> solution = NehSolver().solve(pI);
	printVect(solution);
	std::cout << calculateMakespan(pI, solution) << "\n";
	size_t attemptCounter = 0;
	size_t maxAttempts = this->attemptsBeforeResign;
	size_t lastInsertedTask = getShortestProcTimeTask(pI, solution);
	for (size_t i = 0; i < 50; i++)
	{
		size_t taskToMove = getLongestOpOnCritPath(pI, solution, lastInsertedTask);
		//taskToMove = randomUint(pI->noOfJobs);
		std::cout << taskToMove << "\n";
		size_t nextTask = solution.at(taskToMove);
		solution.erase(solution.begin() + taskToMove);
		size_t currBest = 0;
		size_t currBestValue = UINT_MAX;
		for (size_t pos = 0; pos <= solution.size(); pos++)
		{
			size_t currValue = getMakespanWithInsert(pI, solution, pos, nextTask);
			if (currValue < currBestValue)
			{
				currBestValue = currValue;
				currBest = pos;
			}
		}
		solution.insert(solution.begin() + currBest, nextTask);
		//printVect(solution);
		std::cout << calculateMakespan(pI, solution) << "\n";
		lastInsertedTask = nextTask;
	}
	/*while (attemptCounter < maxAttempts)
	{
		size_t taskToMove = getLongestOpOnCritPath(pI, solution, lastInsertedTask);
	}*/
	return solution;
}

size_t NehXSolver::getLongestOpOnCritPath(ProblemInstance* pI, vector<size_t> solution, size_t lastInsertedTask)
{
	vector<vector<size_t>> partMakespan = getPartMakespanVector(pI, solution);
	size_t job = solution.size() - 1;
	size_t mchn = pI->noOfMachines - 1;
	size_t longestOp = 0;
	size_t longestOwner = 0;
	/*for (size_t job = 0; job < solution.size(); job++)
	{
		for (size_t mchn = 0; mchn < pI->noOfMachines; mchn++)
		{
			std::cout << partMakespan[solution.at(job)][mchn] << " ";
		}
		std::cout << "\n";
	}*/
	for (size_t iter = 0; iter < solution.size() + pI->noOfMachines - 1; iter++)
	{
		//std::cout << pI->procTime[solution.at(job)][mchn] << " " << partMakespan[solution.at(job)][mchn] << "\n";
		if (pI->procTime[solution.at(job)][mchn] > longestOp)
		{
			if (solution.at(job) != lastInsertedTask)
			{
				longestOp = pI->procTime[solution.at(job)][mchn];
				longestOwner = job;
			}
		}

		if (job == 0)
		{
			mchn--;
		}
		else if (mchn == 0)
		{
			job--;
		}
		else
		{
			if (partMakespan[solution.at(job - 1)][mchn] > partMakespan[solution.at(job)][mchn - 1])
			{
				job--;
			}
			else
			{
				mchn--;
			}
		}
	}
	/*std::cout << "owner " << longestOwner << "\n";
	std::cout << "length " << longestOp << "\n";*/
	return longestOwner;
}

size_t NehXSolver::getShortestProcTimeTask(ProblemInstance* pI, vector<size_t> solution)
{
	size_t currTaskId = 0;
	size_t currTaskLength = UINT_MAX;
	for (size_t job = 0; job < pI->noOfJobs; job++)
	{
		size_t sumOfLengths = 0;
		for (size_t mchn = 0; mchn < pI->noOfMachines; mchn++)
		{
			sumOfLengths += pI->procTime[solution.at(job)][mchn];
		}
		if (sumOfLengths < currTaskLength)
		{
			currTaskId = solution.at(job);
			currTaskLength = sumOfLengths;
		}
	}
	return currTaskId;
}

void NehXSolver::setParams(size_t attempts)
{
	this->attemptsBeforeResign = attempts;
}