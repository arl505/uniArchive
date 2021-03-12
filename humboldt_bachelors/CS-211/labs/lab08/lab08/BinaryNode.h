#pragma once
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <typename T>
class BinaryNode
{
protected:
    T _value;
    BinaryNode* _left = nullptr;
    BinaryNode* _right = nullptr;
public:

    //constructor
    BinaryNode(const T& value)
    {
        _value = value;
    }

    //empty constructor
    BinaryNode()
    {
        //no clue what _value will be
    }

    BinaryNode* getLeft()
    {
        return _left;
    }

    void setLeft(BinaryNode* left)
    {
        _left = left;
    }

    BinaryNode* getRight()
    {
        return _right;
    }

    void setRight(BinaryNode* right)
    {
        _right = right;
    }

    T& getValue()
    {
        return _value;
    }

    const T& getValue() const
    {
        return _value;
    }

    void setValue(const T& value)
    {
        _value = value;
    }
    
    int height(BinaryNode<T>* start)
    {
        if (start == nullptr)
        {
            return -1;
        }

        //recursive calls to child nodes
        int left_height = height(start->getLeft());
        int right_height = height(start->getRight());

        //assume right side is smaller, check assumption
        int height = right_height;
        if (left_height > right_height)
        {
            height = left_height;
        }
        return 1 + height;
    }
    
    virtual ~BinaryNode()
    {
    
    }
};



#endif
