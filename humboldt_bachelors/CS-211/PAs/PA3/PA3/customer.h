#ifndef customer_h
#define customer_h

class Customer
{
private:
    int _customer_id;
    int _arrivalTime;
    int _serviceTime;
    int _departureTime;
    int _lineNum;
    bool _customerPlaced;
    
public:
    Customer()
    {
        _customer_id = 0;
        _arrivalTime = 0;
        _serviceTime = 0;
        _departureTime = 0;
        _lineNum = 0;
        _customerPlaced = false;
    }
    void setCustomerId(int customerId)
    {
        _customer_id = customerId;
    }
    int getCustomerId(void)
    {
        return _customer_id;
    }
    
    void setArrivalTime(int arrivalTime)
    {
        _arrivalTime = arrivalTime;
    }
    int getArrivalTime(void)
    {
        return _arrivalTime;
    }
    
    void setServiceTime(int serviceTime)
    {
        _serviceTime = serviceTime;
    }
    int getServiceTime(void)
    {
        return _serviceTime;
    }
    
    void setDepartureTime(int minute)
    {
        _departureTime = minute + _serviceTime;
    }
    int getDepartureTime(void)
    {
        return _departureTime;
    }
    
    void setLineNum(int lineNum)
    {
        _lineNum = lineNum;
    }
    int getLineNum(void)
    {
        return _lineNum;
    }
    
    int getTotalWaitTime(void)
    {
        return (_departureTime - _arrivalTime);
    }
    
    bool isPlaced(void)
    {
        return _customerPlaced;
    }
    void setPlaced(bool placed)
    {
        _customerPlaced = placed;
    }
    
};

#endif /* customer_h */
