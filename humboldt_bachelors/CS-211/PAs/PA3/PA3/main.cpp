
/*
Github: github.com/arl505/CS-211
Assignment: PA 3
Description: a checkout lane simulation that can be used to determine
                the optimal number of lanes that Jacks Mart should have open
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: 3 hours
In completing this program, I received help from the following people: none
*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_map>
#include "checkstand.h"
#include "customer.h"
using namespace std;

int main()
{
    srand(time(NULL));
    
    int numStands = 0;
    string entry;
    bool isEntryGood = false;
    int custCounter = 0;
    
    // part 1
    
    cout << "*** Jacks Mart Simulator ***" << endl;
    
    while(numStands < 1)
    {
        cout << endl << "How many checkstands would you like to simulate: ";
        cin >> entry;
        for(int i = 0; i < entry.length(); i++)
        {
            if(isdigit(entry[i]))
            {
                isEntryGood = true;
            }
            else
            {
                isEntryGood = false;
            }
        }
        if(isEntryGood == false)
        {
            cout << "Non-numeric value entered, try again" << endl;
        }
        else
        {
            if(stoi(entry) < 1)
            {
                cout << "Must enter value of at least 1" << endl;
            }
            
            else
            {
                numStands = stoi(entry);
            }
        }
    }
    
    // part 2
    
    vector<Checkstand> checkstands;
    
    for(int standNum = 0; standNum < numStands; standNum++)
    {
        Checkstand newStand;
        newStand.setLineNum(standNum);
        checkstands.push_back(newStand);
    }
    
    // part 3
    int newCustProbability = 0;
    
    
    for(int minute = 0; minute < 720; minute++)
    {
        if(rand() % 5 <= newCustProbability)
        {
            newCustProbability = 0;
            Customer newCustomer;
            newCustomer.setCustomerId(custCounter);
            custCounter++;
            newCustomer.setArrivalTime(minute);
            newCustomer.setPlaced(false);
            newCustomer.setServiceTime(rand() % 4 + 1);
            
            for(int i = 0; i < checkstands.size() && newCustomer.isPlaced() == false; i++)
            {
                if(checkstands.at(i).isEmpty())
                {
                    newCustomer.setLineNum(checkstands.at(i).getLineNum());
                    newCustomer.setPlaced(true);
                    checkstands.at(i).addCustomer(newCustomer);
                }
            }
            if(newCustomer.isPlaced() == false)
            {
                int randPlace = rand() % checkstands.size();
                newCustomer.setLineNum(checkstands.at(randPlace).getLineNum());
                newCustomer.setPlaced(true);
                checkstands.at(randPlace).addCustomer(newCustomer);
            }
        }
        else
        {
            newCustProbability++;
        }
        
        for(int i = 0; i < checkstands.size(); i++)
        {
            if(!checkstands.at(i).isEmpty())
            {
                if(checkstands.at(i).getInLine().front().getDepartureTime() == 0)
                {
                    queue<Customer> inLine = checkstands.at(i).getInLine();
                    inLine.front().setDepartureTime(minute);
                    checkstands.at(i).setInLine(inLine);
                }
                
                if(checkstands.at(i).getInLine().front().getDepartureTime() < minute)
                {
                    queue<Customer> currServed = checkstands.at(i).getServed();
                    queue<Customer> currInLine = checkstands.at(i).getInLine();
                    currServed.push(currInLine.front());
                    checkstands.at(i).setServed(currServed);
                    currInLine.pop();
                    checkstands.at(i).setInLine(currInLine);
                }
            }
        }
    }
    

    
    ofstream output{"output.csv"};
    output << "Customers Created: ," << custCounter << "\n";
    output << "Customer ID,Arrival,Time to Check Out,Departure,Total Wait,Line Number\n";
    
    double totalWait = 0;
    double totalServed = 0;
    for(int i = 0; i < checkstands.size(); i++)
    {
        queue<Customer> served = checkstands.at(i).getServed();
        int howManyTimes = (int)served.size();
        for(int c = 0; c < howManyTimes; c++)
        {
            Customer currCust = served.front();
            totalServed++;
            totalWait += currCust.getTotalWaitTime();
            served.pop();
            output << currCust.getCustomerId() << "," << currCust.getArrivalTime() << "," << currCust.getServiceTime() << ",";
            output << currCust.getDepartureTime() << "," << currCust.getTotalWaitTime() << "," << currCust.getLineNum() << "\n";
        }
    }
    
    output.close();
    cout.precision(2);
    cout << fixed;
    cout << endl << "Results outputted to output.csv" << endl;
    cout << "The average wait time was: " << totalWait/totalServed << endl << endl;
}
