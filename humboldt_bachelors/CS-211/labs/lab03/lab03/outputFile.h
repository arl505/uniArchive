
#ifndef outputFile_h
#define outputFile_h

void outputFile(string fileName, vector<string> metadata, vector<Pixel> pixels)
{
    ofstream outputFile{fileName};
    
    outputFile << metadata.at(0) << endl << metadata.at(1) << " " << metadata.at(2) << endl << metadata.at(3) << endl;
    
    for(auto item : pixels)
    {
        outputFile << item.get_red() << " " << item.get_green() << " " << item.get_blue() << endl;
    }
    
    outputFile.close();
}

#endif /* outputFile_h */
