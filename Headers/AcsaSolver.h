#ifndef ACSA_SOLVER_H
#define ACSA_SOLVER_H
#include "SaSolver.h"

class AcsaSolver : SaSolver
{
	public:
		vector<size_t> solve(ProblemInstance*);
		void setSolvingParams(initSolutionType, neighType, double Tmin, size_t iters, size_t coolingIters, double coolingRate);
		
	private:
		initSolutionType paramSolutiontype = initSolutionType::DEFAULT;
		neighType paramNeighType = neighType::SWAP;
		double paramTmin = 1;
		size_t paramIters = 100;
		size_t paramCoolingIters = 10;
		double paramCoolingRate = 1;
};

#endif