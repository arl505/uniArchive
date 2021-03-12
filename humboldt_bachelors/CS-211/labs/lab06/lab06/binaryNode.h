//
//  binaryNode.h
//  lab06
//
//  Created by Alec Levin on 3/4/19.
//  Copyright © 2019 arlevin.org. All rights reserved.
//

#ifndef binaryNode_h
#define binaryNode_h

template <typename T>
class BinaryNode
{
private:
    T _value;
    BinaryNode* _left = nullptr;
    BinaryNode* _right = nullptr;
public:
    
    BinaryNode(const T& value)
    {
        _value = value;
    }
    
    BinaryNode()
    {
        
    }
    
    BinaryNode* getLeft(void)
    {
        return _left;
    }
    
    void setLeft(BinaryNode* left)
    {
        _left = left;
    }
    
    BinaryNode* getRight(void)
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
    
};

#endif /* binaryNode_h */
