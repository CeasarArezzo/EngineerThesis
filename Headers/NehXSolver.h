#ifndef NEHX_SOLVER_H
#define NEHX_SOLVER_H
#include "NehSolver.h"
#include <vector>
using std::vector;

class NehXSolver:NehSolver
{
	public:
		vector<size_t> solve(ProblemInstance* pI);
		size_t getShortestProcTimeTask(ProblemInstance* pI, vector <size_t> solution);
		size_t getLongestOpOnCritPath(ProblemInstance* pI, 
			vector<size_t> solution, size_t ignoredTask);
		size_t getBiggestSumOnCritPath(ProblemInstance* pI, vector<size_t> solution, size_t ignoredTask);
		size_t getBiggestCountOnCritPath(ProblemInstance* pI, vector<size_t> solution, size_t ignoredTask);
		size_t getNextTaskToMove(ProblemInstance* pI, vector<size_t> solution, size_t ignoredTask);
};

#endif