
/*
Github: github.com/arl505/CS-211
Assignment: PA 5
Description: this program uses hash tables and priority queues to perform compression on input files.
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: 1.5 hours
In completing this program, I received help from the following people: none
*/
#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bitset>
#include "loadMap.h"
#include "runCompression.h"
#include "decompress.h"
using namespace std;

int main()
{
    string response;
    cout << "(E)ncode or (D)ecode file: ";
    getline(cin, response);
    if(response != "e" && response != "E" && response != "d" && response != "D")
    {
        cout << "Invalid response" << endl << "(E)ncode or (D)ecode file: ";
        getline(cin, response);
    }
    
    if(response == "e" || response == "E")
    {
        string fileName;
        cout << "Enter file to compress: ";
        getline(cin, fileName);
        ifstream file{fileName};
        bool responseGood = file.is_open();
        file.close();
        while(!responseGood)
        {
            cout << "Invalid filename" << endl <<"Enter file to compress: ";
            getline(cin, fileName);
            ifstream testFile{fileName};
            if(testFile.is_open())
            {
                responseGood = true;
            }
            testFile.close();
        }
        runCompression(fileName);
    }
    else
    {
        string compressedFileName;
        cout << "Enter file to decompress: ";
        getline(cin, compressedFileName);
        ifstream file{compressedFileName};
        bool responseGood = file.is_open();
        file.close();
        while(!responseGood)
        {
            cout << "Invalid filename" << endl <<"Enter file to decompress: ";
            getline(cin, compressedFileName);
            ifstream testFile{compressedFileName};
            if(testFile.is_open())
            {
                responseGood = true;
            }
            testFile.close();
        }
        
        string codesFileName;
        cout << "Enter codes file: ";
        getline(cin, codesFileName);
        ifstream codesFile{codesFileName};
        responseGood = codesFile.is_open();
        codesFile.close();
        while(!responseGood)
        {
            cout << "Invalid filename" << endl << "Enter codes file: ";
            getline(cin, codesFileName);
            ifstream testFile{codesFileName};
            if(testFile.is_open())
            {
                responseGood = true;
            }
            testFile.close();
        }
        
        decompress(compressedFileName, codesFileName);
    }
}
