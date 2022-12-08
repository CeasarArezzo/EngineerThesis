#ifndef NEH_SOLVER_H
#define NEH_SOLVER_H
#include "ProblemSolver.h"
#include <vector>
using std::vector;

class NehSolver : public ProblemSolver
{
	public:
		vector<size_t> solve(ProblemInstance* pI);
		size_t getMakespanWithInsert(ProblemInstance* pI, vector<size_t> solution, size_t insertIndex, size_t insertValue);
};

#endif