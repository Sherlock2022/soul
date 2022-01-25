/**
 * @file test3.cpp
 * @author your name (you@domain.com)
 * @brief null对象
 * @version 0.1
 * @date 2022-01-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <string>
#include <iostream>

using namespace std;

class nullCustomer;
class Customer
{
public:
    static Customer *newNull()
    {
        static nullCustomer customer;
        return &customer;
    }

public:
    virtual string getName() const { return name; }
    virtual string getNumber() const { return phonenumber; }
    virtual string getAddress() const { return address; }

    virtual bool isNull() const { return false; }

private:
    string name;
    string phonenumber;
    string address;
};

class nullCustomer : public Customer
{
public:
    string getName() const override { return ""; }
    string getNumber() const override { return ""; }
    string getAddress() const override { return ""; }

    bool isNull() const { return true; }
};

class Fedex //快递
{
public:
    Fedex() : m_pCustomer(nullptr)
    {
    }

    void setCustomer(Customer *p) { m_pCustomer = p; }
    Customer *getCustomer()
    {
        return m_pCustomer == nullptr ? Customer::newNull() : m_pCustomer;
    }

private:
    Customer *m_pCustomer;
};

int main()
{
    Fedex *pFedex = new Fedex();

    // Customer* pCustomer = pFedex->getCustomer();
    // if(pCustomer)
    // {
    //     cout << "name" << pCustomer->getName();
    // }

    cout << "name" << pFedex->getCustomer()->getName();

    return 0;
}
