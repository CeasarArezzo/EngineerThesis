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
			vector<size_t> solution, size_t lastInsertedTask);
		void setParams(size_t attempts);
		size_t attemptsBeforeResign = 10;
};

#endif