#ifndef areActorsConnected_h
#define areActorsConnected_h

#include "StringSplitter.h"

void areActorsConnected()
{
    string startID, endID, currID, currLine;
    vector<string> currLinePieces;
    vector<string> knownFor;
    cout << "Enter First Actor ID: ";
    getline(cin, startID);
    cout << "Enter Second Actor ID: ";
    getline(cin, endID);
    
    ifstream moviesFile{"reduced.tsv"};
    if(moviesFile.is_open())
    {
        getline(moviesFile, currLine);
        while(moviesFile.good() && currID != startID)
        {
            getline(moviesFile, currLine);
            currLinePieces = StringSplitter::split(currLine, "\t");
            currID = currLinePieces[0];
            knownFor = StringSplitter::split(currLinePieces[5], ",");
        }
    }
    
    cout << startID << " and " << endID << " are not connected.\n\n";
}

#endif /* areActorsConnected_h */
