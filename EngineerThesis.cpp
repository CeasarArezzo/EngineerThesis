#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ProblemInstance.h"
#include "InstanceReader.h"
#include "NehSolver.h"
#include "NehXSolver.h"
#include "SaSolver.h"
#include "util.h"
#include "Tester.h"


int main()
{
    setup();
    testMakespanCalculation();
    vector<ProblemInstance> vect;
    vect = readProblemInstance(20, 5);
    //NehXSolver().solve(&vect[0]);
    SaSolver sa;
    sa.setSolvingParams(initSolutionType::RAND, neighType::SWAP, coolingType::GEOMETRICAL, 150, 1.5, 300, 0.96);
    for (size_t i = 0; i < 20; i++)
    {
        vector<size_t> solution = sa.solve(&vect[0]);
        printVect(solution);
        std::cout << calculateMakespan(&vect[0], solution) << " " << vect[0].upperB << "\n\n";
    }
    
    /*size_t a = 1700, b = 1900;
    double temperature = 20;
    long double prob = exp((long double)(b - a) / temperature);
    prob = (long double)1 / prob;
    std::cout << prob << "\n";*/
    //printVect(getInitialSolution(5, initSolutionType::DEFAULT));
    //printVect(getInitialSolution(5, initSolutionType::RAND));
    //printVect(getInitialSolution(5, initSolutionType::RAND));
}