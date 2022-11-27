#ifndef PROBLEM_SOLVER_H
#define PROBLEM_SOLVER_H
#include "ProblemInstance.h"
#include "ProblemSolution.h"

class ProblemSolver
{
	virtual vector<size_t> solve(ProblemInstance*) = 0;
};

#endif