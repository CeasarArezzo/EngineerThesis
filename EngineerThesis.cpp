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
#include "AcsaSolver.h"

int main()
{
    setup();
    testMakespanCalculation();
    vector<ProblemInstance> vect;
    vect = readProblemInstance(20, 10);
    for (size_t i = 0; i < 10; i++)
    {
        ProblemInstance* pI = &vect[i];
        NehXSolver nehx;
        vector<size_t> solution = nehx.solve(pI);
        vector<size_t> solution2 = NehSolver().solve(pI);
        std::cout << calculateMakespan(pI, solution) << " " << pI->upperB << "\n";
        std::cout << calculateMakespan(pI, solution2) << " " << pI->upperB << "\n";
    }
    /*AcsaSolver asca;
    SaSolver sa;
    asca.setSolvingParams(initSolutionType::RAND, neighType::INSERT, 1, 20 * 20, 20 * 20, 1.0);
    sa.setSolvingParams(initSolutionType::RAND, neighType::INSERT, coolingType::GEOMETRICAL, 150, 1, 500, 0.95);
    vector<size_t> solution = asca.solve(pI);
    vector<size_t> saSolution = sa.solve(pI);
    printVect(solution);
    std::cout << calculateMakespan(pI, solution) << " " << pI->upperB << "\n";
    std::cout << calculateMakespan(pI, saSolution) << " " << pI->upperB << "\n";*/
    
    /*size_t a = 1700, b = 1900;
    double temperature = 20;
    long double prob = exp((long double)(b - a) / temperature);
    prob = (long double)1 / prob;
    std::cout << prob << "\n";*/
    //printVect(getInitialSolution(5, initSolutionType::DEFAULT));
    //printVect(getInitialSolution(5, initSolutionType::RAND));
    //printVect(getInitialSolution(5, initSolutionType::RAND));
}