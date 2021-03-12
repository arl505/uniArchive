
/*
Github: github.com/arl505/CS-211
Assignment: Lab 03
Description: a program that will add a simple green screen effect to a PPM image (heavily restricted)
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: ~1 hours
In completing this program, I received help from the following people: none

Note: In completing this lab I reused code from PA2
*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "pixel.h"
#include "getPixels.h"
#include "outputFile.h"
using namespace std;

int main()
{
    string keyFile, targetFile, outputFileName;
    bool fileGood = false;

    cout << "*** PPM Green Screen Effect ***" << endl << endl;
    cout << "Enter key PPM: ";
    cin >> keyFile;
    
    ifstream key{keyFile};
    if(key.is_open())
    {
        fileGood = true;
    }
    key.close();
    
    while(fileGood == false)
    {
        cout << endl << "Invalid Entry" << endl;
        cout << "Enter key PPM: ";
        cin >> keyFile;
        
        ifstream key{keyFile};
        if(key.is_open())
        {
            fileGood = true;
        }
        key.close();
    }
    fileGood = false;
    
    cout << "Enter target PPM: ";
    cin >> targetFile;
    
    ifstream target{targetFile};
    if(target.is_open())
    {
        fileGood = true;
    }
    target.close();
    
    while(fileGood == false)
    {
        cout << endl << "Invalid Entry" << endl;
        cout << "Enter target PPM: ";
        cin >> targetFile;
        
        ifstream key{targetFile};
        if(target.is_open())
        {
            fileGood = true;
        }
        target.close();
    }
    fileGood = false;
    
    cout << "Enter output PPM: ";
    cin >> outputFileName;
    
    vector<Pixel> keyPixels = getPixels(keyFile);
    vector<Pixel> targetPixels = getPixels(targetFile);
    vector<Pixel> output;
    Pixel keyColor = keyPixels.at(0);
    
    for(int i = 0; i < keyPixels.size(); i++)
    {
        if(keyPixels.at(i) == keyColor )
        {
            output.push_back(targetPixels.at(i));
        }
        else
        {
            output.push_back(keyPixels.at(i));
        }
    }
    
    vector<string> metadata = getMetadata(targetFile);
    outputFile(outputFileName, metadata, output);
}
