#include <iostream>
#include <set>
#include <string>

/**
 * @brief 使用双向关联
 * 1. Customer和order是一对多的关系，一个顾客可能有多个订单；
 * 2. order中可能需要保存Customer指针，比如我们需要知道当前order对应的顾客信息；
 * 3. 我们可以将控制函数放到“部件”类中，从而将所有的关联关系逻辑处理放在同一个类中；
 * 4. 如果我们在另一个中也需要控制逻辑关系，那么用该类去调用“部件”类中的函数；
 */

class Customer;
class Order
{
public:
    Order() : m_pCustomer(NULL) 
    { 

    }

    ~Order()
    {
        setCustomer(NULL);
    }

    Customer *getCustomer() { return m_pCustomer; }
    void setCustomer(Customer *p);

private:
    Customer *m_pCustomer;
};

class Customer
{
public:
    Customer(int age, const std::string &name)
        : _age(age), _name(name)
    {
    }

    ~Customer()
    {
        
    }

    void addOrder(Order *o);
    void delOrder(Order *o);

    std::string getName() const { return _name; }
    int getAge() const { return _age; }

private:
    std::set<Order *> orderSet;

    std::string _name;
    int _age;

    friend class Order;
};

void Order::setCustomer(Customer *p)
{
    if (m_pCustomer)
        m_pCustomer->orderSet.erase(this);

    m_pCustomer = p;

    if (m_pCustomer)
        m_pCustomer->orderSet.insert(this);
}

void Customer::addOrder(Order *o)
{
    o->setCustomer(this);
}

void Customer::delOrder(Order *o)
{
    o->setCustomer(NULL);
}

int main()
{
    Customer *pCustomer = new Customer(24, "Kevin");
    Order *pOrder = new Order();

    pCustomer->addOrder(pOrder);

    std::cout << "Custome name :" << pCustomer->getName();
    std::cout << "Custome age :" << pCustomer->getAge();

    return 0;
}