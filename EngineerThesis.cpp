// EngineerThesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ProblemInstance.h"
#include "InstanceReader.h"

int main()
{
    vector<ProblemInstance> vect;

    vect = readProblemInstance(20, 5);
    vect[0].print();


    //ProblemInstance pI = ProblemInstance(1, 1, 1, 1, 1, vect);
    //pI.procTime.push_back(v1);
}