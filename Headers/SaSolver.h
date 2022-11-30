#ifndef SA_SOLVER_H
#define SA_SOLVER_H
#include "ProblemSolver.h"

class SaSolver : public ProblemSolver
{
	public:
		void setSolvingParams(initSolutionType initSol, neighType, coolingType, double T0, double Tend, size_t iters, double coolingRate);
		vector<size_t> solve(ProblemInstance*);
		bool calculateAcceptance(size_t neighMakespan, size_t currMakespan, double temperature);
		double reduceTemperature(double temperature, double coolingRate, coolingType);

	private:
		initSolutionType paramSolutiontype = initSolutionType::DEFAULT;
		neighType paramNeighType = neighType::SWAP;
		coolingType paramCooling = coolingType::LINEAR;
		double paramT0 = 100;
		double paramTend = 0;
		size_t paramIters = 100;
		double coolingRate = 0.5;
		size_t temperatureIterations = 0;
};

#endif