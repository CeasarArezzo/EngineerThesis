#ifndef EXPERIMENTS_H
#define EXPERIMENTS_H
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include "InstanceReader.h"
#include "util.h"
#include "ProblemSolver.h"

using std::vector;
using std::pair;

const size_t instancesNumber = 12;
const size_t instancesPerFile = 10;
const size_t TUNING_NEHX_REPEATS = 3;
const size_t TUNING_SA_CR_REPEATS = 2;
const size_t TUNING_SA_T0_REPEATS = 2;
const size_t TUNING_ACSA_REPEATS = 3;
const size_t COMP_MAKESPAN_REPEATS = 10;

void runTuningNehX();
void runTuningSAGeoCoolingRate();
void runTuningSALinCoolingRate();
void runTuningSAGeoT0();
void runTuningSALinT0();
void runTuningSALogT0();
void runTuningSAGeoTk();
void runTuningSALinTk();
void runTuningSALogTk();
void runTuningAcsaTmin();
void runTuningAcsaCoolingRate();
void compareSaCoolingTypes();
void compareSaNeighTypes();
void compareSaSolTypes();
void compareAcsaNeighTypes();
void compareAcsaStartSolutionTypes();
void compareMakespanCalculation();
void compareAllAlgorithmsResults();
void compareAllAlgorithmsTime();
void measureRuntime();

#endif