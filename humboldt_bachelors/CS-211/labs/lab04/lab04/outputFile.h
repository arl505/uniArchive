
#ifndef outputFile_h
#define outputFile_h

void outputFile(string fileName, vector<Pixel> pixels, int width, int height)
{
    ofstream outputFile{fileName};
    
    outputFile << "P3" << endl << width << " " << height << endl << "255" << endl;
    
    for(auto item : pixels)
    {
        outputFile << item.get_red() << " " << item.get_green() << " " << item.get_blue() << endl;
    }
    
    outputFile.close();
}

#endif /* outputFile_h */
