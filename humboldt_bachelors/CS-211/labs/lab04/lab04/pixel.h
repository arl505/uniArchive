
#ifndef pixel_h
#define pixel_h


class Pixel
{
private:
    int _red;
    int _green;
    int _blue;
public:
    void set_red(int pixelVal)
    {
        _red = pixelVal;
    }
    
    int get_red(void)
    {
        return _red;
    }
    
    void set_green(int pixelVal)
    {
        _green = pixelVal;
    }
    
    int get_green(void)
    {
        return _green;
    }
    
    void set_blue(int pixelVal)
    {
        _blue = pixelVal;
    }
    
    int get_blue(void)
    {
        return _blue;
    }
    
    Pixel()
    {
        _red = 0;
        _green = 0;
        _blue = 0;
    }
    
    Pixel(int redVal, int greenVal, int blueVal)
    {
        _red = redVal;
        _green = greenVal;
        _blue = blueVal;
    }
    
    bool operator==(Pixel otherPixel)
    {
        if((_red == otherPixel.get_red()) &&
            (_green == otherPixel.get_green()) &&
            (_blue == otherPixel.get_blue()) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};

#endif /* pixel_h */
