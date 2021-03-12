
#ifndef getPixels_h
#define getPixels_h

using namespace std;

vector<Pixel> getPixels(string fileName)
{
    vector<Pixel> pixels;
    ifstream imageFile{fileName};
    
    if(imageFile.is_open())
    {
        string item;
        for(int i=0; i<4; i++)
        {
            imageFile >> item;
        }
        
        while(imageFile.good())
        {
            Pixel pixel;
            
            imageFile >> item;
            pixel.set_red(stoi(item));
            imageFile >> item;
            pixel.set_green(stoi(item));
            imageFile >> item;
            pixel.set_blue(stoi(item));
            pixels.push_back(pixel);
        }
    }
    
    imageFile.close();
    
    return pixels;
}

vector<string> getMetadata(string fileName)
{
    vector<string> metadata;
    ifstream imageFile{fileName};
    if(imageFile.is_open())
    {
        for(int i=0; i<4; i++)
        {
            string item;
            imageFile >> item;
            metadata.push_back(item);
        }
    }
    imageFile.close();
    return metadata;
}


#endif /* getPixels_h */
