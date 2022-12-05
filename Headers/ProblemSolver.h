#ifndef PROBLEM_SOLVER_H
#define PROBLEM_SOLVER_H
#include "ProblemInstance.h"
#include "ProblemSolution.h"

enum class initSolutionType
{
	RAND,
	DEFAULT,
	NEH
};

enum class neighType
{
	SWAP,
	NEIGH_SWAP,
	INVERT,
	INSERT
};

enum class coolingType
{
	LINEAR,
	GEOMETRICAL,
	LOGARITHMIC,
	ADAPTIVE
};

vector<size_t> getInitialSolution(size_t length, initSolutionType, ProblemInstance* pI);
vector<size_t> getRandNeigh(vector<size_t>, neighType);
template <typename t> void move(std::vector<t>& v, size_t oldIndex, size_t newIndex);
vector <size_t> vectorInvert(vector<size_t> sol, size_t rand1, size_t rand2);

class ProblemSolver
{
	virtual vector<size_t> solve(ProblemInstance*) = 0;
};

#endif