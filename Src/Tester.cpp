#include <numeric>
#include "Tester.h"
#include "InstanceReader.h"
#include "ProblemInstance.h"
#include "ProblemSolver.h"
#include <iostream>
using std::vector;

void testMakespanCalculation()
{
	size_t jobNumber = 20;
	size_t mchnNumber = 5;
	vector<ProblemInstance> instances = readProblemInstance(jobNumber, mchnNumber);
	vector<size_t> solution(jobNumber);
	std::iota(solution.begin(), solution.end(), 0);
	for (size_t i = 0; i < 10; i++)
	{
		ProblemInstance pI = instances.at(i);
		size_t res1 = calculateMakespan(&pI, solution);
		size_t res2 = calculateMakespan2(&pI, solution);
		//std::cout << res1 << " " << res2 << "\n";
		assert(res1 == res2);
	}
}