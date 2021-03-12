#pragma once
#ifndef AvlTree_h
#define AvlTree_h
#include "BinarySearchTree.h"
#include "AvlNode.h"

template <typename T>
class AvlTree : public BinarySearchTree<T>
{
private:

    AvlNode<T>* rotateRight(AvlNode<T>* node)
    {
        AvlNode<T>* new_root = node->getLeft();
        node->setLeft(new_root->getRight());
        new_root->setRight(node);
        return setHeight(new_root);
    }
    
    AvlNode<T>* rotateLeft(AvlNode<T>* node)
    {
        AvlNode<T>* new_root = node->getRight();
        node->setRight(new_root->getLeft());
        new_root->setLeft(node);
        return setHeight(new_root);
    }

    AvlNode<T>* balance(AvlNode<T>* node)
    {
        if (node == nullptr)
        {
            return node;
        }
        int balance_factor = node->getBalanceFactor();
        if(balance_factor > 1)
        {
            if(node->getRight()->getBalanceFactor() < 0)
            {
                node->setRight(rotateRight(node->getRight()));
            }
            return rotateLeft(node);
            
        }
        else if(balance_factor < -1)
        {
            if(node->getLeft()->getBalanceFactor() < 0)
            {
                node->setLeft(rotateLeft(node->getLeft()));
            }
            return rotateRight(node);
        }
        
        return node;
    }
    
    AvlNode<T>* setHeight(AvlNode<T>* node)
    {
        if(node == nullptr)
        {
            return node;
        }
        
        AvlNode<T>* left = node->getLeft();
        AvlNode<T>* right = node->getRight();
        int left_height = (left == nullptr) ? (-1) : (left->getHeight());
        int right_height = (right == nullptr) ? (-1) : (right->getHeight());
        node->setHeight(max(left_height, right_height) + 1);
        if(node->getBalanceFactor() > 1 || node->getBalanceFactor() < -1)
        {
            // unbalanced! Perform rotations
            return balance(node);
        }
        return node;
    }
    
public:
    virtual BinaryNode<T>* bstAdd(BinaryNode<T>* node, const T& value)
    {
        if(node == nullptr)
        {
            node = new AvlNode<T>{value};
            return node;
        }
        
        AvlNode<T>* result = dynamic_cast<AvlNode<T>*>(BinarySearchTree<T>::bstAdd(node, value));
        
        return setHeight(result);
    }
};

#endif /* AvlTree_h */
