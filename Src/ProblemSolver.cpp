#include <numeric>
#include <algorithm>
#include <stdexcept>
#include "ProblemSolver.h"
#include "util.h"
#include <iostream>
#include "NehSolver.h"

vector<size_t> getInitialSolution(size_t length, initSolutionType solType, ProblemInstance* pI)
{
	vector<size_t> retVal(length);
	switch (solType)
	{
	case initSolutionType::RAND:
	{
		std::iota(retVal.begin(), retVal.end(), 0);
		std::random_shuffle(retVal.begin(), retVal.end());
		break;
	}
	case initSolutionType::DEFAULT:
	{
		std::iota(retVal.begin(), retVal.end(), 0);
		break;
	}
	case initSolutionType::NEH:
	{
		retVal = NehSolver().solve(pI);
		break;
	}
	}
	return retVal;
}

vector<size_t> getRandNeigh(vector<size_t> currSol, neighType neigh)
{
	switch (neigh)
	{
	case neighType::INSERT:
	{
		size_t rand1 = randomUint(currSol.size());
		size_t rand2 = randomUint(currSol.size() - 1);
		if (rand2 >= rand1)
		{
			rand2++;
		}
		if (rand1 == rand2)
		{
			throw std::runtime_error("same random numbers in INVERT neighbourhood");
		}
		move(currSol, rand1, rand2);
		break;
	}
	case neighType::INVERT:
	{
		size_t rand1 = randomUint(currSol.size());
		size_t rand2 = randomUint(currSol.size() - 1);
		if (rand2 >= rand1)
		{
			rand2++;
		}
		if (rand1 == rand2)
		{
			throw std::runtime_error("same random numbers in INVERT neighbourhood");
		}
		currSol = vectorInvert(currSol, rand1, rand2);
		break;
	}
	case neighType::SWAP:
	{
		size_t rand1 = randomUint(currSol.size());
		size_t rand2 = randomUint(currSol.size() - 1);
		if (rand2 >= rand1)
		{
			rand2++;
		}
		if (rand1 == rand2)
		{
			throw std::runtime_error("same random numbers in INVERT neighbourhood");
		}
		std::swap(currSol[rand1], currSol[rand2]);
		break;
	}
	case neighType::NEIGH_SWAP:
	{
		size_t rand = randomUint(currSol.size() - 1);
		std::swap(currSol[rand], currSol[rand + 1]);
		break;
	}
	}
	return currSol;
}

template <typename t> void move(std::vector<t>& v, size_t oldIndex, size_t newIndex)
{
	if (oldIndex > newIndex)
		std::rotate(v.rend() - oldIndex - 1, v.rend() - oldIndex, v.rend() - newIndex);
	else
		std::rotate(v.begin() + oldIndex, v.begin() + oldIndex + 1, v.begin() + newIndex + 1);
}

vector <size_t> vectorInvert(vector<size_t> sol, size_t rand1, size_t rand2)
{
	if (rand1 > rand2)
	{
		std::reverse(sol.begin() + rand2, sol.begin() + rand1 + 1);
	}
	else //if (rand2 > rand1)
	{
		std::reverse(sol.begin() + rand1, sol.begin() + rand2 + 1);
	}
	return sol;
}