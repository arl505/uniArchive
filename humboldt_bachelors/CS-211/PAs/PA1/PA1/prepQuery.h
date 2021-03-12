#ifndef queryDeaths_h
#define queryDeaths_h

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include "performQuery.h"
using namespace std;

vector<string> prepQuery(vector<string> args)
{
    string inputState = args.at(0);
    string inputCause = args.at(1);
    string inputYear = args.at(2);
    
    unordered_map<string , int> states;
    unordered_map<string , int> causes;
    unordered_map<string , int> years;
    
    vector<string> results;
    
    ifstream deathsFile{ "death_rates.csv" };
    if(deathsFile.is_open())
    {
        string lineItem;
        
        // get top header line and forget about it
        getline(deathsFile, lineItem);
        
        // we are going to parse the file line by line
        // taking the "lineItem" as each comma seperated value and
        // appropriately storing it, making it all lower caser for simplicity
        while(deathsFile.good())
        {
            getline(deathsFile, lineItem, ',');
            years[lineItem] = 1;
            
            getline(deathsFile, lineItem, ',');
            transform(lineItem.begin(), lineItem.end(), lineItem.begin(), ::tolower);
            causes[lineItem] = 1;
            
            getline(deathsFile, lineItem, ',');
            transform(lineItem.begin(), lineItem.end(), lineItem.begin(), ::tolower);
            states[lineItem] = 1;
            
            // put buffer at start of next line
            getline(deathsFile, lineItem);
            
        }
    }
     deathsFile.close();
    
    // lets check if the inputted values are valid and
    // if not, add the issue to an errors vector to be used in
    // returning an error message to the user
    
    // when validating, lets make everything lowercase, now users can enter mixed
    // case and will still work, but we still have the user's possibly
    // wonky, originally entered args in the args parameter
    vector<string> errors;
    transform(inputState.begin(), inputState.end(), inputState.begin(), ::tolower);
    transform(inputCause.begin(), inputCause.end(), inputCause.begin(), ::tolower);
    
    if((years[inputYear] != 1 or inputYear =="year") and (inputYear != "-1"))
    {
        errors.push_back("year");
    }

    
    if((causes[inputCause] != 1 or inputCause =="year") and (inputCause != "-1"))
    {
        errors.push_back("cause");
    }
    
    if((states[inputState] != 1 or inputState =="year") and (inputState != "-1"))
    {
        errors.push_back("state");
    }

    
    // lets now check if we have any input errors, if not,
    // perform the query and return the results, if we have errors,
    // based on how many we have (darn you grammar of lists), make a nice response
    if(errors.size() == 0)
    {
        string state = (args.at(0)=="-1")?("all states"):(args.at(0));
        string cause = (args.at(1)=="-1")?("all causes"):(args.at(1));
        string year = (args.at(2)=="-1")?("all years"):("the year " + args.at(2));
        string amount = to_string(performQuery(args));
        int lengthToDecimalPoint = 0;
        for(int i = 0; i < amount.length(); i++)
        {
            if(amount[i] == '.')
            {
                lengthToDecimalPoint = i;
            }
        }
        amount = amount.substr(0, lengthToDecimalPoint);
        
        
        string result_sentence = "Total deaths in " + state + " from " + cause + " in " + year + ": " + amount;
        results.push_back(result_sentence);
    }
    else if(errors.size() == 1)
    {
        cout << "Invalid " << errors.at(0) << " entered" << endl;
    }
    
    else if(errors.size() == 2)
    {
        cout << "Invalid " << errors.at(0) << " and " << errors.at(1) << " entered" << endl;

    }
    
    else if(errors.size() == 3)
    {
        cout << "Invalid " << errors.at(0) << ", " << errors.at(1) << ", and " << errors.at(2) << " entered" << endl;
    }
    
    return results;
}


#endif /* queryDeaths_h */
