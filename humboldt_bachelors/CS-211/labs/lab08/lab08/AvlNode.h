#pragma once
#ifndef AvlNode_h
#define AvlNode_h
#include "BinaryNode.h"

template <typename T>
class AvlNode : public BinaryNode<T>
{
private:
    int _height = 0;

public:
    AvlNode() : BinaryNode<T>()
    {
        
    }
    
    AvlNode(const T& value) : BinaryNode<T>(value)
    {
        
    }
    
    int getHeight() const
    {
        return _height;
    }
    
    void setHeight(const int & h)
    {
        _height = h;
    }
    
    AvlNode* getLeft()
    {
        return dynamic_cast<AvlNode<T>*>(BinaryNode<T>::getLeft());
    }
    
    AvlNode* getRight()
    {
        return dynamic_cast<AvlNode<T>*>(BinaryNode<T>::getRight());
    }
    
    
    int getBalanceFactor()
    {
        int right_height;
        int left_height;
        if(getRight() != nullptr)
        {
             right_height = getRight()->getHeight();
        }
        else
        {
            right_height = -1;
        }
        
        if(getLeft() != nullptr)
        {
            left_height = getLeft()->getHeight();
        }
        else
        {
            left_height = -1;
        }
        return right_height - left_height;
    }

};

#endif /* AvlNode_h */
