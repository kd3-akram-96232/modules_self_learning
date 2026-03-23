#include<iostream>
using namespace std;

class A {
    int num1 = 0;

    public:
    A(int n){
        this->num1 = n;
    }

    friend void show(A a);
};


void show(A a){
    int res = a.num1;
    cout << res << endl;
}

int main(){

    A a(50);

    show(a);


    return 0;
}