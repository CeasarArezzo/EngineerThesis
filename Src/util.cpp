#include <iostream>
#include <random>
#include "util.h"

void printVect(vector<size_t> toPrint)
{
	std::cout << "Vector size: " << toPrint.size() << "\n";
	for (size_t iter = 0; iter < toPrint.size(); iter++)
	{
		std::cout << toPrint.at(iter) << " ";
	}
	std::cout << "\n";
}

size_t randomUint(size_t limit)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, limit - 1);

	return dist(rng);
}

void setup()
{
	std::srand(unsigned(std::time(0)));
}

double randomDouble(double lowerB, double upperB)
{
	std::uniform_real_distribution<double> unif(lowerB, upperB);
	std::default_random_engine re;
	return unif(re);
}

double randomDouble(double upperB)
{
	return randomDouble(0, upperB);
}

vector<pair<size_t, size_t>> getAllInstanceSizes()
{
	vector<pair<size_t, size_t>> instanceSizes;
	instanceSizes.push_back(make_pair(20, 5));
	instanceSizes.push_back(make_pair(20, 10));
	instanceSizes.push_back(make_pair(20, 20));
	instanceSizes.push_back(make_pair(50, 5));
	instanceSizes.push_back(make_pair(50, 10));
	instanceSizes.push_back(make_pair(50, 20));
	instanceSizes.push_back(make_pair(100, 5));
	instanceSizes.push_back(make_pair(100, 10));
	instanceSizes.push_back(make_pair(100, 20));
	instanceSizes.push_back(make_pair(200, 10));
	instanceSizes.push_back(make_pair(200, 20));
	instanceSizes.push_back(make_pair(500, 20));
	return instanceSizes;
}

vector<pair<size_t, size_t>> getAllInstanceSizesSkip1()
{
	vector<pair<size_t, size_t>> instanceSizes;
	instanceSizes.push_back(make_pair(20, 5));
	instanceSizes.push_back(make_pair(20, 10));
	instanceSizes.push_back(make_pair(20, 20));
	instanceSizes.push_back(make_pair(50, 5));
	instanceSizes.push_back(make_pair(50, 10));
	instanceSizes.push_back(make_pair(50, 20));
	instanceSizes.push_back(make_pair(100, 5));
	instanceSizes.push_back(make_pair(100, 10));
	instanceSizes.push_back(make_pair(100, 20));
	instanceSizes.push_back(make_pair(200, 10));
	instanceSizes.push_back(make_pair(200, 20));
	return instanceSizes;
}

vector<pair<size_t, size_t>> getAllInstanceSizesSkip3()
{
	vector<pair<size_t, size_t>> instanceSizes;
	instanceSizes.push_back(make_pair(20, 5));
	instanceSizes.push_back(make_pair(20, 10));
	instanceSizes.push_back(make_pair(20, 20));
	instanceSizes.push_back(make_pair(50, 5));
	instanceSizes.push_back(make_pair(50, 10));
	instanceSizes.push_back(make_pair(50, 20));
	instanceSizes.push_back(make_pair(100, 5));
	instanceSizes.push_back(make_pair(100, 10));
	instanceSizes.push_back(make_pair(100, 20));
	return instanceSizes;
}

vector<pair<size_t, size_t>> getAllInstanceSizesSkip4()
{
	vector<pair<size_t, size_t>> instanceSizes;
	instanceSizes.push_back(make_pair(20, 5));
	instanceSizes.push_back(make_pair(20, 10));
	instanceSizes.push_back(make_pair(20, 20));
	instanceSizes.push_back(make_pair(50, 5));
	instanceSizes.push_back(make_pair(50, 10));
	instanceSizes.push_back(make_pair(50, 20));
	instanceSizes.push_back(make_pair(100, 5));
	instanceSizes.push_back(make_pair(100, 10));
	return instanceSizes;
}

vector<pair<size_t, size_t>> getAllInstanceSizesMakespan()
{
	vector<pair<size_t, size_t>> instanceSizes;
	instanceSizes.push_back(make_pair(20, 5));
	instanceSizes.push_back(make_pair(20, 10));
	instanceSizes.push_back(make_pair(20, 20));
	instanceSizes.push_back(make_pair(50, 5));
	instanceSizes.push_back(make_pair(50, 10));
	instanceSizes.push_back(make_pair(100, 5));
	instanceSizes.push_back(make_pair(100, 10));
	return instanceSizes;
}