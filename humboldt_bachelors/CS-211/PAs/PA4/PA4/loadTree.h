#ifndef LOADTREE_H
#define LOADTREE_H
#pragma once
using namespace std;

BinaryTree loadNewTree(string treename)
{
	BinaryTree gameTree{};
	gameTree.setTreeName(treename);
	gameTree.addElement("*dog?");
	return gameTree;
}

BinaryTree loadTree()
{
	string response;
	bool responseGood = false;
	cout << "File Name: ";
	getline(cin, response);
	ifstream testOpen{ response };
	if (testOpen.is_open())
	{
		responseGood = true;
		testOpen.close();
	}
	while (!responseGood)
	{
		cout << "Invalid entry\n" << "File Name: ";
		getline(cin, response);
		ifstream testOpen{ response };
		if (testOpen.is_open())
		{
			responseGood = true;
		}
	}
	testOpen.close();

	BinaryTree gameTree{};
	gameTree.setTreeName(response);

	ifstream gameFile{ response };
	if (gameFile.is_open())
	{
		while (gameFile.good())
		{
			string item;
			getline(gameFile, item);
			gameTree.addElement(item);
		}
	}
	gameFile.close();
	cout << "..." << response << " loaded" << endl << endl;
	return gameTree;
}

#endif
