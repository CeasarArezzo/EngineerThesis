#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <utility>
using std::vector;
using std::make_pair;
using std::pair;

void setup();
void printVect(vector<size_t>);
size_t randomUint(size_t limit);
double randomDouble(double lowerB, double upperB);
double randomDouble(double upperB);
vector<pair<size_t, size_t>> getAllInstanceSizes();
vector<pair<size_t, size_t>> getAllInstanceSizesSkip1();
vector<pair<size_t, size_t>> getAllInstanceSizesSkip3();
vector<pair<size_t, size_t>> getAllInstanceSizesSkip4();
vector<pair<size_t, size_t>> getAllInstanceSizesMakespan();

#endif