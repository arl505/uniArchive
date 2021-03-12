#ifndef runCompression_h
#define runCompression_h

string getPrefix(string fileName)
{
    string filePrefix = "";
    bool atSuffix = false;
    for(int i = 0; i < fileName.length() && !atSuffix; i++)
    {
        if(fileName[i] != '.')
        {
            filePrefix += fileName[i];
        }
        else
        {
            atSuffix = true;
        }
    }
    return filePrefix;
}

string intToBinary(int num)
{
    string binaryNum = "";
    while (num > 0)
    {
        binaryNum = to_string(num % 2) + binaryNum;
        num /= 2;
    }
    if (binaryNum == "")
    {
        return "0";
    }
    return binaryNum;
}

void runCompression(string fileName)
{
    // load file prefix ie 'happy' in 'happy.txt'
    string filePrefix = getPrefix(fileName);
    
    // load a hashtable of words and frequencies
    unordered_map<string, int> words = loadMap(fileName);
    priority_queue<pair<int, string>> pq;

    for(auto word : words)
    {
    
        // push each word onto a pq
        pq.push(make_pair(word.second, word.first));
    }
    
    unordered_map<string, string> mappings;
    int counter = 0;
    while(!pq.empty())
    {
    
        // pop from pq, for each word: add to mapping with its numerical rank in the queue
        pair<int, string> topWord = pq.top();
        mappings[topWord.second] = intToBinary(counter);
        counter++;
        pq.pop();
    }
    
    
    ofstream outputCodes{filePrefix + ".codes.txt"};
    for(auto item : mappings)
    {
        // for each word, output the word and binary value it maps to
        outputCodes << item.first << ":" << item.second << endl;
    }
    outputCodes.close();
    
    ofstream outputCompressed{filePrefix + ".compressed.txt"};
    ifstream inputFile{fileName};
    if(inputFile.is_open())
    {
        while(inputFile.good())
        {
            string currWord;
            inputFile >> currWord;
            
            // for each word in OG file, output the binary value it maps to
            // if it isn't the last word, add a space at the end, if it is last, no space at end
            if(inputFile.good())
            {
                outputCompressed << mappings[currWord] << " ";
            }
            else
            {
                outputCompressed << mappings[currWord];
            }
        }
    }
    inputFile.close();
    outputCompressed.close();
    
    cout << "Encoded results written to: " + filePrefix + ".compressed.txt" << endl;
    cout << "Codes file written to: " + filePrefix + ".codes.txt" << endl;
}

#endif /* runCompression_h */
