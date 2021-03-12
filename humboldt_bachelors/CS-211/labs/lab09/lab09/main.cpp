#include <unordered_map> //hash table
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;


void concordance(string text)
{
	//TODO
    ifstream file{text};
    unordered_map<string, int> wordFrequencies;
    if(file.is_open())
    {
        while(file.good())
        {
            string word;
            file >> word;
            wordFrequencies[word]++;
        }
    }
    cout << "***concordance tests***" << endl;
    for(auto item : wordFrequencies)
    {
        cout << item.first << " appears " << item.second << " times" << endl;
    }
}

bool hasUniqueChars(string text)
{
    unordered_map<char, int> letterFrequencies;
    for(int i = 0; i < text.length(); i++)
    {
        letterFrequencies[text[i]]++;
        if(letterFrequencies[text[i]] > 1)
        {
            return false;
        }
    }
	return true;
}

bool isAnagram(string first, string second)
{
	//TODO
    unordered_map<char, int> firstFrequencies;
    for(int i = 0; i < first.length(); i++)
    {
        firstFrequencies[first[i]]++;
    }
    
    unordered_map<char, int> secondFrequencies;
    for(int i = 0; i < second.length(); i++)
    {
        secondFrequencies[second[i]]++;
    }

	return (firstFrequencies == secondFrequencies);
}

string mostCommonSubstring(string text, int size)
{
    if(size > text.length() || size == 0)
    {
        return "NULL";
    }

    unordered_map<string, int> sequenceFrequencies;
    int maxSize = -1;
    string maxString = "";
    for(int i = 0; i <= text.length() - size; i++)
    {
        string currWord = "";
        int currPlace = i;
        for(int j = 0; j < size; j++)
        {
            currWord += text[currPlace];
            currPlace++;
        }
        sequenceFrequencies[currWord]++;
        if(maxString == "" || maxSize < sequenceFrequencies[currWord])
        {
            maxString = currWord;
            maxSize = sequenceFrequencies[currWord];
        }
    }
    return maxString;
}

int main(void)
{
	
	cout << boolalpha;

   //TODO: open test_file, create concordance
   concordance("test_file.txt");

   //unique chars test
	cout << endl << "***unique characters test***" << endl;

	//test case #1
	cout << "abcde: " <<
		hasUniqueChars("abcde") 
		<< " (expected: true)"
		<< endl;
 
	//test case #2:
	cout << "aaaa: " <<
		hasUniqueChars("aaaa")
		<< " (expected: false)"
		<< endl;

	//test case #3:
	cout << "(empty string): " <<
		hasUniqueChars("")
		<< " (expected: true)"
		<< endl;

	//test case #4:
	cout << "abcdea: " <<
		hasUniqueChars("abcdea")
		<< " (expected: false)"
		<< endl;

	//anagram tests
	cout << endl << endl;
	cout << "***anagram tests***" << endl;

	//test case #1:
	cout << "tab, bat: " <<
		isAnagram("tab", "bat")
		<< " (expected: true)"
		<< endl;

	//test case #2
	cout << "bat, tab: " <<
		isAnagram("bat", "tab")
		<< " (expected: true)"
		<< endl;

	//test case #3
	cout << "(empty), (empty): " <<
		isAnagram("", "")
		<< " (expected: true)"
		<< endl;

	//test case #4
	cout << "dog, cat: " <<
		isAnagram("dog", "cat")
		<< " (expected: false)"
		<< endl;

	//test case #5
	cout << "castles, castle: " <<
		isAnagram("castles", "castle")
		<< " (expected: false)"
		<< endl;

	//test case #6
	cout << "bat, tabb: " <<
		isAnagram("bat", "tabb")
		<< " (expected: false)"
		<< endl;

	//most common substring
	cout << endl << endl << "***Most common substring***" << endl;

	//test case #1
	cout << "abcabcdefdefabc. 3: " <<
		mostCommonSubstring("abcabcdefdefabc", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #2
	cout << "defdefabcabc, 3: " <<
		mostCommonSubstring("defdefabcabc", 3)
		<< " (expected: def)"
		<< endl;

	//test case #3
	cout << "aaabbcccc, 1: " <<
		mostCommonSubstring("aaabbcccc", 1)
		<< " (expected: c)"
		<< endl;

	//test case #4
	cout << "abcdefhijklmnopqrstuvwxyz, 4: " <<
		mostCommonSubstring("abcdefhijklmnopqrstuvwxyz", 4)
		<< " (expected: abcd)"
		<< endl;

	//test case #5
	cout << "abc, 5: " <<
		mostCommonSubstring("abc", 5)
		<< " (expected: NULL)"
		<< endl;

	//test case #6
	cout << "(Empty), 1: " <<
		mostCommonSubstring("", 1)
		<< " (expected: NULL)"
		<< endl;

	//test case #7
	cout << "abcabcab, 3: " <<
		mostCommonSubstring("abcabcab", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #8
	cout << "abcabcab, 0: " <<
		mostCommonSubstring("abcabcab", 0)
		<< " (expected: NULL)"
		<< endl;

	return 0;
}
