/**
 * @file test2.cpp
 * @author your name (you@domain.com)
 * @brief 以子类取代类型码
 * @version 0.1
 * @date 2022-01-20
 *
 * @copyright Copyright (c) 2022
 *
 */

enum Type
{
    ENGINEER,
    SLAESMAN,
    MANAGER
};

class Employee
{
public:
    Employee(Type type) : _type(type)
    {
    }

protected:
    Type getType()
    {
        return _type;
    }

    static Employee *create(Type type)
    {
        switch (type)
        {
        case ENGINEER:
            return new Engineer();
            break;
        case SLAESMAN:
            return new Salesman();
            break;
        case MANAGER:
            return new Manager();
            break;
        default:
            return nullptr;
            break;
        }
    }

protected:
    Type _type;
};

class Engineer : public Employee
{
public:
    Engineer() : Employee(ENGINEER)
    {
    }
};

class Salesman : public Employee
{
public:
    Salesman() : Employee(SLAESMAN)
    {
    }
};

class Manager : public Employee
{
public:
    Manager() : Employee(MANAGER)
    {
    }
};
