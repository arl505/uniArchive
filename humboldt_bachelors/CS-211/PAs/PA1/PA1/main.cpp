
/*
Assignment: PA1
Description: Analyzes death statistics provided by the US government.
             Prompts the user for a state, cause of death, and year.
             Then outputs the total number of deaths that match the criteria.
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: 4 hours
In completing this program, I received help from the following people: none
*/

#include "getQueryArgs.h"
#include "prepQuery.h"
#include <iostream>
using namespace std;

int main() {
    cout << "***Death Rate Data Analysis***" << endl << endl;
    bool keep_going = true;
    while(keep_going)
    {
        // prompt and get query arguments
        vector<string> args = getQueryArgs();
        
        // prep and perform query
        vector<string> results = prepQuery(args);
        
        // output to screen
        cout << endl;
        for(auto item : results)
        {
            cout << item << endl;
        }
        cout << "Would you like to run another query (Y/N)?: ";

        
        // get response and set keep_going appropriately
        string response;
        getline(cin, response);
        cout << endl;
        while(response != "N" and response != "n" and response != "y" and response != "Y")
        {
            cout << "Invalid entry\nWould you like to run anouther query (Y/N)?: ";
            getline(cin, response);
            cout << endl;

        }
        if(response == "n" or response == "N")
        {
            keep_going = false;
        }
        else
        {
            keep_going = true;
        }
    }
}
