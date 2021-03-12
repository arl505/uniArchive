#ifndef getQueryArgs_h
#define getQueryArgs_h

#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> getQueryArgs()
{
    string inputState;
    string inputCause;
    string inputYear;
    
    cout << "Enter State (-1 for all states): ";
    getline(cin, inputState);
    
    cout << "Enter Cause (-1 for all causes): ";
    getline(cin, inputCause);

    cout << "Enter Year (-1 for all years): ";
    getline(cin, inputYear);

    vector<string> args;
    args.push_back(inputState);
    args.push_back(inputCause);
    args.push_back(inputYear);
    
    return args;
}



#endif /* getQueryArgs_h */
