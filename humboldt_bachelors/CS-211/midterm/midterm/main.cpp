#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include "binaryNode.h"
#include "linkedList.h"
#include "treeNode.h"
using namespace std;

int findNthSmallest(vector<int> nums, int n)
{
    if(n < 1 || n > nums.size())
    {
        return -1;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto item : nums)
    {
        pq.push(item);
    }
    
    int result = 0;
    for(int i = 1; i <= n; i++)
    {
        result = pq.top();
        pq.pop();
    }
    return result;
}

void reverseOrderTraversal(BinaryNode<int>* node)
{
    if(node == nullptr)
    {
        return;
    }
    reverseOrderTraversal(node->_right);
    cout << node->_value << endl;
    reverseOrderTraversal(node->_left);
}

LinkedList* reverseLinkedList(LinkedList* list)
{
    LinkedList* head = new LinkedList;
    head->value = list->value;
    head->next = nullptr;
    list = list->next;
    while(list != nullptr)
    {
        LinkedList* next = new LinkedList;
        next->value = head->value;
        next->next = head->next;
        head->next = next;
        head->value = list->value;
        list = list->next;
    }
    return head;
}

vector<int> sortStack(stack<int> &input)
{
    stack<int> tempStack;
    vector<int> results;
    while(input.empty() == false)
    {
        int currNum = input.top();
        input.pop();
        while(tempStack.empty() == false && tempStack.top() > currNum)
        {
            input.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(currNum);
    }
    
    while(tempStack.empty() == false)
    {
        results.push_back(tempStack.top());
        tempStack.pop();
    }
    
    return results;
}

bool searchTree(TreeNode* node, int num)
{
    if(node == nullptr)
    {
        return false;
    }
    
    if(node->value == num)
    {
        return true;
    }
    
    return searchTree(node->left, num) || searchTree(node->right, num);
}

void inOrderTraverse(TreeNode* node, vector<int> &nums)
{
    if(node == nullptr)
    {
        return;
    }
    
    inOrderTraverse(node->left, nums);
    nums.push_back(node->value);
    inOrderTraverse(node->right, nums);
}

vector<int> bstToVector(TreeNode* node)
{
    vector<int> results;
    inOrderTraverse(node, results);
    return results;
}

int getNodeHeight(TreeNode* node)
{
    if(node == nullptr)
    {
        return -1;
    }
    
    return max(getNodeHeight(node->left), getNodeHeight(node->right)) + 1;
}

bool isAvl(TreeNode* node)
{
    if(node == nullptr)
    {
        return true;
    }
    if(abs(getNodeHeight(node->left) - getNodeHeight(node->right)) > 1)
    {
        return false;
    }
    
    return isAvl(node->left) && isAvl(node->right);
}

vector<int> mergeSortedEasy(vector<int> v1, vector<int> v2)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto item : v1)
    {
        pq.push(item);
    }
    for(auto item : v2)
    {
        pq.push(item);
    }
    v1.clear();
    while(pq.empty() == false)
    {
        v1.push_back(pq.top());
        pq.pop();
    }
    return v1;
}

vector<int> mergeSortedNoPQ(vector<int> v1, vector<int> v2)
{
    for(int i = 0; i < v2.size(); i++)
    {
        vector<int>::iterator currPlace = v1.begin();
        int currCount = 0;
        bool placed = false;
        while(!placed)
        {
            if(currCount < v1.size() && v1.at(currCount) > v2.at(i))
            {
                v1.insert(currPlace, v2.at(i));
                placed = true;
            }
            else if(currCount >= v1.size())
            {
                v1.push_back(v2.at(i));
                placed = true;
            }
            currPlace++;
            currCount++;
        }
    }
    return v1;
}

bool isBalanced(string input)
{
    stack<char> openChars;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            openChars.push(input[i]);
        }
        
        if(input[i] == ')')
        {
            char currChar = openChars.top();
            openChars.pop();
            if(currChar != '(')
            {
                return false;
            }
        }
        
        if(input[i] == ']')
        {
            char currChar = openChars.top();
            openChars.pop();
            if(currChar != '[')
            {
                return false;
            }
        }
        
        if(input[i] == '}')
        {
            char currChar = openChars.top();
            openChars.pop();
            if(currChar != '{')
            {
                return false;
            }
        }
    }
    if(openChars.empty() == false)
    {
        return false;
    }
    return true;
}

int main()
{
    // problem 1 tests
    cout << "***PROBLEM 1***" << endl;
    vector<int> testNums;
    testNums.push_back(1);
    testNums.push_back(3);
    testNums.push_back(2);
    testNums.push_back(5);
    testNums.push_back(9);
    testNums.push_back(8);
    testNums.push_back(6);
    
    cout << "The 4th smallest is: " << findNthSmallest(testNums, 4) << endl;
    
    // problem 2 tests
    cout << "\n\n***PROBLEM 2***" << endl;
    BinaryNode<int>* root = new BinaryNode<int>{ 90 };
    root->_left = new BinaryNode<int>{ 50 };
    root->_left->_left = new BinaryNode<int>{ 20 };
    root->_left->_right = new BinaryNode<int>{ 75 };
    root->_left->_left->_left = new BinaryNode<int>{ 5 };
    root->_left->_left->_right = new BinaryNode<int>{ 25 };
    root->_left->_right->_left = new BinaryNode<int>{ 66 };
    root->_left->_right->_right = new BinaryNode<int>{ 80 };
    root->_right = new BinaryNode<int>{ 150 };
    root->_right->_left = new BinaryNode<int>{ 95 };
    root->_right->_right = new BinaryNode<int>{ 175 };
    root->_right->_left->_left = new BinaryNode<int>{ 92 };
    root->_right->_left->_right = new BinaryNode<int>{ 111 };
    root->_right->_right->_left = new BinaryNode<int>{ 166 };
    root->_right->_right->_right = new BinaryNode<int>{ 200 };

    reverseOrderTraversal(root);


    // problem 3 tests
    cout << "\n\n***PROBLEM 3***" << endl;
    LinkedList* list = new LinkedList;
    list->value = 1;
    list->next = new LinkedList;
    list->next->value = 2;
    list->next->next = new LinkedList;
    list->next->next->value = 3;
    list->next->next->next = nullptr;
    list = reverseLinkedList(list);
    while(list != nullptr)
    {
        cout << list->value << endl;
        list = list->next;
    }


    // problem 4 tests
    cout << "\n\n***PROBLEM 4***" << endl;
    stack<int> testStack;
    testStack.push(0);
    testStack.push(1);
    testStack.push(2);
    testStack.push(30);
    testStack.push(4);
    testStack.push(5);
    vector<int> stackResults = sortStack(testStack);
    for(auto item : stackResults)
    {
        cout << item << endl;
    }

    // problem 5 tests
    cout << "\n\n***PROBLEM 5***" << endl;
    TreeNode* treeRoot = new TreeNode{90};
    treeRoot->left = new TreeNode{ 50 };
    treeRoot->left->left = new TreeNode{ 20 };
    treeRoot->left->right = new TreeNode{ 75 };
    treeRoot->left->left->left = new TreeNode{ 5 };
    treeRoot->left->left->right = new TreeNode{ 25 };
    treeRoot->left->right->left = new TreeNode{ 66 };
    treeRoot->left->right->right = new TreeNode{ 80 };
    treeRoot->right = new TreeNode{ 150 };
    treeRoot->right->left = new TreeNode{ 95 };
    treeRoot->right->right = new TreeNode{ 175 };
    treeRoot->right->left->left = new TreeNode{ 92 };
    treeRoot->right->left->right = new TreeNode{ 111 };
    treeRoot->right->right->left = new TreeNode{ 166 };
    treeRoot->right->right->right = new TreeNode{ 200 };
    cout << boolalpha << searchTree(treeRoot, 50) << endl;

    // problem 6 tests
    cout << "\n\n***PROBLEM 6***" << endl;
    vector<int> bst = bstToVector(treeRoot);
    for(auto item : bst)
    {
        cout << item << endl;
    }

    // problem 7 tests
    cout << "\n\n***PROBLEM 7***" << endl;
    cout << isAvl(treeRoot) << endl;

    // problem 8 tests
    cout << "\n\n***PROBLEM 8***" << endl;
    cout << getNodeHeight(treeRoot) << endl;

    // problem 9 tests
    cout << "\n\n***PROBLEM 9***" << endl;
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(9);
    v2.push_back(0);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(6);
    v2.push_back(8);
    v2.push_back(10);
    v1 = mergeSortedNoPQ(v1, v2);
    for(auto item : v1)
    {
        cout << item << endl;
    }

    // problem 10 tests
    cout << "\n\n***PROBLEM 10***" << endl;
    cout << isBalanced("({}[])a") << endl;
    
}
