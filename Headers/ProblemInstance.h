#ifndef PROBLEM_INSTANCE_H
#define PROBLEM_INSTANCE_H
#include <vector>
#include <string>

using std::vector;

class ProblemInstance
{
	public:
		size_t noOfJobs;
		size_t noOfMachines;
		size_t initSeed;
		size_t upperB;
		size_t lowerB;
		vector<vector<size_t>> procTime;
		ProblemInstance(size_t noOfJobs, size_t noOfMachines, size_t initSeed,
			size_t upperB, size_t lowerB, vector<vector<size_t>> procTime);
		ProblemInstance();
		std::string toString();
		void print();
};

#endif