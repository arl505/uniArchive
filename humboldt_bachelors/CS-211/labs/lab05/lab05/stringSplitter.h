#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H

#include <string>
#include <vector>

using namespace std;

    vector<string> split(string text, string delimiter)
    {
        //vectors are dynamically expanding arrays
        vector<string> pieces;

        //find the first delimiter
        int location = text.find(delimiter);

        //we are starting at the beginning of our string
        int start = 0;

        //go until we have no more delimiters
        while(location != string::npos)
        {
            //add the current piece to our list of pieces
            string piece = text.substr(start, location - start);
            pieces.push_back(piece);

            //update our index markers for the next round
            start = location + 1;
            location = text.find(delimiter, start);
        }

        //at the end of our loop, we're going to have one trailing piece to take care of.
        //handle that now.
        string piece = text.substr(start, location - start);
        pieces.push_back(piece);
        return pieces;
    }


#endif
