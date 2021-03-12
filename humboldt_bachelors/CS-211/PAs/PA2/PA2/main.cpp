
/*
Github: github.com/arl505/CS-211
Assignment: PA 2
Description: a program that will add simple effects to a PPM image
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: 10 hours
In completing this program, I received help from the following people: none
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
#include "basicOperations.h"
#include "advancedOperations.h"
using namespace std;

int main()
{
    srand(time(NULL));
    
    string inputFileName;
    string outputFileName;
    int operationNum;
    bool isFileValid = false;
    
    
    cout << "PPM Image Manipulator\nEnter input file: ";
    cin >> inputFileName;
    
    ifstream input{inputFileName};
    (input.is_open())?(isFileValid=true):(isFileValid=false);
    input.close();
   
    while(isFileValid == false)
    {
        cout << endl <<"Invalid input file entered" << endl;
        cout << "Enter input file: ";
        cin >> inputFileName;
        ifstream input{inputFileName};
        (input.is_open())?(isFileValid=true):(isFileValid=false);
        input.close();
    }
    
    cout << endl << "Enter output file: ";
    cin >> outputFileName;
    
    // we are going to process the file into this vector of pixels
    vector<Pixel> pixels;
    
    // parse the file
    pixels = getPixels(inputFileName);
    
    // get the top three metadata lines
    vector<string> metadata = getMetadata(inputFileName);
    
    bool keep_going = true;
    while(keep_going)
    {
        cout << "Image Effects Menu" << endl;
        cout << "1. Remove Red\t2. Remove Green\t3. Remove Blue\t4. Negate Red" << endl;
        cout << "5. Negate Green\t6. Negate Blue\t7. Add Random Noise\t8. High Contrast" << endl;
        cout << "9. Grayscale\t10. Flip Horizontally\t11. Flip Vertically\t12. Flip 90" << endl;
        cout << "13. Blur\t14. Pixelate\t15. Exit Program" << endl << endl << "Selection: ";
        cin >> operationNum;
        
        switch(operationNum)
        {
            case 1:
                pixels = removeRed(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 2:
                pixels = removeGreen(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 3:
                pixels = removeBlue(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 4:
                pixels = negateRed(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 5:
                pixels = negateGreen(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 6:
                pixels = negateBlue(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 7:
                pixels = addRandomNoise(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 8:
                pixels = highContrast(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 9:
                pixels = grayscale(pixels);
                cout << "Effect applied" << endl << endl;
                break;
            case 10:
                pixels = flipHorizontally(pixels, stoi(metadata.at(1)), stoi(metadata.at(2)));
                cout << "Effect applied" << endl << endl;
                break;
            case 11:
                pixels = flipVertically(pixels, stoi(metadata.at(1)), stoi(metadata.at(2)));
                cout << "Effect applied" << endl << endl;
                break;
            case 12:
                pixels = rotate(pixels, stoi(metadata.at(1)), stoi(metadata.at(2)));
                iter_swap(metadata.begin() + 1, metadata.begin()+2);
                cout << "Effect applied" << endl << endl;
                break;
            case 13:
                for(int i = 0; i < 10; i++)
                {
                    pixels = blur(pixels, stoi(metadata.at(1)), stoi(metadata.at(2)));
                }
                cout << "Effect applied" << endl << endl;
                break;
            case 14:
                pixels = pixelate(pixels, stoi(metadata.at(1)), stoi(metadata.at(2)));
                cout << "Effect applied" << endl << endl;
                break;
            case 15:
                keep_going = false;
                cout << "Exiting program" << endl;
                break;
            default:
                cout << "Inavlid entry" << endl << endl;
        }
    }
    // output the file
    outputFile(outputFileName, metadata, pixels);
}
