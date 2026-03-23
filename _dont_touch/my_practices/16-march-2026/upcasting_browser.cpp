#include<iostream>
using namespace std;

class Product {
    int id;
    string title;
    double price;

    public:
        virtual void acceptRecord(){

        }
        virtual void printRecord(){

        }
};

class Book: public Product {
    public:
        public:
        virtual void acceptRecord(){

        }
        virtual void printRecord(){

        }

};

class Tape : public Product {
        
    public:
        virtual void acceptRecord(){

        }
        virtual void printRecord(){

        }
};

int main() {
    Product *product = new Book();
    Product *product2 = new Tape();

    return 0;
}