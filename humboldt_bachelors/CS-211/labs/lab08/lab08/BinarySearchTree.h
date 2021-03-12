#pragma once
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryNode.h"
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree
{
protected:
   BinaryNode<T>* _root = nullptr;
   
   bool find(BinaryNode<int>* start, const int& to_find)
    {
        //recursive base case answers the question,
        //"how do we know when we're done?"
        //base case 1: start's value matches to_find
        //base case 2: if children are null (not needed)
        //base case 3: if *start* is null
        if (start == nullptr)
        {
            return false;
        }

        //always do after null check to prevent runtime exceptions
        if (start->getValue() == to_find)
        {
            return true;
        }

        //recursive case: offload work to some subsegment of
        //our children
        return find(start->getLeft(), to_find)
            || find(start->getRight(), to_find);
    }

   virtual BinaryNode<T>* bstAdd(BinaryNode<T>* node, int value)
   {
      //null node indicates time to create a new item in our tree
      if (node == nullptr)
      {
         node = new BinaryNode<T>{ value };
         return node;
      }

      //if not null, send result to child based on relation of node's value
      //and new value
      if (value >= node->getValue())
      {
         node->setRight(bstAdd(node->getRight(), value));
      }
      else
      {
         node->setLeft(bstAdd(node->getLeft(), value));
      }

      //to maintian recursive correctness, always return a BinaryNode<T>*
      return node;
   }

   virtual BinaryNode<T>* bstRemove(BinaryNode<T>* node, int value)
   {
      //ALWAYS guard against a null ptr
      if (node == nullptr)
      {
         return nullptr;
      }

      if (node->getValue() == value)
      {
         //case #1: no children
         if (node->getLeft() == nullptr && node->getRight() == nullptr)
         {
            delete node;
            return nullptr;
         }
         else if (node->getLeft() == nullptr || node->getRight() == nullptr)
         {
            //a little verbose, but completely okay. Not any slower than
            //other method.
            /*BinaryNode<T>* child = node->getLeft();
            if (child == nullptr)
            {
               child = node->getRight();
            }*/
            //same thing as above
            BinaryNode<T>* child = node->getLeft() == nullptr
               ? node->getRight()
               : node->getLeft();
            delete node;
            return child;
         }
         else
         {
            //two children.  Grab rightmost in left subtree
            BinaryNode<T>* largest = node->getLeft();
            while (largest->getRight() != nullptr)
            {
               largest = largest->getRight();
            }

            //take largest's value
            node->setValue(largest->getValue());
            largest = bstRemove(node->getLeft(), largest->getValue());

            //reassign left side to be reconfiguration resulting from
            //delete
            node->setLeft(largest);
         }
      }
      else if (value > node->getValue())
      {
         BinaryNode<T>* result = bstRemove(node->getRight(), value);
         node->setRight(result);
      }
      else
      {
         BinaryNode<T>* result = bstRemove(node->getLeft(), value);
         node->setLeft(result);
      }
      return node;
   }


public:
   virtual void addElement(const T& value)
   {
      _root = bstAdd(_root, value);
   }

   virtual void removeElement(const T& value)
   {
      _root = bstRemove(_root, value);
   }
   
    bool checkAVL(BinaryNode<T>* node)
    {
        int leftHeight = 0, rightHeight = 0;

        if(node == nullptr)
        {
            return true;
        }

        rightHeight = node->height(node->getRight());
        leftHeight = node->height(node->getLeft());

        if(abs(leftHeight-rightHeight) > 1)
        {
            return false;
        }
        
        return checkAVL(node->getLeft()) && checkAVL(node->getRight());
    }

   /*
   This function returns true when the supplied binary search tree is AVL compliant
   (difference between left and right height is no more than 1).  True at all levels of the tree.
   */
   bool isAvl()
   {
      return checkAVL(_root);
   }
   
    void mergeFromRoot(BinaryNode<T>* node)
    {
        if(node == nullptr)
        {
            return;
        }
    
        addElement(node->getValue());
        
        mergeFromRoot(node->getLeft());
        mergeFromRoot(node->getRight());
        return;
    }
    
   /*
   Merges the supplied BST into the current BST in such a way that the BST property is maintained
   */
    void mergeTree(const BinarySearchTree<T>& other)
    {
        BinaryNode<T>* otherNode = other._root;
        mergeFromRoot(otherNode);
    }
    
    vector<int> getPath(int val)
    {
        BinaryNode<T>* node = _root;
        vector<int> path;
        path.push_back(_root->getValue());
        while(node != nullptr && node->getValue() != val)
        {
            if(val >= node->getValue())
            {
                path.push_back(node->getValue());
                node = node->getRight();
                
            }
            else
            {
                path.push_back(node->getValue());
                node = node->getLeft();
            }
        }
        path.push_back(val);
        return path;
    }

   /*
   For this function, determine the closest common ancestor of both values in the tree.  If one value is not in the tree, output "NONE".  For example, given the tree:
            10
        5       15
     1    6   11   17

     * Values 1 and 5 share the ancestor 5 (parent-child relationship).
     * Values 1 and 6 share the ancestor 5 (sibling relationship).
     * Values 6 and 11 share the ancestor 10 (grandparent relationship).
     Return -1 if there is no common ancestor.
   */
   
    int commonAncestor(int val1, int val2)
    {
        int result;
        if(find(_root, val1) == false)
        {
            return -1;
        }
        
        if(find(_root, val2) == false)
        {
            return -1;
        }
        vector<int> path1 = getPath(val1);
        vector<int> path2 = getPath(val2);
        for(auto item : path1)
        {
            for( auto item2 : path2)
            {
                if(item == item2)
                {
                    result = item;
                }
            }
        }
        return result;

    }
    
   
};

#endif // !BINARY_SEARCH_TREE_H
