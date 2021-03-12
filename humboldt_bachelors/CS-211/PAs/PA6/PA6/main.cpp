/*
Github: github.com/arl505/CS-211
Assignment: PA 6
Description:
Author: Alec Levin
HSU ID: 0125-44022
Completion Time:
In completing this program, I received help from the following people: none
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "Actor.h"
#include "listMovies.h"
#include "areActorsConnected.h"
#include "outputPath.h"
#include "associationsByDegree.h"
#include "Movie.h"
#include "StringSplitter.h"
using namespace std;

int main()
{
    string taskNum;
    cout << "What task would you like to run (2-5, x to quit): ";
    getline(cin, taskNum);
    while(taskNum != "x")
    {
        if(taskNum == "2")
            listMovies();
        else if (taskNum == "3")
            areActorsConnected();
        else if (taskNum == "4")
            outputPath();
        else if (taskNum == "5")
            associationsByDegree();
        else
            cout << "Invalid task number\n";
        
        cout << "What task would you like to run (2-5, x to quit): ";
        getline(cin, taskNum);
    }
}
