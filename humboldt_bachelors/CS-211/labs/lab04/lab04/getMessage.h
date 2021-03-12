#ifndef getMessage_h
#define getMessage_h

string getMessage(void)
{
    string keyFile, targetFile, outputFileName;
    bool fileGood = false;

    cout << "*** PPM Secret Message Decoder ***" << endl << endl;
    cout << "Enter filename of PPM file containing encoded message: ";
    getline(cin, keyFile);
    
    ifstream key{keyFile};
    if(key.is_open())
    {
        fileGood = true;
    }
    key.close();
    
    while(fileGood == false)
    {
        cout << endl << "Invalid Entry" << endl;
        cout << "Enter filename of PPM file containing encoded message: ";
        getline(cin, keyFile);
        
        ifstream key{keyFile};
        if(key.is_open())
        {
            fileGood = true;
        }
        key.close();
    }
    
    vector<Pixel> keyPixels = getPixels(keyFile);
    vector<string> metadata = getMetadata(keyFile);
    
    string secretMessage = "";
    int letterVal;
    char letter;
    int nextRow = 0;
    int nextColumn = 0;
    int rowLength = stoi(metadata.at(2));
    bool keepGoing = true;
    
    if(keyPixels.size() > 0)
    {
        letterVal = keyPixels.at(0).get_red();
        letter = letterVal;
        secretMessage += letter;
        
        nextRow = keyPixels.at(0).get_green();
        nextColumn = keyPixels.at(0).get_blue();
        if(nextRow == 0 && nextColumn == 0)
        {
            keepGoing = false;
        }
        
    }
    
    while(keepGoing)
    {
        int place = (nextRow * rowLength) + nextColumn;
        
        letterVal = keyPixels.at(place).get_red();
        letter = letterVal;
        secretMessage += letter;
        
        nextRow = keyPixels.at(place).get_green();
        nextColumn = keyPixels.at(place).get_blue();
        if(nextRow == 0 && nextColumn == 0)
        {
            keepGoing = false;
        }
        
    }
    
    return secretMessage;
}

#endif /* getMessage_h */
