#include "Experiments.h"
#include "NehXSolver.h"
#include "ProblemSolver.h"
#include "SaSolver.h"
#include "AcsaSolver.h"

void runTuningNehX()
{
	std::cout << "\t\tRUNNING NEH+ TUNNING\n";

	std::ofstream file;
	file.open("tunningNehX-CompToNeh.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip1();
	vector<NehXSolver> solvers;
	for (size_t i = 0; i < 6; i++)
	{
		solvers.push_back(NehXSolver());
	}
	solvers[0].setParams(10);
	solvers[1].setParams(25);
	solvers[2].setParams(50);
	solvers[5].setParams(0);
	file << "it - jobs - mchns - 10 - 50 - n - 2n - 0\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		solvers[3].setParams(instanceVect[0].noOfJobs);
		solvers[4].setParams(instanceVect[0].noOfJobs * 2);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < TUNING_NEHX_REPEATS; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)TUNING_NEHX_REPEATS << " ";
		}
		file << "\n";
		file.flush();
	}
	file.flush();
	file.close();
}

void runTuningSAGeoCoolingRate()
{
	std::cout << "\t\tRUNNING SA GEOMETRICAL COOLING RATE TUNNING\n";

	std::ofstream file;
	file.open("tunningSAGeoCR-2.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizes();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 5; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "jobs - mchns - 0.98 - 0.95 - 0.9 - 0.8 - 0.75\n";
	for (size_t problemSize = 6; problemSize < instancesNumber; problemSize++)
	{
		file << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 100, 1, n * n / 2, 0.98);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 100, 1, n * n / 2, 0.95);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 100, 1, n * n / 2, 0.90);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 100, 1, n * n / 2, 0.80);
		solvers[4].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 100, 1, n * n / 2, 0.75);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < TUNING_SA_CR_REPEATS; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)TUNING_SA_CR_REPEATS << " ";
		}
		file << "\n";
		file.flush();
	}
	file.flush();
	file.close();
}

void runTuningSALinCoolingRate()
{
	std::cout << "\t\tRUNNING SA LINEAR COOLING RATE TUNNING\n";

	std::ofstream file;
	file.open("tunningSALinCR.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip1();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "jobs - mchns - 0.5 - 1 - 5 - 10\n";
	for (size_t problemSize = 0; problemSize < instancesNumber; problemSize++)
	{
		file << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 100, 1, n * n / 2, 0.5);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 100, 1, n * n / 2, 1);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 100, 1, n * n / 2, 2.5);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 100, 1, n * n / 2, 5);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < TUNING_SA_CR_REPEATS; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)TUNING_SA_CR_REPEATS << " ";
		}
		file << "\n";
		file.flush();
	}
	file.flush();
	file.close();
}

void runTuningSAGeoT0()
{
	std::cout << "\t\tRUNNING SA GEOMETRICAL T0 TUNING\n";

	std::ofstream file;
	file.open("tuningSAGeoT0.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip3();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 5; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - 200 160 130 100 80\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 200, 1, n * n / 2, 0.98);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 160, 1, n * n / 2, 0.98);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 100, 1, n * n / 2, 0.98);
		solvers[4].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 80, 1, n * n / 2, 0.98);
		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			double sumPrd = 0;
			size_t repLimit = TUNING_SA_T0_REPEATS;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void runTuningSALinT0()
{
	std::cout << "\t\tRUNNING SA LINEAR T0 TUNING\n";

	std::ofstream file;
	file.open("tuningSALinT0.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 5; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - 200 160 130 100 80\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 200, 1, n * n / 2, 0.5);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 160, 1, n * n / 2, 0.5);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 130, 1, n * n / 2, 0.5);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 100, 1, n * n / 2, 0.5);
		solvers[4].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 80, 1, n * n / 2, 0.5);
		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			double sumPrd = 0;
			size_t repLimit = TUNING_SA_T0_REPEATS;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void runTuningSALogT0()
{
	std::cout << "\t\tRUNNING SA LOGARITHMIC T0 TUNING\n";

	std::ofstream file;
	file.open("tuningSALogT0.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 5; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - 200 160 130 100 80\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 200, 1, n * n / 2, 1);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 160, 1, n * n / 2, 1);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 130, 1, n * n / 2, 1);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 100, 1, n * n / 2, 1);
		solvers[4].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 80, 1, n * n / 2, 1);
		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			double sumPrd = 0;
			size_t repLimit = TUNING_SA_T0_REPEATS;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void runTuningSAGeoTk()
{
	std::cout << "\t\tRUNNING SA GEOMETRICAL Tk TUNING\n";

	std::ofstream file;
	file.open("tuningSAGeoTk.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - 0.5 1 2.5 5\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 0.5, n * n / 2, 0.98);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 2.5, n * n / 2, 0.98);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 5, n * n / 2, 0.98);
		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			double sumPrd = 0;
			size_t repLimit = TUNING_SA_T0_REPEATS;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void runTuningSALinTk()
{
	std::cout << "\t\tRUNNING SA LINEAR Tk TUNING\n";

	std::ofstream file;
	file.open("tuningSALinTk.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - 0.5 1 2.5 5\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 130, 0.5, n * n / 2, 0.5);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 130, 1, n * n / 2, 0.5);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 130, 2.5, n * n / 2, 0.5);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 130, 5, n * n / 2, 0.5);
		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			double sumPrd = 0;
			size_t repLimit = TUNING_SA_T0_REPEATS;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void runTuningSALogTk()
{
	std::cout << "\t\tRUNNING SA LOGARITHMIC Tk TUNING\n";

	std::ofstream file;
	file.open("tuningSALogTk.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - 0.5 1 2.5 5\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 130, 0.5, n * n / 2, 0.5);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 130, 1, n * n / 2, 0.5);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 130, 2.5, n * n / 2, 0.5);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 130, 5, n * n / 2, 0.5);
		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			double sumPrd = 0;
			size_t repLimit = TUNING_SA_T0_REPEATS;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void runTuningAcsaTmin()
{
	std::cout << "\t\tRUNNING ACSA Tmin TUNNING\n";

	std::ofstream file;
	file.open("tuningAcsaTmin-fixed.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip1();
	vector<AcsaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(AcsaSolver());
	}
	file << "jobs - mchns - 0.5 - 1 - 5 - 10\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 1);
		solvers[1].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 1, n * n / 2, 500, 1);
		solvers[2].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 5, n * n / 2, 500, 1);
		solvers[3].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 10, n * n / 2, 500, 1);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < TUNING_ACSA_REPEATS; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)TUNING_ACSA_REPEATS << " ";
		}
		file << "\n";
		file.flush();
	}
	file.flush();
	file.close();
}

void runTuningAcsaCoolingRate()
{
	std::cout << "\t\tRUNNING ACSA CR TUNING\n";

	std::ofstream file;
	file.open("tuningAcsaCR.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip1();
	vector<AcsaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(AcsaSolver());
	}
	file << "it - jobs - mchns - 0.5 - 1 - 2.5 - 5\n";
	for (size_t problemSize = 0; problemSize < instancesNumber; problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 0.5);
		solvers[1].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 1);
		solvers[2].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 2.5);
		solvers[3].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 5);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < TUNING_ACSA_REPEATS; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)TUNING_ACSA_REPEATS << " ";
		}
		file << "\n";
		file.flush();
	}
	file.flush();
	file.close();
}

void compareMakespanCalculation()
{
	std::cout << "\t\tRUNNING MAKESPAN CALCULATION COMPARISION\n";

	std::ofstream file;
	file.open("compMakespanCalc.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesMakespan();
	file << "id - jobs - mchns - iterative - recursive\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		long double sumIterative = 0;
		long double sumRecursive = 0;
		for (size_t iter = 0; iter < 2; iter++)
		{
			ProblemInstance* pI = &instanceVect[iter];
			vector<size_t> sol = getInitialSolution(pI->noOfJobs, initSolutionType::RAND, pI);
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
			size_t ret1 = calculateMakespan(pI, sol);
			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			sumIterative += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

			std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
			size_t ret2 = calculateMakespan2(pI, sol);
			std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

			sumRecursive += std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count();
		}
		sumIterative /= 2;
		sumRecursive /= 2;
		file << sumIterative  << " " << sumRecursive << "\n";
		file.flush();
	}
	file.close();
}

void compareSaCoolingTypes()
{
	std::cout << "\t\tCOMPARE SA COOLING TYPES\n";

	std::ofstream file;
	file.open("compareSaCooling.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 3; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - GEO - LIN - LOG\n";
	for (size_t problemSize = 0; problemSize < instancesNumber; problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LINEAR, 130, 1, n * n / 2, 0.5);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::LOGARITHMIC, 130, 0.5, n * n / 2, 1);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			size_t repLimit = 2;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void compareSaNeighTypes()
{
	std::cout << "\t\tCOMPARE SA NEIGH TYPES\n";

	std::ofstream file;
	file.open("compareSaNeigh.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - INSERT - INVERT - SWAP - NEIGH SWAP\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[1].setParams(initSolutionType::DEFAULT, neighType::INVERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[2].setParams(initSolutionType::DEFAULT, neighType::SWAP, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[3].setParams(initSolutionType::DEFAULT, neighType::NEIGH_SWAP, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			size_t repLimit = 2;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void compareSaSolTypes()
{
	std::cout << "\t\tCOMPARE SA Sol TYPES\n";

	std::ofstream file;
	file.open("compSaSol.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip4();
	vector<SaSolver> solvers;
	for (size_t i = 0; i < 3; i++)
	{
		solvers.push_back(SaSolver());
	}
	file << "it - jobs - mchns - DEFAULT - RAND - NEH\n";
	for (size_t problemSize = 0; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[1].setParams(initSolutionType::RAND, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);
		solvers[2].setParams(initSolutionType::NEH, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			size_t repLimit = 2;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void compareAcsaNeighTypes()
{
	std::cout << "\t\tCOMPARE ACSA NEIGH TYPES\n";

	std::ofstream file;
	file.open("compareAcsaNeigh2.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip1();
	vector<AcsaSolver> solvers;
	for (size_t i = 0; i < 4; i++)
	{
		solvers.push_back(AcsaSolver());
	}
	file << "it - jobs - mchns - INSERT - INVERT - SWAP - NEIGH SWAP\n";
	for (size_t problemSize = 8; problemSize < instancesNumber; problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 0.5);
		solvers[1].setSolvingParams(initSolutionType::DEFAULT, neighType::INVERT, 0.5, n * n / 2, 500, 0.5);
		solvers[2].setSolvingParams(initSolutionType::DEFAULT, neighType::SWAP, 0.5, n * n / 2, 500, 0.5);
		solvers[3].setSolvingParams(initSolutionType::DEFAULT, neighType::NEIGH_SWAP, 0.5, n, 500, 0.5);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			size_t repLimit = 2;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void compareAcsaStartSolutionTypes()
{
	std::cout << "\t\tCOMPARE ACSA Solution TYPES\n";

	std::ofstream file;
	file.open("compareAcsaSol.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip1();
	vector<AcsaSolver> solvers;
	for (size_t i = 0; i < 3; i++)
	{
		solvers.push_back(AcsaSolver());
	}
	file << "it - jobs - mchns - RAND - DEFAULT - NEH\n";
	for (size_t problemSize = 0; problemSize < instancesNumber; problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;
		solvers[0].setSolvingParams(initSolutionType::RAND, neighType::INSERT, 0.5, n * n / 2, 500, 0.5);
		solvers[1].setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 0.5);
		solvers[2].setSolvingParams(initSolutionType::NEH, neighType::INSERT, 0.5, n * n / 2, 500, 0.5);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumPrd = 0;
			size_t repLimit = 2;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					size_t makespan = calculateMakespan(pI, solvers[solver].solve(pI));
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
				}
			}
			file << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void compareAllAlgorithmsResults()
{
	std::cout << "\t\tCOMPARE ALL ALGORITHMS RESULTS\n";

	std::ofstream fileRes;
	fileRes.open("compareAllRes2-3.txt");
	std::ofstream fileTime;
	fileTime.open("compareAllTime2-3.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip3();
	vector<ProblemSolver*> solvers;
	/*solvers.push_back(new NehSolver());
	NehXSolver* nehx = new NehXSolver();
	nehx->setParams(25);
	solvers.push_back(nehx);

	SaSolver* saSol = new SaSolver();
	saSol->setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, 10, 0.98);
	solvers.push_back(saSol);

	AcsaSolver* acsaSol1 = new AcsaSolver();
	acsaSol1->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, 10, 500, 0.5);
	solvers.push_back(acsaSol1);*/

	AcsaSolver* acsaSol2 = new AcsaSolver();
	acsaSol2->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, 10, 10, 0.5);
	solvers.push_back(acsaSol2);

	fileRes << "it - jobs - mchns - Neh - Neh+ - SA - ACSA (500it) - ACSA(n^2/2it)\n";
	fileTime << "it - jobs - mchns - Neh - Neh+ - SA - ACSA (500it) - ACSA(n^2/2it)\n";
	for (size_t problemSize = 6; problemSize < dimensionList.size(); problemSize++)
	{
		fileRes << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		fileTime << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;

		/*SaSolver* saSol = (SaSolver*)solvers[2];
		saSol->setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n*n/2, 0.98);

		AcsaSolver* acsaSol1 = (AcsaSolver*)solvers[3];
		acsaSol1->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n*n/2, 500, 0.5);*/
		
		AcsaSolver* acsaSol2 = (AcsaSolver*)solvers[0];
		acsaSol2->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n*n/2, n*n/2, 0.5);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << "solver " << solver << "\n";
			double sumPrd = 0;
			size_t sumTime = 0;
			size_t repLimit = 1;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				//std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
					vector<size_t> sol = solvers[solver]->solve(pI);
					size_t makespan = calculateMakespan(pI, sol);
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					if (makespan < pI->upperB)
					{
						std::ofstream fileUp;
						fileUp.open("updatedMakespan.txt", std::ios_base::app);
						fileUp << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " solver:" << solver << " instance:" << instance << " " << pI->upperB << "\n";
						for (size_t i = 0; i < sol.size(); i++)
						{
							fileUp << sol[i] << " ";
						}
						fileUp << "\n\n";
					}
					sumPrd += ((double)makespan - (double)pI->upperB) / (double)pI->upperB * 100;
					sumTime += std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
				}
			}
			fileRes << sumPrd / (double)instancesPerFile / (double)repLimit << " ";
			fileTime << sumTime / instancesPerFile / repLimit << " ";
		}
		fileRes << "\n";
		fileRes.flush();
		fileTime << "\n";
		fileTime.flush();
	}
	fileRes.close();
	fileTime.close();
}

void compareAllAlgorithmsTime()
{
	std::cout << "\t\tCOMPARE ALL ALGORITHMS TIME\n";

	std::ofstream file;
	file.open("compareAllTime2.txt");

	vector<pair<size_t, size_t>> dimensionList = getAllInstanceSizesSkip1();
	vector<ProblemSolver*> solvers;
	solvers.push_back(new NehSolver());
	NehXSolver* nehx = new NehXSolver();
	nehx->setParams(25);
	solvers.push_back(nehx);

	SaSolver* saSol = new SaSolver();
	saSol->setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, 10, 0.98);
	solvers.push_back(saSol);

	AcsaSolver* acsaSol1 = new AcsaSolver();
	acsaSol1->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, 10, 500, 0.5);
	solvers.push_back(acsaSol1);

	AcsaSolver* acsaSol2 = new AcsaSolver();
	acsaSol1->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, 10, 10, 0.5);
	solvers.push_back(acsaSol2);

	file << "it - jobs - mchns - Neh - Neh+ - SA - ACSA (500it) - ACSA(n^2/2it)\n";
	for (size_t problemSize = 5; problemSize < dimensionList.size(); problemSize++)
	{
		file << problemSize + 1 << " " << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << " ";
		vector<ProblemInstance> instanceVect = readProblemInstance(dimensionList[problemSize].first, dimensionList[problemSize].second);

		size_t n = dimensionList[problemSize].first;

		SaSolver* saSol = (SaSolver*)solvers[2];
		saSol->setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, n * n / 2, 0.98);

		AcsaSolver* acsaSol1 = (AcsaSolver*)solvers[3];
		acsaSol1->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, 500, 0.5);

		AcsaSolver* acsaSol2 = (AcsaSolver*)solvers[4];
		acsaSol2->setSolvingParams(initSolutionType::DEFAULT, neighType::INSERT, 0.5, n * n / 2, n * n / 2, 0.5);

		std::cout << dimensionList[problemSize].first << " " << dimensionList[problemSize].second << "\n";
		for (size_t solver = 0; solver < solvers.size(); solver++)
		{
			std::cout << solver << "\n";
			double sumIterative = 0;
			size_t repLimit = 2;
			for (size_t instance = 0; instance < instancesPerFile; instance++)
			{
				std::cout << "\t\tinstance solver " << instance << " " << solver << "\n";
				ProblemInstance* pI = &instanceVect[instance];
				for (size_t repeat = 0; repeat < repLimit; repeat++)
				{
					std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
					size_t makespan = calculateMakespan(pI, solvers[solver]->solve(pI));
					std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
					sumIterative += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
				}
			}
			file << sumIterative / (double)instancesPerFile / (double)repLimit << " ";
		}
		file << "\n";
		file.flush();
	}
	file.close();
}

void measureRuntime()
{
	SaSolver sa;
	sa.setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, 200 * 200 / 2, 0.98);
	vector<ProblemInstance> instanceVect = readProblemInstance(50, 10);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//sa.solve(&instanceVect[0]);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	double res = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
	std::cout << "200 20 " << res << "\n";
	instanceVect = readProblemInstance(50, 20);
	sa.setParams(initSolutionType::DEFAULT, neighType::INSERT, coolingType::GEOMETRICAL, 130, 1, 500 * 500 / 2, 0.98);
	vector<size_t> solution = getInitialSolution(50, initSolutionType::RAND, &instanceVect[0]);
	begin = std::chrono::steady_clock::now();
	//sa.solve(&instanceVect[0]);
	calculateMakespan(&instanceVect[0], solution);
	end = std::chrono::steady_clock::now();
	res = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << "500 20 " << res << "\n";
}