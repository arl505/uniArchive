
#ifndef basic_operations_h
#define basic_operations_h

vector<Pixel> removeRed(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        item.set_red(0);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> removeGreen(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        item.set_green(0);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> removeBlue(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        item.set_blue(0);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> negateRed(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        int pixelVal = item.get_red();
        pixelVal = 255 - pixelVal;
        item.set_red(pixelVal);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> negateGreen(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        int pixelVal = item.get_green();
        pixelVal = 255 - pixelVal;
        item.set_green(pixelVal);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> negateBlue(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        int pixelVal = item.get_blue();
        pixelVal = 255 - pixelVal;
        item.set_blue(pixelVal);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> addRandomNoise(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        int offset = rand() % 20 + (-10);
        int redVal = item.get_red();
        int greenVal = item.get_green();
        int blueVal = item.get_blue();
        
        if((redVal + offset) > 255)
        {
            redVal = 255;
        }
        else if((redVal + offset) < 0)
        {
            redVal = 0;
        }
        else
        {
            redVal += offset;
        }
        
        if((greenVal + offset) > 255)
        {
            greenVal = 255;
        }
        else if((greenVal + offset) < 0)
        {
            greenVal = 0;
        }
        else
        {
            greenVal += offset;
        }
        
        if((blueVal + offset) > 255)
        {
            blueVal = 255;
        }
        else if((blueVal + offset) < 0)
        {
            blueVal = 0;
        }
        else
        {
            blueVal += offset;
        }
        
        item.set_red(redVal);
        item.set_green(greenVal);
        item.set_blue(blueVal);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> highContrast(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        int redVal = item.get_red();
        int greenVal = item.get_green();
        int blueVal = item.get_blue();
        
        if(redVal > (255/2))
        {
            redVal = 255;
        }
        else
        {
            redVal = 0;
        }
        
        if(greenVal > (255/2))
        {
            greenVal = 255;
        }
        else
        {
            greenVal = 0;
        }
        
        if(blueVal > (255/2))
        {
            blueVal = 255;
        }
        else
        {
            blueVal = 0;
        }
        
        item.set_red(redVal);
        item.set_green(greenVal);
        item.set_blue(blueVal);
        results.push_back(item);
    }
    return results;
}

vector<Pixel> grayscale(vector<Pixel> pixels)
{
    vector <Pixel> results;
    for(auto item : pixels)
    {
        int redVal = item.get_red();
        int greenVal = item.get_green();
        int blueVal = item.get_blue();
        
        int averageVal = (redVal + greenVal + blueVal)/3;
        
        item.set_red(averageVal);
        item.set_green(averageVal);
        item.set_blue(averageVal);
        results.push_back(item);
    }
    return results;
}

#endif /* basic_operations_h */
