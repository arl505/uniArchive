
/*
Github: github.com/arl505/CS-211
Assignment: Lab 04
Description: a program that will decode secret messages embedded into PPM files
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: 1 hour 20 minutes (have not yet attempted Extra Credit)
In completing this program, I received help from the following people: none

Note: In completing this lab I reused code from PA2 and Lab 03
*/
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include "pixel.h"
#include "getPixels.h"
#include "outputFile.h"
#include "getMessage.h"
#include "sendMessage.h"
using namespace std;

int main()
{
    srand(time(NULL));
    
    bool keepGoing = true;
    bool fileGood = false;
    string filename;
    string response;
    string answer;
    while(keepGoing)
    {
        cout << "Enter D to decode a message from a PPM file\nEnter E to encode a message to a PPM file\nor enter X to exit: ";
        getline(cin, response);
        cout << endl;
        if(response == "d" || response == "D")
        {
            answer = getMessage();
            cout << endl << "Secret message: " << answer << endl << endl;
        }
        else if(response == "e" || response == "E")
        {
            cout << "Would you like to encode an existing PPM file or encode a message" << endl;
            cout << "into a new, randomly generated PPM file?" << endl;
            cout << "Enter E for existing or N for new: ";
            getline(cin, answer);
            if(answer == "e" || answer == "E")
            {
                cout << "Enter existing filename of existing PPM file to be encoded with secret message: ";
                getline(cin, filename);
                ifstream key{filename};
                if(key.is_open())
                {
                    fileGood = true;
                }
                key.close();
                
                while(fileGood == false)
                {
                    cout << endl << "Invalid Entry" << endl;
                    cout << "Enter existing filename of existing PPM file to be encoded with secret message: ";
                    getline(cin, filename);
                    
                    ifstream key{filename};
                    if(key.is_open())
                    {
                        fileGood = true;
                    }
                    key.close();
                }
                vector<Pixel> pixels = getPixels(filename);
                cout << "Enter a secret message to encode: ";
                getline(cin, answer);
                cout << endl;
                while(answer.length() > 500 || answer.length() == 0 || answer.length() > pixels.size())
                {
                    cout << "Entry too long or empty\n\nEnter a secret message to encode: ";
                    getline(cin, answer);
                    cout << endl;
                }
                encodeExistingImage(filename, answer);
            }
            
            else if(answer == "n" || answer == "N")
            {
                cout << "Enter a secret message to encode: ";
                getline(cin, answer);
                cout << endl;
                while(answer.length() > 500 || answer.length() == 0)
                {
                    cout << "Entry too long or empty\n\nEnter a secret message to encode: ";
                    getline(cin, answer);
                    cout << endl;
                }
                encodeNewImage(answer);
                cout << "Message encoded in output.ppm" << endl << endl;
            }
        }
        else if(response == "x" || response == "X")
        {
            keepGoing = false;
        }
    }
   
}
