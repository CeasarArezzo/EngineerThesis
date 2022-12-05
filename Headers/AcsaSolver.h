#ifndef ACSA_SOLVER_H
#define ACSA_SOLVER_H
#include "SaSolver.h"

class AcsaSolver : SaSolver
{
	public:
		vector<size_t> solve(ProblemInstance*);
		void setSolvingParams(double T0, double Tend, size_t iters, size_t coolingIters);
		double reduceTemperature(double temperature);
		
	private:
		double paramT0 = 100;
		double paramTend = 0;
		size_t paramIters = 100;
		size_t paramCoolingIters = 10;
};

#endif