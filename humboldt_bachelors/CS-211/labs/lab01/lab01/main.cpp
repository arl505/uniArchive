#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "CsvParser.h"
using namespace std;

/*
    QUESTION FOR ADAM FOR PA1:
        * Must we add you as a collaborator on our private github?
        * Must we use the CsvReader.h file you just gave us?
        * Should our program handle input from a different deathRates.csv?
            - ie: do we need to worry about handling special character
                instances not included in provided deathRates.csv
        * Do you still require a project solution file?
        * Can we assume input will be case and character perfect?
        * How should we handle invalid input? Your UI doesn't show it
*/

int main()
{
   DefaultState state{nullptr};
   state.handle();
}
