#include "util.h"
#include "Tester.h"
#include "Experiments.h"

int main()
{
    setup();
    size_t expNumb = 0;
    std::cin >> expNumb;
    switch (expNumb)
    {
    case 1:
        runTuningNehX();
        break;
    case 2:
        runTuningAcsaTmin();
        break;
    case 3:
        runTuningAcsaCoolingRate();
        break;
    case 4:
        runTuningSAGeoT0();
        break;
    case 5:
        runTuningSALinT0();
        break;
    case 6:
        runTuningSALogT0();
        break;
    case 7:
        runTuningSAGeoTk();
        break;
    case 8:
        runTuningSALinTk();
        break;
    case 9:
        runTuningSALogTk();
        break;
    case 10:
        runTuningSAGeoCoolingRate();
        break;
    case 11:
        runTuningSALinCoolingRate();
        break;
    case 12:
        compareSaCoolingTypes();
        break;
    case 13:
        compareSaNeighTypes();
        break;
    case 14:
        compareSaSolTypes();
        break;
    case 15:
        compareAcsaNeighTypes();
        break;
    case 16:
        compareAcsaStartSolutionTypes();
        break;
    case 17:
        compareAllAlgorithmsResults();
        break;
    case 18:
        compareAllAlgorithmsTime();
        break;
    case 19:
        compareMakespanCalculation();
        break;
    }

}