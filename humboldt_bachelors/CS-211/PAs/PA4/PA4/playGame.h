#ifndef PLAYGAME_H
#define PLAYGAME_H
#pragma once
using namespace std;

void playGame(BinaryTree gameTree)
{
	bool keepPlaying = true;
    BinaryNode* gameNode = gameTree.getRoot();
	BinaryNode* startNode = gameNode;
	while (keepPlaying)
	{
		string response;
		while (gameNode != nullptr)
		{
			if (gameNode->isLeaf() == false)
			{
				cout << gameNode->getValue() << " (yes/no): ";
				getline(cin, response);
				while (response != "yes" && response != "no")
				{
					cout << "Invalid entry\n" << gameNode->getValue() << " (yes/no): ";
					getline(cin, response);
				}
				if (response == "yes")
				{
					gameNode = gameNode->getRightChild();
				}
				else if (response == "no")
				{
					gameNode = gameNode->getLeftChild();
				}
			}
			else
			{
				string guess = gameNode->getValue();
				guess = guess.substr(1, guess.length());
				cout << "Is it a " << guess << " (yes/no): ";
				getline(cin, response);
				while (response != "yes" && response != "no")
				{
					cout << "Invalid entry\n" << "Is it a " << guess << " (yes/no): ";
					getline(cin, response);
				}
				if (response == "yes")
				{
                    cout << "I guessed your animal!" << endl;
                    gameNode = gameNode->getRightChild();
				}
				else if (response == "no")
				{
                    string animal, question;
                    string ogAnimal = gameNode->getValue().substr(1, guess.length()-1);
                    cout << "Darn, I got it wrong. What is the correct answer?: ";
                    getline(cin, animal);
                    cout << "What is a yes/no question that I can use to differentiate between a " << ogAnimal << " and a " << animal << "?: ";
                    ogAnimal = "*" + ogAnimal + "?";
                    animal = "*" + animal + "?";
                    getline(cin, question);
                    cout << "Is the answer to this question yes or no?: ";
                    getline(cin, response);
                    while (response != "yes" && response != "no")
                    {
                        cout << "\nInvalid entry\n" << "Is the answer to this question yes or no?: ";
                        getline(cin, response);
                    }
                    
                    if(response == "no")
                    {
                        gameTree.addSet(animal, ogAnimal, question, gameNode);
                    }
                    else
                    {
                        gameTree.addSet(ogAnimal, animal, question, gameNode);
                    }
     
                    gameNode = nullptr;
                }
			}
		}
		cout << endl << "Would you like to play again? (yes/no): ";
		getline(cin, response);
		while (response != "yes" && response != "no")
		{
			cout << "Invalid entry\n" << "Would you like to play again? (yes/no): ";
			getline(cin, response);
		}
		if (response == "yes")
		{
			keepPlaying = true;
			gameNode = startNode;
		}
		else
		{
			keepPlaying = false;
		}
	}
}

#endif
