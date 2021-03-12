#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <utility>
using namespace std;
class BinaryNode
{
private:

    //underlying value in our node
    string _value;

    //a pointer to our left child
    BinaryNode *_left_child;

    //a pointer to our right child
    BinaryNode *_right_child;

    //disallow copy constructors
    BinaryNode(const BinaryNode &other);
    BinaryNode(BinaryNode &&other);
    
    //disallow assignment operator
    BinaryNode &operator=(const BinaryNode &other);
    BinaryNode &operator=(BinaryNode &&other);
    
    bool _leaf;

public:

    //default constructor
    BinaryNode()
    {
        _left_child = nullptr;
        _right_child = nullptr;
        _leaf = false;
    }

    BinaryNode(string value)
    {
        _left_child = nullptr;
        _right_child = nullptr;
        _value = value;
        _leaf = false;
    }

    //constructor that takes in two binary nodes to set as left and right
    BinaryNode(BinaryNode *left, BinaryNode *right)
    {
        _left_child = left;
        _right_child = right;
        _leaf = false;
    }

    virtual bool isLeaf()
    {
        return _leaf;
    }

    void setLeaf(bool leafVal)
    {
        _leaf = leafVal;
    }

    BinaryNode *getLeftChild()
    {
        return _left_child;
    }

    const BinaryNode *getLeftChild() const
    {
        return _left_child;
    }

    void setLeftChild(BinaryNode *left)
    {
        _left_child = left;
    }

    BinaryNode *getRightChild()
    {
        return _right_child;
    }

    const BinaryNode *getRightChild() const
    {
        return _right_child;
    }

    void setRightChild(BinaryNode *right)
    {
        _right_child = right;
    }

    void setValue(string value)
    {
        _value = value;
    }

    string &getValue()
    {
        return _value;
    }

    const string &getValue() const
    {
        return _value;
    }
};

#endif
