// EngineerThesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ProblemInstance.h"
#include "InstanceReader.h"
#include "ProblemSolution.h"
#include "NehSolver.h"

int main()
{
    vector<ProblemInstance> vect;
    vect = readProblemInstance(20, 5);
    NehSolver neh;
    vector<size_t> sol = neh.solve(&vect[0]);
    //std::cout << calculateMakespan(&vect[0], sol) << "\n";;
}