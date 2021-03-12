#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;

class BinaryTree
{
private:
    BinaryNode* _root = nullptr;
	string _treeName;
    int size = 0;

protected:
   BinaryNode* addNode(BinaryNode* node, string value)
   {
        //null node indicates time to create a new item in our tree
        if (node == nullptr)
        {
            node = new BinaryNode{ value };
            
            if(value[0] == '*')
            {
                node->setLeaf(true);
            }
            
            return node;
        }
        else
        {
            if(false == isFull(node))
            {
                node->setLeftChild(addNode(node->getLeftChild(), value));
            }
            else
            {
                node->setRightChild(addNode(node->getRightChild(), value));
            }
        }
        return node;
    }
    
public:
    BinaryNode* getRoot()
    {
        return _root;
    }

    void addElement(string value)
    {
        _root = addNode(_root, value);
    }

    bool checkFullness(BinaryNode* node)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->getLeftChild() == nullptr && node->getRightChild() != nullptr)
        {
            return false;
        }
        else if (node->getLeftChild() != nullptr && node->getRightChild() == nullptr)
        {
            return false;
        }
        else if (node->getLeftChild() == nullptr && node->getRightChild() == nullptr && node->getValue()[0] != '*')
        {
            return false;
        }
        return checkFullness(node->getLeftChild()) && checkFullness(node->getRightChild());
    }

    bool isFull(BinaryNode* node)
    {
        if (_root == nullptr || node->getLeftChild() == nullptr)
        {
            return false;
        }
        return checkFullness(node->getLeftChild());
    }

	string getName(void)
	{
		return _treeName;
	}
	void setTreeName(string treeName)
	{
		_treeName = treeName;
	}
 
    BinaryNode* addSet(string noAnimal, string yesAnimal, string question, BinaryNode* node)
    {
        BinaryNode* newRightNode = new BinaryNode;
        newRightNode->setValue(yesAnimal);
        newRightNode->setLeaf(true);
        
        BinaryNode* newLeftNode = new BinaryNode;
        newLeftNode->setValue(noAnimal);
        newLeftNode->setLeaf(true);
        
        node->setValue(question);
        node->setLeaf(false);
        node->setRightChild(newRightNode);
        node->setLeftChild(newLeftNode);
        return node;
    }

};

#endif
