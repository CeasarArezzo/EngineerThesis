#ifndef PROBLEM_SOLUTION_H
#define PROBLEM_SOLUTION_H
#include <vector>
#include "ProblemInstance.h"

using std::vector;

size_t calculateMakespan(ProblemInstance* pI, vector<size_t> solution);
size_t calculateMakespan2(ProblemInstance* pI, vector<size_t> solution);
vector<vector<size_t>> getPartMakespanVector(ProblemInstance* pI, vector<size_t> solution);

#endif