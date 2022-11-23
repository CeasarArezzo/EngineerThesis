#include "ProblemInstance.h"
#include <iostream>

using std::to_string;

ProblemInstance::ProblemInstance(size_t noOfJobs, size_t noOfMachines, size_t initSeed, 
	size_t upperB, size_t lowerB, vector<vector<size_t>> procTime)
{
	this->noOfJobs = noOfJobs;
	this->noOfMachines = noOfMachines;
	this->initSeed = initSeed;
	this->upperB = upperB;
	this->lowerB = lowerB;
	this->procTime = vector<vector<size_t>>(procTime);
	std::cout << procTime.size() << "\n";
}

ProblemInstance::ProblemInstance()
{
	this->noOfJobs = 0;
	this->noOfMachines = 0;
	this->initSeed = 0;
	this->upperB = 0;
	this->lowerB = 0;
	this->procTime = vector<vector<size_t>>();
}

std::string ProblemInstance::toString()
{
	std::string output = "Instance Info\nNoOfJobs: " + to_string(noOfJobs) + ", noOfMachines: " + to_string(noOfMachines) + ", initSeed: " + to_string(initSeed) + ", upperB: " + to_string(upperB) + ", lowerB: " + to_string(lowerB);
	return output;
}

void ProblemInstance::print()
{
	std::cout << toString() << "\n";
	for (size_t mchn = 0; mchn < noOfMachines; mchn++)
	{
		for (size_t job = 0; job < noOfJobs; job++)
		{
			std::cout << procTime[job][mchn] << " ";
		}
		std::cout << "\n";
	}
}
