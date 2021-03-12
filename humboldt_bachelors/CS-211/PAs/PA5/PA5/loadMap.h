#ifndef loadMap_h
#define loadMap_h

using namespace std;

unordered_map<string, int> loadMap(string fileName)
{
    unordered_map<string, int> words;
    
    ifstream file{fileName};
    if(file.is_open())
    {
        while(file.good())
        {
            string currWord;
            file >> currWord;
            if(!currWord.empty())
            {
                words[currWord]++;
            }
        }
    }
    file.close();
    return words;
}

#endif /* loadMap_h */
