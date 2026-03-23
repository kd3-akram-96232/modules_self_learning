#include<iostream>
using namespace std;

class Number {
    int value;

    public:
    Number(){}
    Number(int value){
        this->value = value;
    }

    Number operator + (const Number &n){
        return Number(this->value + n.value);
    }

    void display(){
        cout << this->value << endl;
    }

};


class Counter {
    int count = 0;

    public:
        void operator ++ () {
            ++this->count;
        }
        void operator -- (){
            --this->count;
        }

        void displayCount(){
            cout << "count: " << count << endl;
        }
};

class Complex {
    float real;
    float imag;
    public:
    Complex():real(real),imag(imag){}
    Complex(float real, float imag){
        this->real = real;
        this->imag = imag;
    }

    Complex operator + (const Complex &c){
        return Complex(real+c.real, imag + c.imag);
    }

    void display(){
        cout << "real: " << real << endl;
        cout << "imag: " << imag << endl;
    }


};

class Person {
    string name;
    public:
        Person(string name): name(""){}
};

int main(){
    Complex c1(10, 20), c2(30, 40);
    Complex c3 = c1+c2;
    c3.display();

    // Counter c;
    // ++c;
    // ++c;
    // ++c;
    // ++c;
    // --c;
    // // 4-1=3
    // c.displayCount();

    // Number n1(10);
    // Number n2(20);

    // Number n3 = n1 + n2;

    // n3.display();

    return 0;
}

