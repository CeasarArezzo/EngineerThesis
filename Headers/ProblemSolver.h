#ifndef PROBLEM_SOLVER_H
#define PROBLEM_SOLVER_H
#include "ProblemInstance.h"
#include "ProblemSolution.h"

class ProblemSolver
{
	virtual ProblemSolution solve(ProblemInstance) = 0;
};

#endif