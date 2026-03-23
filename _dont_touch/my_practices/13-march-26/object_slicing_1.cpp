#include<iostream>
using namespace std;

class Base {
    int num1;
    int num2;
    public:
    Base(int num1, int num2){
        this->num1 = num1;
        this->num2 = num2;
    }

    void printRecord(){
        cout << "base:num 1: " << this->num1 << endl;
        cout << "base:num 2: " << this->num2 << endl;
    }
};

class Derived: public Base{
   int num1;
   int num2;
    int num3;

    public:
    Derived(int num1, int num2, int num3): Base(10, 20){
        this->num1 = num1;
        this->num2 = num2;
        this->num3 = num3;
    }

    void printRecord(){
            cout << "derived: num 1: " << this->num1 << endl;
            cout << "derived: num 2: " << this->num2 << endl;
            cout << "derived: num 3: " << this->num3 << endl;
    }
};


int main(){

    Base *base = new Derived(30, 40, 50);

    base->printRecord();

    return 0;
}