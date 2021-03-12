#ifndef performQuery_h
#define performQuery_h

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "performQuery.h"
using namespace std;

double performQuery(vector<string> args)
{
    string result;
    double deathCount = 0;
    
    string inputState = args.at(0);
    string inputCause = args.at(1);
    string inputYear = args.at(2);
    
    transform(inputState.begin(), inputState.end(), inputState.begin(), ::tolower);
    transform(inputCause.begin(), inputCause.end(), inputCause.begin(), ::tolower);

    
    string currState;
    string currCause;
    string currYear;
    string endOfLine;
    string currDeaths;

    
    if(inputCause != "-1")
    {
        if(inputState != "-1")
        {
            if(inputYear != "-1")
            {
                // input year, state and cause != -1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        transform(currCause.begin(), currCause.end(), currCause.begin(), ::tolower);
                        transform(currState.begin(), currState.end(), currState.begin(), ::tolower);
                        if(currYear == inputYear && currCause == inputCause && currState == inputState)
                        {
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                deathRates.close();
            }
            else
            {
                // year == -1, state and cause != -1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        transform(currCause.begin(), currCause.end(), currCause.begin(), ::tolower);
                        transform(currState.begin(), currState.end(), currState.begin(), ::tolower);
                        if(currCause == inputCause && currState == inputState && currDeaths != "Deaths" && currDeaths != "")
                        {
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                deathRates.close();
            }
        }
        else
        {
            if(inputYear != "-1")
            {
                // input year and cause != -1, state==-1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        transform(currCause.begin(), currCause.end(), currCause.begin(), ::tolower);
                        transform(currState.begin(), currState.end(), currState.begin(), ::tolower);
                        if(currCause == inputCause && currYear == inputYear && currDeaths != "Deaths" && currDeaths != "")
                        {
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                deathRates.close();
            }
            else
            {
                // year, state == -1, cause != -1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        transform(currCause.begin(), currCause.end(), currCause.begin(), ::tolower);
                        transform(currState.begin(), currState.end(), currState.begin(), ::tolower);
                        if(currCause == inputCause  && currDeaths != "Deaths" && currDeaths != "")
                        {
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                 deathRates.close();
            }
        }
    }
    else
    {
         if(inputState != "-1")
        {
            if(inputYear != "-1")
            {
                // input year and state != -1, cause == -1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        transform(currCause.begin(), currCause.end(), currCause.begin(), ::tolower);
                        transform(currState.begin(), currState.end(), currState.begin(), ::tolower);
                        if(currYear == inputYear && inputState == currState  && currDeaths != "Deaths" && currDeaths != "")
                        {
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                deathRates.close();
            }
            else
            {
                // year and cause == -1, state != -1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        transform(currCause.begin(), currCause.end(), currCause.begin(), ::tolower);
                        transform(currState.begin(), currState.end(), currState.begin(), ::tolower);
                        if(inputState == currState && currDeaths != "Deaths" && currDeaths != "")
                        {
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                deathRates.close();
            }
        }
        else
        {
            if(inputYear != "-1")
            {
                // cause and state == -1, year != -1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        transform(currCause.begin(), currCause.end(), currCause.begin(), ::tolower);
                        transform(currState.begin(), currState.end(), currState.begin(), ::tolower);
                        if(currYear == inputYear && currDeaths != "Deaths" && currDeaths != "")
                        {
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                deathRates.close();
            }
            else
            {
                // year, state, cause == -1
                ifstream deathRates{"death_rates.csv"};
                if(deathRates.is_open())
                {
                    while(deathRates.good())
                    {
                        getline(deathRates, currYear, ',');
                        getline(deathRates, currCause, ',');
                        getline(deathRates, currState, ',');
                        getline(deathRates, currDeaths, ',');
                        getline(deathRates, endOfLine, '\n');
                        
                        if(currDeaths != "Deaths" && currDeaths != ""){
                            deathCount += stod(currDeaths);
                        }
                    }
                }
                deathRates.close();
            }
        }
    }
    
    return deathCount;
}

#endif /* performQuery_h */
