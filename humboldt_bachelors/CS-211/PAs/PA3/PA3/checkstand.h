#ifndef checkstand_h
#define checkstand_h

#include <queue>
#include "customer.h"
using namespace std;

class Checkstand
{
private:
    int _lineNum;
    queue<Customer> _inLine;
    queue<Customer> _served;
    
public:
    Checkstand()
    {
        queue<Customer> emtpyList;
        _lineNum = 0;
        _inLine = emtpyList;
        _served = emtpyList;
    }
    
    void setLineNum(int lineNum)
    {
        _lineNum = lineNum;
    }
    int getLineNum(void)
    {
        return _lineNum;
    }
    
    void setInLine(queue<Customer> customers)
    {
        _inLine = customers;
    }
    queue<Customer> getInLine(void)
    {
        return _inLine;
    }
    
    void setServed(queue<Customer> customers)
    {
        _served = customers;
    }
    queue<Customer> getServed(void)
    {
        return _served;
    }
    
    bool isEmpty(void)
    {
        if(_inLine.size() == 0)
        {
            return true;
        }
        return false;
    }
    
    void addCustomer(Customer customer)
    {
        _inLine.push(customer);
    }
    
    void popInLine(void)
    {
        _inLine.pop();
    }
    
    void addServed(Customer customer)
    {
        _served.push(customer);
    }
    
    void popServed(void)
    {
        _served.pop();
    }
};

#endif /* checkstand_h */
