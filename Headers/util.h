#ifndef UTIL_H
#define UTIL_H
#include <vector>
using std::vector;

void setup();
void printVect(vector<size_t>);
size_t randomUint(size_t limit);
double randomDouble(double lowerB, double upperB);
double randomDouble(double upperB);

#endif