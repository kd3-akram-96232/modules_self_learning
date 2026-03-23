#include<iostream>
using namespace std;

class Product {
    string title;
    double price;

    virtual void accept() = 0;
    virtual void display() = 0;
};

class Book {

};

class Tape {

};

