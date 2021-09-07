// ConsoleApplication31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Employee
{
    int m_eno;
    char* m_ename;
public:
    Employee()
    {
        m_eno = 0;
        m_ename = new char;
        m_ename[0] = '\0';
    }
    Employee(int eno, const char* ename)
    {
        m_eno = eno;
        m_ename = new char[strlen(ename) + 1];
        strcpy_s(m_ename,-1, ename);
    }
    Employee(const Employee& object)
    {
        m_eno = object.m_eno;
        m_ename = new char[strlen(object.m_ename) + 1];
        strcpy_s(m_ename,-1, object.m_ename);
    }
    Employee& operator=(Employee& object)
    {
        if (this != &object)
        {
            delete[]m_ename;
            m_eno = object.m_eno;
            m_ename = new char[strlen(object.m_ename) + 1];
           strcpy_s(m_ename,-1, object.m_ename);
        }
        return *this;
    }
    void display()
    {
        cout << "Eno:" << m_eno << endl;
        cout << "Ename:" << m_ename << endl;
    }
    ~Employee()
    {
        if (m_ename != nullptr)
        {
            delete[]m_ename;
            m_ename = nullptr;
        }
    }
 };
    void main()
    {
        Employee obj1;
        obj1.display();
        Employee obj2(101, "Lakshmi");
        obj2.display();
        Employee obj3(obj2);
        obj3.display();

       Employee obj4(102, "Praveen");
       obj4 = obj4;
       obj4.display();
    }


