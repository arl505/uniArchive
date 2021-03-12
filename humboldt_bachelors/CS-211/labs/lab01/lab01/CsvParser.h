#pragma once
#ifndef CsvParser_h
#define CsvParser_h

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CsvStateMachine;
class CsvState;
class DefaultState;
class QuoteState;
class DoubleQuoteState;
class EndState;

class CsvState
{
protected:
    CsvStateMachine* _machine = nullptr;

public:
    virtual ~CsvState(){};
    
    CsvState(CsvStateMachine* machine){
        _machine = machine;
    }
    
    virtual void handle() = 0;
};

class DefaultState : public CsvState
{
public:
    DefaultState(CsvStateMachine* machine)
    : CsvState(machine)
    {
    }
    
    virtual void handle();
};

class QuoteState : public CsvState
{
public:
    QuoteState(CsvStateMachine* machine)
    : CsvState(machine)
    {
    }
    
    virtual void handle();
};

class DoubleQuoteState : public CsvState
{
public:
    DoubleQuoteState(CsvStateMachine* machine)
    : CsvState(machine)
    {
    }
    
    virtual void handle();
};

class EndState : public CsvState
{
public:
    EndState(CsvStateMachine* machine)
    : CsvState(machine)
    {
    }
    
    virtual void handle();
};

void DefaultState::handle()
{
    
}

void QuoteState::handle()
{
    
}

void DoubleQuoteState::handle()
{
    
}

void EndState::handle()
{
    
}

#endif /* CsvParser_h */
