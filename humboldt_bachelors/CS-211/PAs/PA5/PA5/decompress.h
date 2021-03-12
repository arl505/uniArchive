#ifndef decompress_h
#define decompress_h

void decompress(string compressedFileName, string codesFileName)
{
    unordered_map<string, string> mappings;
    
    ifstream codesFile{codesFileName};
    if(codesFile.is_open())
    {
        while(codesFile.good())
        {
            string currWord;
            string currWordMapsTo;
            getline(codesFile, currWord, ':');
            getline(codesFile, currWordMapsTo);
            if(currWord != "")
            {
                mappings[currWordMapsTo] = currWord;
            }
        }
    }
    codesFile.close();
    
    ifstream compressedFile{compressedFileName};
    string prefix = getPrefix(compressedFileName);
    ofstream outputFile{prefix+".txt"};
    if(compressedFile.is_open())
    {
        while(compressedFile.good())
        {
            string currWord;
            compressedFile >> currWord;
            if(compressedFile.good())
            {
                outputFile << mappings[currWord] << " ";
            }
            else
            {
                outputFile << mappings[currWord];
            }
        }
    }
    compressedFile.close();
    outputFile.close();
    cout << "File decoded to " + prefix + ".txt" << endl;
}
#endif /* decompress_h */
