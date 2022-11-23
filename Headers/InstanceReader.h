#ifndef INSTANCE_READER_H
#define INSTANCE_READER_H
#include <vector>
#include <string>
#include "ProblemInstance.h"

using std::vector;

const size_t INSTANCES_PER_FILE = 10;

vector<ProblemInstance> readProblemInstance(size_t noOfJobs, size_t noOfMachines);

#endif