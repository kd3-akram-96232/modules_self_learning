#include <iostream>
using namespace std;

class A{
    public:
    void afunction(){
        cout << "A function" << endl;
    }
    A(){
        cout << "class A" <<endl;
    }
    ~A(){
        cout << "class ~A" <<endl;
    }
};
class B: virtual public A {
    public:
    B(){
        cout << "class B" << endl;
    }
    ~B(){
        cout << "class ~B" <<endl;
    }
};
class C: virtual public A {
    public:
    C(){
        cout << "class C" <<endl;
    }
    ~C(){
        cout << "class ~C" <<endl;
    }
};
class D: public B, public C{
    public:
    D(){
        cout << "class D" << endl;
    }
    ~D(){
        cout << "class ~D" <<endl;
    }
};

int main(){

    D d;
    d.afunction();

    return 0;
}