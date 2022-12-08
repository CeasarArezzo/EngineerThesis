#include "AcsaSolver.h"
#include "util.h"
#include <iostream>
#include <algorithm>
#include <cmath>

vector<size_t> AcsaSolver::solve(ProblemInstance* pI)
{
	vector<size_t> currSol = getInitialSolution(pI->noOfJobs, this->paramSolutiontype, pI);
	vector<size_t> bestKnownSol(currSol);
	size_t bestKnownMakespan = calculateMakespan(pI, bestKnownSol);
	size_t currMakespan = bestKnownMakespan;
	double temperature = this->paramTmin;
	size_t totalCoolingIters = 0;
	size_t coolingItersLimit = this->paramCoolingIters;
	size_t rI = 0;
	size_t stayTime = 0;
	long double tempMin = (long double) this->paramTmin;
	long double coolingRate = this->paramCoolingRate;

	while (totalCoolingIters < coolingItersLimit)
	{
		size_t bestSpanAtStart = bestKnownMakespan;
		size_t currSpanAtStart = currMakespan;

		for (size_t iter = 0; iter < this->paramIters; iter++)
		{
			vector<size_t> newSol = getRandNeigh(currSol, this->paramNeighType);
			size_t newMakespan = calculateMakespan(pI, newSol);
			if (calculateAcceptance(newMakespan, currMakespan, temperature))
			{
				currSol = newSol;
				currMakespan = newMakespan;
				if (currMakespan < bestKnownMakespan)
				{
					bestKnownSol = currSol;
					bestKnownMakespan = currMakespan;
				}
			}
		}
		//printVect(currSol);
		if (currMakespan < currSpanAtStart)
		{
			rI = 0;
			stayTime = 0;
		}
		else if (currMakespan > currSpanAtStart)
		{
			rI++;
			stayTime = 0;
		}
		else if (currMakespan == currSpanAtStart)
		{
			stayTime++;
			if (stayTime >= 3)
			{
				rI++;
				stayTime = 0;
			}
		}

		if (bestSpanAtStart < bestKnownMakespan)
		{
			totalCoolingIters++;
		}
		else if (bestSpanAtStart == bestKnownMakespan)
		{
			totalCoolingIters++;
		}
		else
		{
			totalCoolingIters = 0;
		}
		temperature = tempMin + coolingRate * exp(std::max(1 + rI - 0, (size_t)1));
		//if (totalCoolingIters % 200 == 0)
			//std::cout << "acsaLoop:id" << " " << rI << " " << currMakespan << " " << bestKnownMakespan << " " << totalCoolingIters << "\n";
	}
	return bestKnownSol;
}

void AcsaSolver::setSolvingParams(initSolutionType solType, neighType thisNeigh, 
	double Tmin, size_t iters, size_t coolingIters, double coolingRate)
{
	paramSolutiontype = solType;
	paramNeighType = thisNeigh;
	paramTmin = Tmin;
	paramCoolingRate = coolingRate;
	paramIters = iters;
	paramCoolingIters = coolingIters;
}
