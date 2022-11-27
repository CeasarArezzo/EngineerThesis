#ifndef NEH_SOLVER_H
#define NEH_SOLVER_H
#include "ProblemSolver.h"
#include <vector>
using std::vector;

class NehSolver:ProblemSolver
{
	public:
		vector<size_t> solve(ProblemInstance* pI);
};

#endif