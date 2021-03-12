#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include "binaryNode.h"
#include "linkedListNode.h"
using namespace std;

/**********************
*                     *
*      PROBLEM 1      *
*                     *
**********************/
void bstAdd(BinaryNode*& root, int val)
{
    if(root == nullptr)
    {
        root = new BinaryNode{val};
        return;
    }
    
    if(root->value > val)
    {
        bstAdd(root->left, val);
    }
    else if(root->value <= val)
    {
        bstAdd(root->right, val);
    }
}

void coutInOrder(BinaryNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    
    coutInOrder(node->left);
    cout << node->value << endl;
    coutInOrder(node->right);
}

/**********************
*                     *
*      PROBLEM 2      *
*                     *
**********************/
void bstDelete(BinaryNode*& node, int valToBeRemoved)
{
    if(node == nullptr)
    {
        return;
    }
    
    if(node->value == valToBeRemoved)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            // node is leaf
            node = nullptr;
            return;
        }
        
        else if(node->left == nullptr && node->right != nullptr)
        {
            // node has 1 child (right)
            node = node->right;
            node->right = nullptr;
            return;
        }
        
        else if(node->left != nullptr && node->right == nullptr)
        {
            // node has 1 child (left)
            node = node->left;
            node->left = nullptr;
            return;
        }
        
        else
        {
            BinaryNode *predecessor = node->right;
            bool keepDescending = true;
            if(predecessor->left == nullptr)
            {
                keepDescending = false;
            }
            while(keepDescending)
            {
                predecessor = predecessor->left;
                if(predecessor->left == nullptr)
                {
                    keepDescending = false;
                }
            }
            node->value = predecessor->value;
            bstDelete(node->right, predecessor->value);
            return;
        }
    }
    
    if(node->value > valToBeRemoved)
    {
        bstDelete(node->left, valToBeRemoved);
    }
    else if (node->value <= valToBeRemoved)
    {
        bstDelete(node->right, valToBeRemoved);
    }
    
}

/**********************
*                     *
*      PROBLEM 3      *
*                     *
**********************/
bool isHeap(vector<int> items)
{
    for(int i = 0; i < ((items.size()-2) / 2); i++)
    {
        if((items[i] > items[i*2+1]) || ((i*2+2 != items.size()) && (items[i] > items[i*2+2])))
        {
            return false;
        }
    }
    return true;
}

/**********************
*                     *
*      PROBLEM 4      *
*                     *
**********************/
vector<int> sortedVector(priority_queue<int> pq1, priority_queue<int> pq2)
{
    vector<int> results;
    while(pq1.empty() == false && pq2.empty() == false)
    {
        int pq1Num = pq1.top();
        int pq2Num = pq2.top();
        if(pq1Num >= pq2Num)
        {
            results.push_back(pq1Num);
            pq1.pop();
        }
        else
        {
            results.push_back(pq2Num);
            pq2.pop();
        }
    }
    
    if(pq1.empty() == false)
    {
        while(pq1.empty() == false)
        {
            results.push_back(pq1.top());
            pq1.pop();
        }
    }
    if(pq2.empty() == false)
    {
        while(pq2.empty() == false)
        {
            results.push_back(pq2.top());
            pq2.pop();
        }
    }
    return results;
}

/**********************
*                     *
*      PROBLEM 5      *
*                     *
**********************/
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int>& nums, int start, int end)
{
    int pivot = nums[end];
    int i = start - 1;
    for(int j = start; j <= end-1;j++)
    {
        if(nums[j] <= pivot)
        {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }
    swap(&nums[i+1], &nums[end]);
    return i+1;
}

void quickSort(vector<int>& nums, int start, int end)
{
    if(start < end)
    {
        int partitionNum = partition(nums, start, end);
        quickSort(nums, start, partitionNum-1);
        quickSort(nums, partitionNum+1, end);
    }
}


/**********************
*                     *
*      PROBLEM 6      *
*                     *
**********************/
void inorderTraversal(BinaryNode* node, vector<int>& nums)
{
    if(node == nullptr)
    {
        return;
    }
    
    inorderTraversal(node->left, nums);
    nums.push_back(node->value);
    inorderTraversal(node->right, nums);
}

bool isBST(BinaryNode* node)
{
    if(node == nullptr)
    {
        return true;
    }
    
    vector<int> initial;
    inorderTraversal(node, initial);
    vector<int> sorted = initial;
    sort(sorted.begin(), sorted.end());
    if(initial == sorted)
    {
        return true;
    }
    return false;
}

/**********************
*                     *
*      PROBLEM 7      *
*                     *
**********************/
int getHeight(BinaryNode* node)
{
    if(node == nullptr)
    {
        return -1;
    }
    
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}
bool isAVL(BinaryNode* node)
{
    if(node == nullptr)
    {
        return true;
    }
    
    if(abs(getHeight(node->right) - getHeight(node->left)) > 1 || !isBST(node))
    {
        return false;
    }
    isAVL(node->left);
    isAVL(node->right);
    return true;
}

/**********************
*                     *
*      PROBLEM 8      *
*                     *
**********************/
string mostRainyDay(vector<int> days)
{
    unordered_map<int, string> dayMappings;
    dayMappings[0] = "Sunday";
    dayMappings[1] = "Monday";
    dayMappings[2] = "Tuesday";
    dayMappings[3] = "Wednesday";
    dayMappings[4] = "Thursday";
    dayMappings[5] = "Friday";
    dayMappings[6] = "Saturday";
    
    unordered_map<int, int> frequencies;
    int maxNum = 0;
    int maxDay;
    for(int i = 0; i < days.size(); i++)
    {
        int dayNum = i % 7;
        frequencies[dayNum] += days[i];
    }
    
    for(auto item : frequencies)
    {
        if(item.second > maxNum)
        {
            maxNum = item.second;
            maxDay = item.first;
        }
    }
    return dayMappings[maxDay];
}

/**********************
*                     *
*      PROBLEM 9      *
*                     *
**********************/
void bstToVector(BinaryNode* node, vector<int>& nums)
{
    if(node == nullptr)
    {
        return;
    }
    bstToVector(node->left, nums);
    nums.push_back(node->value);
    bstToVector(node->right, nums);
}

/**********************
*                     *
*     PROBLEM 10      *
*                     *
**********************/
LinkedListNode* reverseLL(LinkedListNode* node)
{
    LinkedListNode* tail = new LinkedListNode{node->_value};
    LinkedListNode* head;
    tail->_next = nullptr;
    node = node->_next;
    while(node != nullptr)
    {
        head = new LinkedListNode{node->_value};
        head->_next = tail;
        tail = head;
        node = node->_next;
    }
    return tail;
}

/**********************
*                     *
*     PROBLEM 11      *
*                     *
**********************/
vector<string> fizzbuzz(int n)
{
    vector<string> results;
    for(int i = 0; i < n; i++)
    {
        if(i >= 5 && i % 3 == 0 && i % 5 == 0)
        {
            results.push_back("fizzbuzz");
        }
        
        else if(i >= 3 && i % 3 == 0)
        {
            results.push_back("fizz");
        }
        
        else if(i >= 5 && i % 5 == 0)
        {
            results.push_back("buzz");
        }
        else
        {
            results.push_back(to_string(i));
        }
    }
    return results;
}

/**********************
*                     *
*     PROBLEM 12      *
*                     *
**********************/
string mostCommonString(string s, int n)
{
    unordered_map<string, int> frequencies;
    for(int i = 0; i <= s.length() - n; i++)
    {
        frequencies[s.substr(i, n)]++;
    }
    
    string maxWord;
    int maxCount = 0;
    for(auto item : frequencies)
    {
        if(maxCount < item.second)
        {
            maxWord = item.first;
            maxCount = item.second;
        }
    }
    return maxWord;
}

/**********************
*                     *
*     PROBLEM 13      *
*                     *
**********************/
BinaryNode* avlRightRotate(BinaryNode* originalRoot)
{
    BinaryNode* newRoot = originalRoot->left;
    originalRoot->left = newRoot->right;
    newRoot->right = originalRoot;
    return newRoot;
}

/**********************
*                     *
*     PROBLEM 14      *
*                     *
**********************/
bool areParenthesisValid(string input, unordered_map<char, char> validParenthesis)
{
    stack<char> openChars;
    unordered_map<char, int> allParenthesis;
    unordered_map<char, int> closedChars;
    for(auto item : validParenthesis)
    {
        allParenthesis[item.first]++;
        allParenthesis[item.second]++;
        closedChars[item.second]++;
    }
    
    for(int i = 0; i < input.length(); i++)
    {
        if(allParenthesis.find(input[i]) != allParenthesis.end())
        {
            if(validParenthesis.find(input[i]) != validParenthesis.end())
            {
                openChars.push(input[i]);
            }
            
            else
            {
                if(openChars.empty() || validParenthesis[openChars.top()] != input[i])
                {
                    return false;
                }
                openChars.pop();
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
    cout << boolalpha;
    cout << "***Problem 1 Tests***" << endl;
    BinaryNode* root = new BinaryNode{ 90 };
    root->left = new BinaryNode{ 50 };
    root->left->left = new BinaryNode{ 20 };
    root->left->right = new BinaryNode{ 75 };
    root->left->left->left = new BinaryNode{ 5 };
    root->left->left->right = new BinaryNode{ 25 };
    root->left->right->left = new BinaryNode{ 66 };
    root->left->right->right = new BinaryNode{ 80 };
    root->right = new BinaryNode{ 150 };
    root->right->left = new BinaryNode{ 95 };
    root->right->right = new BinaryNode{ 175 };
    root->right->left->left = new BinaryNode{ 92 };
    root->right->left->right = new BinaryNode{ 111 };
    root->right->right->left = new BinaryNode{ 166 };
    root->right->right->right = new BinaryNode{ 200 };
    
    
    bstAdd(root, 69);
    bstAdd(root, 220);
    bstAdd(root, -1);
    bstAdd(root, 62);
    bstAdd(root, 79);
    coutInOrder(root);
    
    
    cout << "\n\n***Problem 2 Tests***" << endl;
    
    bstDelete(root, 69);
    bstDelete(root, 220);
    bstDelete(root, -1);
    bstDelete(root, 62);
    bstDelete(root, 79);
    coutInOrder(root);
    
    
    cout << "\n\n***Problem 3 Tests***" << endl;
    vector<int> isAHeap = {2,3,4,5,10};
    vector<int> isNotAHeap = {2,10,4,5,3,15};
    cout << isHeap(isAHeap) << endl;
    cout << isHeap(isNotAHeap) << endl;
    
    cout << "\n\n***Problem 4 Tests***" << endl;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    for(int i = 0; i < 10; i++)
    {
        pq1.push(rand() % 101);
        pq2.push(rand() % 101);
    }
    pq2.push(rand() % 101);
    pq2.push(rand() % 101);
    pq2.push(rand() % 101);
    vector<int> sorted;
    sorted = sortedVector(pq1, pq2);
    for(auto item : sorted)
    {
        cout << item << endl;
    }
    
    cout << "\n\n***Problem 5 Tests***" << endl;
    vector<int> nums;
    for(int i = 0; i < 20; i++)
    {
        nums.push_back(rand()%101);
    }
    quickSort(nums, 0, nums.size());
    for(auto item : nums)
    {
        cout << item << endl;
    }
    
    cout << "\n\n***Problem 6 Tests***" << endl;
    cout << isBST(root) << endl;
    
    cout << "\n\n***Problem 7 Tests***" << endl;
    BinaryNode* rootOfAvl = new BinaryNode{12};
    rootOfAvl->left = new BinaryNode{8};
    rootOfAvl->left->right = new BinaryNode{11};
    rootOfAvl->left->left = new BinaryNode{5};
    rootOfAvl->left->left->left = new BinaryNode{4};
    rootOfAvl->right = new BinaryNode{18};
    rootOfAvl->right->left = new BinaryNode{17};
    
    BinaryNode* rootOfNotAvl = new BinaryNode{12};
    rootOfNotAvl->left = new BinaryNode{8};
    rootOfNotAvl->left->right = new BinaryNode{11};
    rootOfNotAvl->left->left = new BinaryNode{5};
    rootOfNotAvl->left->left->right = new BinaryNode{7};
    rootOfNotAvl->left->left->left = new BinaryNode{4};
    rootOfNotAvl->left->left->left->left = new BinaryNode{2};
    rootOfNotAvl->right = new BinaryNode{18};
    rootOfNotAvl->right->left = new BinaryNode{17};
    
    cout << isAVL(rootOfAvl) << endl;
    cout << isAVL(rootOfNotAvl) << endl;
    
    cout << "\n\n***Problem 8 Tests***" << endl;
    vector<int> data = {1, 1, 2, 1, 1, 1, 3, 0, 0, 1, 4, 2, 1, 2};
    cout << mostRainyDay(data) << endl;
    
    cout << "\n\n***Problem 9 Tests***" << endl;
    vector<int> bst;
    bstToVector(root, bst);
    for(auto item : bst)
    {
        cout << item << endl;
    }
    
    cout << "\n\n***Problem 10 Tests***" << endl;
    LinkedListNode* head = new LinkedListNode{5};
    head->_next = new LinkedListNode{4};
    head->_next->_next = new LinkedListNode{3};
    head->_next->_next->_next = new LinkedListNode{2};
    head->_next->_next->_next->_next = new LinkedListNode{1};
    head->_next->_next->_next->_next->_next = new LinkedListNode{0};
    head->_next->_next->_next->_next->_next->_next = nullptr;
    LinkedListNode* newHead = reverseLL(head);
    while(newHead!=nullptr)
    {
        cout << newHead->_value <<endl;
        newHead = newHead->_next;
    }
    
    cout << "\n\n***Problem 11 Tests***" << endl;
    for(auto item : fizzbuzz(16))
    {
        cout << item << endl;
    }
    
    cout << "\n\n***Problem 12 Tests***" << endl;
    cout << mostCommonString("aabcdabc", 3) << endl;
    
    cout << "\n\n***Problem 13 Tests***" << endl;
    BinaryNode* avlRightNode = new BinaryNode{100};
    avlRightNode->left = new BinaryNode{50};
    avlRightNode->left->left = new BinaryNode{25};
    avlRightNode->left->left->left = new BinaryNode{10};
    avlRightNode->left->right = new BinaryNode{75};
    avlRightNode->right = new BinaryNode{150};
    avlRightNode = avlRightRotate(avlRightNode);
    coutInOrder(avlRightNode);
    
    cout << "\n\n***Problem 14 Tests***" << endl;
    unordered_map<char, char> validParenthesis;
    validParenthesis['('] = ')';
    validParenthesis['{'] = '}';
    validParenthesis['['] = ']';
    cout << areParenthesisValid("(5+3)(1*2){[(12314*&^%$#@)]}", validParenthesis) << endl;
}
