#ifndef sendMessage_h
#define sendMessage_h

void encodeExistingImage(string filename, string secretMessage)
{
    vector<Pixel> pixels = getPixels(filename);
    vector<string> metadata = getMetadata(filename);
    int numRows = stoi(metadata.at(1));
    int numColumns = stoi(metadata.at(2));
    
    if(numRows >= 255 && numColumns >= 255)
    {
        char letter;
        int letterVal;
        double nextRow, nextColumn;
        int curr1dPixelPlace;
        unordered_map<int, int> pixelsTaken;
       
        letter = secretMessage[0];
        letterVal = letter;
        nextRow = rand() % 256;
        nextColumn = rand() % 256;
        pixels.at(0).set_red(letterVal);
        if(secretMessage.length() == 1)
        {
            pixels.at(0).set_green(0);
            pixels.at(0).set_blue(0);
        }
        else
        {
            pixels.at(0).set_green(nextRow);
            pixels.at(0).set_blue(nextColumn);
        }
        
        pixelsTaken[0] = 1;
        
        for(int i = 1; i < secretMessage.length(); i++)
        {
            letter = secretMessage[i];
            letterVal = letter;
            curr1dPixelPlace = (nextRow * numColumns) + nextColumn;
            pixelsTaken[curr1dPixelPlace] = 1;
            nextRow = rand() % 256;
            nextColumn = rand() % 256;
            while(pixelsTaken[((nextRow * numColumns) + nextColumn)] == 1)
            {
                nextRow = rand() % 256;
                nextColumn = rand() % 256;
            }
            pixels.at(curr1dPixelPlace).set_red(letterVal);
            if(i == (secretMessage.length()-1))
            {
                pixels.at(curr1dPixelPlace).set_green(0);
                pixels.at(curr1dPixelPlace).set_blue(0);
            }
            else
            {
                pixels.at(curr1dPixelPlace).set_green(nextRow);
                pixels.at(curr1dPixelPlace).set_blue(nextColumn);
            }
        }
        outputFile(filename, pixels, numRows, numColumns);
        cout << "Message encoded in " << filename << endl << endl;
    }
    else
    {
        char letter;
        int letterVal;
        double nextRow, nextColumn;
        int curr1dPixelPlace;
        unordered_map<int, int> pixelsTaken;
       
        letter = secretMessage[0];
        letterVal = letter;
        nextRow = rand() % (numRows+1);
        nextColumn = rand() % (numColumns+1);
        pixels.at(0).set_red(letterVal);
        if(secretMessage.length() == 1)
        {
            pixels.at(0).set_green(0);
            pixels.at(0).set_blue(0);
        }
        else
        {
            pixels.at(0).set_green(nextRow);
            pixels.at(0).set_blue(nextColumn);
        }
        
        pixelsTaken[0] = 1;
        
        for(int i = 1; i < secretMessage.length(); i++)
        {
            letter = secretMessage[i];
            letterVal = letter;
            curr1dPixelPlace = (nextRow * numColumns) + nextColumn;
            pixelsTaken[curr1dPixelPlace] = 1;
            nextRow = rand() % (numRows);
            nextColumn = rand() % (numColumns);
            while(pixelsTaken[((nextRow * numColumns) + nextColumn)] == 1)
            {
                nextRow = rand() % (numRows+1);
                nextColumn = rand() % (numColumns+1);
            }
            pixels.at(curr1dPixelPlace).set_red(letterVal);
            if(i == (secretMessage.length()-1))
            {
                pixels.at(curr1dPixelPlace).set_green(0);
                pixels.at(curr1dPixelPlace).set_blue(0);
            }
            else
            {
                pixels.at(curr1dPixelPlace).set_green(nextRow);
                pixels.at(curr1dPixelPlace).set_blue(nextColumn);
            }
        }
        outputFile(filename, pixels, numRows, numColumns);
        cout << "Message encoded in " << filename << endl << endl;
        
    }
}

void encodeNewImage(string secretMessage)
{
    vector<Pixel> pixels;
    for(double i = 0; i < 250000; i++)
    {
        Pixel pixel;
        pixel.set_red(rand()%256);
        pixel.set_green(rand()%256);
        pixel.set_blue(rand()%256);
        pixels.push_back(pixel);
    }
    
    char letter;
    int letterVal;
    double nextRow, nextColumn;
    int curr1dPixelPlace;
    unordered_map<int, int> pixelsTaken;
   
    letter = secretMessage[0];
    letterVal = letter;
    nextRow = rand() % 256;
    nextColumn = rand() % 256;
    pixels.at(0).set_red(letterVal);
    if(secretMessage.length() == 1)
    {
        pixels.at(0).set_green(0);
        pixels.at(0).set_blue(0);
    }
    else
    {
        pixels.at(0).set_green(nextRow);
        pixels.at(0).set_blue(nextColumn);
    }
    
    pixelsTaken[0] = 1;
    
    for(int i = 1; i < secretMessage.length(); i++)
    {
        letter = secretMessage[i];
        letterVal = letter;
        curr1dPixelPlace = (nextRow * 500) + nextColumn;
        pixelsTaken[curr1dPixelPlace] = 1;
        nextRow = rand() % 256;
        nextColumn = rand() % 256;
        while(pixelsTaken[((nextRow * 500) + nextColumn)] == 1)
        {
            nextRow = rand() % 256;
            nextColumn = rand() % 256;
        }
        pixels.at(curr1dPixelPlace).set_red(letterVal);
        if(i == (secretMessage.length()-1))
        {
            pixels.at(curr1dPixelPlace).set_green(0);
            pixels.at(curr1dPixelPlace).set_blue(0);
        }
        else
        {
            pixels.at(curr1dPixelPlace).set_green(nextRow);
            pixels.at(curr1dPixelPlace).set_blue(nextColumn);
        }
    }
    outputFile("output.ppm", pixels, 500, 500);
}

#endif /* sendMessage_h */
