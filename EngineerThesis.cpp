#include "util.h"
#include "Tester.h"
#include "Experiments.h"

int main()
{
    setup();
    testMakespanCalculation();

    //runTuningNehX(); //done
    //runTuningAcsaTmin(); //done
    //runTuningAcsaCoolingRate(); //done
    //runTuningSAGeoT0(); //done
    //runTuningSALinT0(); //done
    //runTuningSALogT0(); //done
    //runTuningSAGeoTk(); //done
    //runTuningSALinTk(); //done
    //runTuningSALogTk(); //done
    //runTuningSAGeoCoolingRate(); //done
    //runTuningSALinCoolingRate(); //done

    //compareSaCoolingTypes(); //done
    //compareSaNeighTypes(); //done
    //compareSaSolTypes(); //done
    //compareAcsaNeighTypes(); //done
    //compareAcsaStartSolutionTypes(); //possible rerun for 2nd part
    //compareAllAlgorithmsResults(); //rerun for 100 5+
    //compareAllAlgorithmsTime(); //rerun for 100 10+

    //compareMakespanCalculation(); //done
    measureRuntime(); //done
}