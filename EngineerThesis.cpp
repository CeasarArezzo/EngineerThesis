// EngineerThesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ProblemInstance.h"
#include "InstanceReader.h"
#include "ProblemSolution.h"

int main()
{
    vector<ProblemInstance> vect;
    vect = readProblemInstance(5, 3);
    vector<size_t> solution = { 2, 1, 4, 3, 0 };
    std::cout << calculateMakespan(&vect.at(0), solution) << "\n";
}