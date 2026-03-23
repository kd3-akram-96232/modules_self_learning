#include <iostream>
using namespace std;

class Person
{
    string name;

public:
    Person() {}
    Person(string name)
    {
        this->name = name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void print()
    {
        cout << name << endl;
    }
};

class Employee : public Person
{
    int empid;
    string empName;

public:
    Employee(int empId, string empName) : Person("p: " + empName)
    {
        this->empid = empid;
        this->empName = empName;
    }

    void print()
    {
        // Person is a simple class that stores a string name, 
        // can be constructed with or without an initial name, 
        // allows setting the name via setName, 
        // and can print the name to cout.
        Person::print();


        // this->print();

        cout << this->empid << "empName: " << this->empName << endl;
    }
};

int main()
{
    Employee emp(1, "John");
    emp.print();

    // Employee emp1(2, "Smith");
    // emp1.print();

    // Person::print();
}