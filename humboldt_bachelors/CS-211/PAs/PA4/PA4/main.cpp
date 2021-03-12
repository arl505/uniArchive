
/*
Github: github.com/arl505/CS-211
Assignment: PA 4
Description: a "yes/no" animal guessing game using a binary tree
Author: Alec Levin
HSU ID: 0125-44022
Completion Time: 10 hours
In completing this program, I received help from the following people: none
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "binaryNode.h"
#include "binaryTree.h"
#include "playGame.h"
#include "loadTree.h"
#include "outputTree.h"
using namespace std;

int main()
{
	string response;
	bool keepGuessing = true;
	
	cout << "***Animal Guessing Game***\n" << endl;
	
	while (keepGuessing)
	{
		cout << "Load file? (yes/no): ";
		getline(cin, response);
		while (response != "yes" && response != "no")
		{
			cout << "Invalid entry\n" << "Load file? (yes/no): ";
			getline(cin, response);
		}
		if (response == "yes")
		{
			BinaryTree gameTree = loadTree();
			playGame(gameTree);
			vector<string> results = outputTree(gameTree.getRoot());
			toFile(gameTree.getName(), results);
		}
		else
		{
			cout << "Save results to: ";
			getline(cin, response);
			BinaryTree gameTree = loadNewTree(response);
			playGame(gameTree);
			vector<string> results = outputTree(gameTree.getRoot());
			toFile(gameTree.getName(), results);
		}

		cout << "Would you like to play a different game? (yes/no): ";
		getline(cin, response);
		while (response != "yes" && response != "no")
		{
			cout << "Invalid entry\n" << "Would you like to play a different game? (yes/no): ";
			getline(cin, response);
		}
		if (response == "yes")
		{
			keepGuessing = true;
		}
		else
		{
			keepGuessing = false;
		}
	}
}
