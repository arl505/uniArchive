
/*
Github: github.com/arl505/CS-211
Assignment: Lab 05
Description: a postfix (sometimes called Reverse Polish) calculator
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: 1 hour 30 minutes
In completing this program, I received help from the following people: none
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <unordered_map>
#include "stringSplitter.h"

using namespace std;

int main()
{
    cout.precision(2);
    string expression;
    string entry = "y";
  
    
    
    while(entry != "n" && entry != "N")
    {
        stack<double> nums;
        int opCount = 0;
        int numsCount = 0;
        if(entry == "y" || entry == "Y")
        {
            double result;
            bool validEntry = true;
            cout << "Enter an expression to evaluate: ";
            getline(cin, expression);
            
            vector<string> results = split(expression, " ");
            for(auto item : results)
            {
                bool isDigit;
                for(int i = 0; i < item.length(); i ++)
                {
                    if(isdigit(item[i]))
                    {
                        isDigit = true;
                        
                    }
                    else
                    {
                        isDigit = false;
                        if((item[i]!='*')&&(item[i]!='/')&&(item[i]!='-')&&(item[i]!='+'))
                        {
                            validEntry = false;
                        }
                    }
                }
                
                if(isDigit && item != "")
                {
                    nums.push(stoi(item));
                    numsCount++;
                }
                
                else if (item.length() == 1 && item == "+")
                {
                    opCount++;
                    if (nums.size() > 1)
                    {
                        double num1, num2, answer;
                        num1 = nums.top();
                        nums.pop();
                        num2 = nums.top();
                        nums.pop();
                        answer = num1 + num2;
                        nums.push(answer);
                    }

                }
                else if (item.length() == 1 && item == "-")
                {
                    opCount++;
                    if (nums.size() > 1)
                    {
                        double num1, num2, answer;
                        num1 = nums.top();
                        nums.pop();
                        num2 = nums.top();
                        nums.pop();
                        answer = num2 - num1;
                        nums.push(answer);
                    }

                }
                else if (item.length() == 1 && item == "/")
                {
                    opCount++;
                    if (nums.size() > 1)
                    {
                        double num1, num2, answer;
                        num1 = nums.top();
                        nums.pop();
                        num2 = nums.top();
                        nums.pop();
                        answer = num2 / num1;
                        nums.push(answer);
                    }

                }
                else if (item.length() == 1 && item == "*")
                {
                    opCount++;
                    if (nums.size() > 1)
                    {
                        double num1, num2, answer;
                        num1 = nums.top();
                        nums.pop();
                        num2 = nums.top();
                        nums.pop();
                        answer = num1 * num2;
                        nums.push(answer);
                    }

                }
            }
            
            
            if(nums.size() == 1 && validEntry && (opCount+1 == numsCount))
            {
                cout.precision(2);
                cout << fixed;
                cout << "Result: " << nums.top() << endl;
                nums.pop();
                cout << "Continue (y/n)?: ";
                getline(cin, entry);
            }
            else
            {
                cout << "Invalid Entry" << endl;
                cout << "Continue (y/n)?: ";
                getline(cin, entry);
            }
        }
        else
        {
            cout << "Invalid Entry" << endl;
            cout << "Continue (y/n)?: ";
            getline(cin, entry);
        }
    }
}




