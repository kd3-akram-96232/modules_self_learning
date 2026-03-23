#include <iostream>
using namespace std;

class Base
{
    int num1;
    int num2;

public:
    Base() : num1(0), num2(0) {};
    Base(int num1, int num2){
        this->num1 = num1;
        this->num2 = num2;
    }

    void printRecord(void){
        cout << "num1 : " << num1 << endl;
        cout << "num2 : " << num2 << endl;
    }
    void showRecord(void){
        cout << "num1 : " << num1 << endl;
        cout << "num2 : " << num2 << endl;
    }
};

class Derived: public Base{
    int num3;
    public:
    Derived(): num3(0){}
    Derived(int num1, int num2, int num3): num3(num3), Base(num1, num2){}
    void printRecord( void ){
        Base::printRecord( ); 
        cout<<"num3 : "<<num3<<endl;
    }
    void displayRecord( void ){
        Base::showRecord( ); //num1 
        cout<<"num3 : "<<num3<<endl; 
    }
};

int main(){

    Derived d1(10, 20, 30);
    Base *ptrBase = &d1;

    d1.printRecord();

    ptrBase->printRecord();

    return 0;
}