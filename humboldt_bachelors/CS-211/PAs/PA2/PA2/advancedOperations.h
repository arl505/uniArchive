#ifndef advancedOperations_h
#define advancedOperations_h

vector<Pixel> flipHorizontally(vector<Pixel> pixels, int length, int height)
{
    
    vector <Pixel> results;
    vector<Pixel> row;
    
    // loop through however many rows (aka height)
    for(int i = 0; i < height; i++)
    {
        // loop through each row for however long the row is (aka length)
        for(int j = 0; j < length; j++)
        {
            // from left to right add the pixels of the row to a row vector
            int place = j + (i * length);
            row.push_back(pixels.at(place));
        }
            
        // unload the row in opposite order (aka flip it)
        for(int c = row.size()-1; c >= 0; c--)
        {
            results.push_back(row.at(c));
        }
        
        // make sure we clear our current row before looping back and processing the next one
        row.clear();
        
    }
    return results;
}

vector<Pixel> flipVertically(vector<Pixel> pixels, int length, int height)
{
    
    vector <Pixel> results;
    vector<Pixel> row;
    vector<vector<Pixel>> rows;
    
    // loop through however many rows (aka height)
    for(int i = 0; i < height; i++)
    {
        // loop through each row for however long the row is (aka length)
        for(int j = 0; j < length; j++)
        {
            // from left to right add the pixels of the row to a row vector
            int place = j + (i * length);
            row.push_back(pixels.at(place));
        }
        
        rows.push_back(row);
        
        // make sure we clear our current row before looping back and processing the next one
        row.clear();
    }
    for(int i = rows.size()-1; i >= 0; i--)
    {
        for(int j = 0; j < rows.at(i).size(); j++)
        {
            results.push_back(rows.at(i).at(j));
        }
    }
    return results;
}

vector<Pixel> rotate(vector<Pixel> pixels, int oldNumColumns, int oldNumRows)
{
    vector <Pixel> results;
    
    int newNumColumns = oldNumRows;
    int newNumRows = oldNumColumns;
    vector<vector<Pixel>> columns;
    
    // initialize empty columns of pixels
    for(int i = 0; i < newNumColumns; i++)
    {
        vector<Pixel> emptyColumn;
        columns.push_back(emptyColumn);
    }
    
    // we are going to loop through our current pixels row by row
    // and add each row to our columns list (from the back of the columns vector to the front),
    // but leaving the pixels in order of the row such that the first pixel in the row is the first pixel
    // thats now at the top of the column
    for(int i = 0; i < oldNumRows; i++)
    {
        // loop through each row for however long the row is (aka length)
        for(int j = 0; j < oldNumColumns; j++)
        {
            // current place in original pixels vector
            int place = j + (i * oldNumColumns);
            
            // add current pixel to appropriate column
            columns.at((newNumColumns-i)-1).push_back(pixels.at(place));
        }
    }
    
    
    // now we are going to loop through and build our results one row at a time.
    // For each place in our row we need to grab the pixel from a different and appropriate column
    // based off our row place.
    for(int heightPlace = 0; heightPlace < newNumRows; heightPlace++)
    {
        for(int rowPlace = 0; rowPlace < newNumColumns; rowPlace++)
        {
            results.push_back(columns.at(rowPlace).at(heightPlace));
        }
    }
    return results;
}

vector<Pixel> blur(vector<Pixel> pixels, int numColumns, int numRows)
{
    vector <Pixel> results;
    Pixel curr;
    int pixelVal1, pixelVal2, pixelVal3, setPixelVal;
    
  // we already have the pixels in a single dimensional structure that
  // will allow us to easily go row by row because when iterating row by row,
  // adjacent pixels are always just +1. So iterate row by row and do the work
  // on each pixel, then push the pixel on to the results vector
    for(int rowNum = 0; rowNum < numRows; rowNum++)
    {
        for(int rowPlace = 0; rowPlace < numColumns; rowPlace++)
        {
            int place = (numColumns * rowNum) + rowPlace;
            curr = pixels.at(place);
            if(rowPlace == 0)
            {
                pixelVal1 = curr.get_red();
                pixelVal2 = pixels.at(place + 1).get_red();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_red(setPixelVal);
                
                pixelVal1 = curr.get_green();
                pixelVal2 = pixels.at(place + 1).get_green();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_green(setPixelVal);
                
                pixelVal1 = curr.get_blue();
                pixelVal2 = pixels.at(place + 1).get_blue();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_blue(setPixelVal);
            }
            else if(rowPlace == (numColumns-1))
            {
                pixelVal1 = curr.get_red();
                pixelVal2 = pixels.at(place - 1).get_red();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_red(setPixelVal);
                
                pixelVal1 = curr.get_green();
                pixelVal2 = pixels.at(place - 1).get_green();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_green(setPixelVal);
                
                pixelVal1 = curr.get_blue();
                pixelVal2 = pixels.at(place - 1).get_blue();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_blue(setPixelVal);
            }
            else
            {
                pixelVal1 = curr.get_red();
                pixelVal2 = pixels.at(place + 1).get_red();
                pixelVal3 = pixels.at(place - 1).get_red();
                setPixelVal = (pixelVal1 + pixelVal2 + pixelVal3) / 3;
                curr.set_red(setPixelVal);
                
                pixelVal1 = curr.get_green();
                pixelVal2 = pixels.at(place + 1).get_green();
                pixelVal3 = pixels.at(place - 1).get_green();
                setPixelVal = (pixelVal1 + pixelVal2 + pixelVal3) / 3;
                curr.set_green(setPixelVal);
                
                pixelVal1 = curr.get_blue();
                pixelVal2 = pixels.at(place + 1).get_blue();
                pixelVal3 = pixels.at(place - 1).get_blue();
                setPixelVal = (pixelVal1 + pixelVal2 + pixelVal3) / 3;
                curr.set_blue(setPixelVal);
            }
            results.push_back(curr);
        }
    }
    

    // set up empty columns
    vector<vector<Pixel>> columns;
    for(int i = 0; i < numColumns; i++)
    {
        vector<Pixel> emptyColumn;
        columns.push_back(emptyColumn);
    }
    
    
    // load pixels in row by row into their appropriate column from the results vector
    for(int rowNum = 0; rowNum < numRows; rowNum++)
    {
        for(int rowPlace = 0; rowPlace < numColumns; rowPlace++)
        {
            int place = (numColumns * rowNum) + rowPlace;
            columns.at(rowPlace).push_back(results.at(place));
        }
    }
    
    // iterate through and average the pixels that are now iterated through by column instead of by row
    for(int columnNum = 0; columnNum < columns.size(); columnNum++)
    {
        for(int columnPlace = 0; columnPlace < columns.at(columnNum).size(); columnPlace++)
        {
            curr = columns.at(columnNum).at(columnPlace);
            if(columnPlace == 0)
            {
                pixelVal1 = curr.get_red();
                pixelVal2 = columns.at(columnNum).at(columnPlace+1).get_red();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_red(setPixelVal);
                
                pixelVal1 = curr.get_green();
                pixelVal2 = columns.at(columnNum).at(columnPlace+1).get_green();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_green(setPixelVal);
                
                pixelVal1 = curr.get_blue();
                pixelVal2 = columns.at(columnNum).at(columnPlace+1).get_blue();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_blue(setPixelVal);
            }
            else if(columnPlace == (columns.at(columnNum).size() -1))
            {
                pixelVal1 = curr.get_red();
                pixelVal2 = columns.at(columnNum).at(columnPlace-1).get_red();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_red(setPixelVal);
                
                pixelVal1 = curr.get_green();
                pixelVal2 = columns.at(columnNum).at(columnPlace-1).get_green();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_green(setPixelVal);
                
                pixelVal1 = curr.get_blue();
                pixelVal2 = columns.at(columnNum).at(columnPlace-1).get_blue();
                setPixelVal = (pixelVal1 + pixelVal2) / 2;
                curr.set_blue(setPixelVal);
            }
            else
            {
                pixelVal1 = curr.get_red();
                pixelVal2 = columns.at(columnNum).at(columnPlace-1).get_red();
                pixelVal3 = columns.at(columnNum).at(columnPlace+1).get_red();
                setPixelVal = (pixelVal1 + pixelVal2 + pixelVal3) / 3;
                curr.set_red(setPixelVal);
                
                pixelVal1 = curr.get_green();
                pixelVal2 = columns.at(columnNum).at(columnPlace-1).get_green();
                pixelVal3 = columns.at(columnNum).at(columnPlace+1).get_green();
                setPixelVal = (pixelVal1 + pixelVal2 + pixelVal3) / 3;
                curr.set_green(setPixelVal);
                
                pixelVal1 = curr.get_blue();
                pixelVal2 = columns.at(columnNum).at(columnPlace-1).get_blue();
                pixelVal3 = columns.at(columnNum).at(columnPlace+1).get_blue();
                setPixelVal = (pixelVal1 + pixelVal2 + pixelVal3) / 3;
                curr.set_blue(setPixelVal);
            }
            columns.at(columnNum).at(columnPlace) = curr;
        }
    }
    
    // clear the results vector because we now have our pixels in our columns
    // data structure. Clear the results and then appropriately load the pixels from
    // columns into results.
    results.clear();
    
    for(int rowNum = 0; rowNum < numRows; rowNum++)
    {
        for(int rowPlace = 0; rowPlace < numColumns; rowPlace++)
        {
            results.push_back(columns.at(rowPlace).at(rowNum));
        }
    }
    return results;
}

vector<Pixel> pixelate(vector<Pixel> pixels, int numColumns, int numRows)
{
    vector <Pixel> results;
    int dvalue = 5;
    
    // we have pixels in 1-d structure, we want them in 2-d list of rows
    vector<vector<Pixel>> rows;
    
    // initialize 2-d list of rows with empty row vectors
    for(int i = 0; i < numRows; i++)
    {
        vector<Pixel> emptyRow;
        rows.push_back(emptyRow);
    }
    
    // fill our rows
    for(int rowNum = 0; rowNum < numRows; rowNum++)
    {
        for(int rowPlace = 0; rowPlace < numColumns; rowPlace++)
        {
            int place = (rowNum * numColumns) + rowPlace;
            rows.at(rowNum).push_back(pixels.at(place));
        }
    }
    
    Pixel reference;
    
    // for every row
    for(int rowNum = 0; rowNum < numRows; rowNum += dvalue)
    {
        // for every pixel in every row
        for(int rowPlace = 0; rowPlace < rows.at(rowNum).size(); rowPlace += dvalue)
        {
            reference = rows.at(rowNum).at(rowPlace);
            
            // for each row after the current row for as far as the dvalue says
            for(int currRow = rowNum; currRow < (rowNum + dvalue); currRow++)
            {
                // for as many pixels after the current pixel as the dvalue says
                for(int currPlace = rowPlace; currPlace < (rowPlace + dvalue); currPlace++)
                {
                    if(currRow < rows.size() && currPlace < rows.at(currRow).size())
                    {
                        // set the pixel equal to the reference pixel
                        rows.at(currRow).at(currPlace) = reference;
                    }
                }
            }
        }
    }
    
    // for each row
    for(int rowNum = 0; rowNum < numRows; rowNum++)
    {
        // for each pixel in each row
        for(int rowPlace = 0; rowPlace < numColumns; rowPlace++)
        {
            // add pixel to results
            results.push_back(rows.at(rowNum).at(rowPlace));
        }
    }
    return results;
}

#endif /* advancedOperations_h */
