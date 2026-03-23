#include <iostream>

using namespace std;

class A{
public:
    virtual void printDetails() = 0;
};

class B : public A{
};

class C : public B{
public:
    void printDetails() override{
        cout << "FROM C" << endl;
    }
};

int main(){

    C c;
    c.printDetails();

    return 0;
}