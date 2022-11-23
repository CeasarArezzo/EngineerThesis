#include <fstream>
#include <iostream>
#include "InstanceReader.h"

vector<ProblemInstance> readProblemInstance(size_t noOfJobs, size_t noOfMachines)
{
	vector<ProblemInstance> vect;
	std::ifstream reader("Data/tai" + std::to_string(noOfJobs) + "_" +
		std::to_string(noOfMachines) + ".txt");
	std::string tmp;
	size_t readVal = 0;
	for (size_t i = 0; i < INSTANCES_PER_FILE; i++)
	{
		ProblemInstance pI;
		//skip first info line
		std::getline(reader, tmp);
		reader >> readVal;
		pI.noOfJobs = readVal;
		reader >> readVal;
		pI.noOfMachines = readVal;
		reader >> readVal;
		pI.initSeed = readVal;
		reader >> readVal;
		pI.upperB = readVal;
		reader >> readVal;
		pI.lowerB = readVal;

		//skip second line:
		std::getline(reader, tmp);
		std::getline(reader, tmp);

		vector<vector<size_t>> procTimes(noOfJobs, vector<size_t>(noOfMachines, 0));
		for (size_t mchn = 0; mchn < noOfMachines; mchn++)
		{
			for (size_t job = 0; job < noOfJobs; job++)
			{
				reader >> procTimes[job][mchn];
			}
		}
		std::getline(reader, tmp);
		pI.procTime = procTimes;
		vect.push_back(pI);
	}
	
	return vect;
}
