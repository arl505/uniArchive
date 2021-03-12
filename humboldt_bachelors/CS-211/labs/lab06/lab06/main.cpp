/*
Github: github.com/arl505/CS-211
Assignment: Lab 06
Description: idk?
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: ~2 hours
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
#include "binaryNode.h"
using namespace std;

bool find(BinaryNode<int>* start, const int& to_find)
{
    if(start == nullptr)
    {
        return false;
    }
    if(start->getValue() == to_find)
    {
        return true;
    }
    
    return find(start->getLeft(), to_find) || find(start->getRight(), to_find);
    
}

int size(BinaryNode<int>* start)
{
    if(start == nullptr)
    {
        return 0;
    }
    return 1 + size(start->getLeft()) + size(start->getRight());
}

int height(BinaryNode<int>* start)
{
    if(start == nullptr)
    {
        return -1;
    }
    
    return 1 + max(height(start->getLeft()), height(start->getRight()));
}

bool isFull(BinaryNode<int>* start)
{
    if(start == nullptr)
    {
        return true;
    }
    if(start->getLeft() == nullptr && start->getRight() != nullptr)
    {
        return false;
    }
    else if(start->getLeft() != nullptr && start->getRight() == nullptr)
    {
        return false;
    }
    
    return (isFull(start->getLeft()) && isFull(start->getRight()));
}

int main()
{
    cout << boolalpha;
    BinaryNode<int>* root = new BinaryNode<int>{5};
    root->setLeft(new BinaryNode<int>{12});
    root->setRight(new BinaryNode<int>{4});
    root->getLeft()->setLeft(new BinaryNode<int>{11});
    root->getLeft()->setRight(new BinaryNode<int>{18});
    root->getRight()->setLeft(new BinaryNode<int>{10});
    root->getRight()->setRight(new BinaryNode<int>{7});
    
    root->getRight()->getLeft()->setLeft(new BinaryNode<int>{3});
    root->getRight()->getLeft()->setRight(new BinaryNode<int>{9});
    
    root->getRight()->getRight()->setRight(new BinaryNode<int>{15});
    
    root->getRight()->getRight()->getRight()->setLeft(new BinaryNode<int>{20});
    root->getRight()->getRight()->getRight()->setRight(new BinaryNode<int>{22});
}
