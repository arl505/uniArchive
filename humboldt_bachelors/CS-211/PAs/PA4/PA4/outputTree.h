#ifndef OUTPUTTREE_H
#define OUTPUTTREE_H

using namespace std;

vector<string> outputTree(BinaryNode* node)
{
	vector<string> results;
	if (node == nullptr)
	{
		return results;
	}

	vector<string> leftResults = outputTree(node->getLeftChild());
	vector<string> rightResults = outputTree(node->getRightChild());
	results.push_back(node->getValue());
	for (auto item : leftResults)
	{
		results.push_back(item);
	}
	for (auto item : rightResults)
	{
		results.push_back(item);
	}
	return results;
}

void toFile(string filename, vector<string> results)
{
	ofstream outputFile{ filename };
	for (auto item : results)
	{
		outputFile << item << "\n";
	}
	outputFile.close();
}
#pragma once
#endif
