#include <cmath>
#include "SaSolver.h"
#include "util.h"

vector<size_t> SaSolver::solve(ProblemInstance* pI)
{
	vector<size_t> currSol = getInitialSolution(pI->noOfJobs, this->paramSolutiontype, pI);
	vector<size_t> bestSol(currSol);
	size_t currMakespan = calculateMakespan(pI, bestSol);
	size_t bestMakespan = currMakespan;
	double temperature = this->paramT0;

	while (temperature >= this->paramTend)
	{
		for (size_t iter = 0; iter < this->paramIters; iter++)
		{
			vector<size_t> newSol = getRandNeigh(currSol, this->paramNeighType);
			size_t newMakespan = calculateMakespan(pI, newSol);
			if (calculateAcceptance(newMakespan, currMakespan, temperature))
			{
				currSol = newSol;
				currMakespan = newMakespan;
				if (currMakespan < bestMakespan)
				{
					bestSol = currSol;
					bestMakespan = currMakespan;
				}
			}
		}
		this->temperatureIterations++;
		temperature = reduceTemperature(temperature, coolingRate, this->paramCooling);
	}

	return bestSol;
}

double SaSolver::reduceTemperature(double temperature, double coolingRate, coolingType selectedCooling)
{
	switch (selectedCooling)
	{
	case coolingType::LINEAR:
	{
		temperature -= coolingRate;
		break;
	}
	case coolingType::GEOMETRICAL:
	{
		temperature *= coolingRate;
		break;
	}
	case coolingType::LOGARITHMIC:
	{
		temperature = temperature / (log(1 + this->temperatureIterations));
		break;
	}
	case coolingType::ADAPTIVE:
	{
		//TODO: NOT IMPLEMENTED, USING LINEAR INSTEAD
		temperature -= coolingRate;
		break;
	}
	}
	return temperature;
}

bool SaSolver::calculateAcceptance(size_t neighMakespan, size_t currMakespan, double temperature)
{
	double randN = randomDouble(1.0);
	if (neighMakespan > currMakespan)
	{
		long double probabilityOfAccept = exp((long double)(neighMakespan - currMakespan) / temperature);
		probabilityOfAccept = (long double) 1 / probabilityOfAccept;
		return probabilityOfAccept > randN;
	}
	return true;
}

void SaSolver::setSolvingParams(initSolutionType initSol, neighType neigh, coolingType selCooling, 
	double T0, double Tend, size_t iters, double coolingRate)
{
	this->paramSolutiontype = initSol;
	this->paramNeighType = neigh;
	this->paramCooling = selCooling;
	this->paramT0 = T0;
	this->paramTend = Tend;
	this->paramIters = iters;
	this->coolingRate = coolingRate;
}