#include <iostream>
using namespace std;

class Product
{
    string title;
    double price;

public:
    Product() : title(""), price(0) {}
    Product(string title, double price)
    {
        this->title = title;
        this->price = price;
    }

public:
    virtual void accept() {};
    virtual void display() {};
};

class Book
{
    int pages;

public:
    Book() {}
    Book(int pages)
    {
        this->pages = pages;
    }
};

class Tape
{
    int playtime;

public:
    Tape() {}
    Tape(int playtime)
    {
        this->playtime = playtime;
    }
};

int main()
{

    Product *arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "1. Book, 2. Tape, Enter choice: ";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            arr[i] =  (Product *) new Book;
            arr[i]->accept();
            break;
        case 2:
            arr[i] = (Product *) new Tape;
            arr[i]->accept();
            break;
        }
    }
    return 0;
}
