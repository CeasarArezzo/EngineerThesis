#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ProblemInstance.h"
#include "InstanceReader.h"
#include "NehSolver.h"
#include "SaSolver.h"
#include "util.h"
#include "Tester.h"


int main()
{
    setup();
    //vector<ProblemInstance> vect;
    //vect = readProblemInstance(20, 5);
    //NehSolver neh;
    //vector<size_t> sol = neh.solve(&vect[0]);
    //std::cout << calculateMakespan(&vect[0], sol) << "\n";;
    //SaSolver sa;
    //sa.setSolvingParams(initSolutionType::RAND, neighType::SWAP, coolingType::GEOMETRICAL , 100, 1, 50, 0.5);
    //vector<size_t> sol2 = sa.solve(&vect[0]);
    //std::cout << calculateMakespan(&vect[0], sol2) << "\n";
    testMakespanCalculation();
    /*size_t a = 1700, b = 1900;
    double temperature = 20;
    long double prob = exp((long double)(b - a) / temperature);
    prob = (long double)1 / prob;
    std::cout << prob << "\n";*/
    //printVect(getInitialSolution(5, initSolutionType::DEFAULT));
    //printVect(getInitialSolution(5, initSolutionType::RAND));
    //printVect(getInitialSolution(5, initSolutionType::RAND));
    //sa.solve(&vect[0]);
}