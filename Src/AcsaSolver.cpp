#include "AcsaSolver.h"

vector<size_t> AcsaSolver::solve(ProblemInstance*)
{

}

double AcsaSolver::reduceTemperature(double temperature)
{

}

void AcsaSolver::setSolvingParams(double T0, double Tend, size_t iters, size_t coolingIters)
{
	paramT0 = T0;
	paramTend = Tend;
	paramIters = iters;
	paramCoolingIters = coolingIters;
}
