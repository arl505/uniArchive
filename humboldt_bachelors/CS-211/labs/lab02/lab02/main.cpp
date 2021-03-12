
/*
Assignment: Lab 02
Description: Intro to PA2
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: ~1 hour
In completing this program, I received help from the following people: none
*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "pixel.h"
#include "getPixels.h"
#include "outputFile.h"
#include "basicOperations.h"
using namespace std;

int main()
{
    srand(time(NULL));
    
    // we are going to process the file into this vector of pixels
    vector<Pixel> pixels;
    
    // parse the file
    pixels = getPixels("bunny.ppm");
    
    
    // get the top three metadata lines
    vector<string> metadata = getMetadata("bunny.ppm");
    
    // do the operation
    pixels = grayscale(pixels);
    
    // output the file
    outputFile("bunny_edit.ppm", metadata, pixels);
    
}
