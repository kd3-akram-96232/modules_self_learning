#include <iostream>
using namespace std;

class User
{
    string name;
    int rollNumber;
    double marks;

public:
    User() {}
    User(string name, int rollNumber, double marks)
    {
        this->name = name;
        this->rollNumber = rollNumber;
        this->marks = marks;
    }

    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setRollNumber(int rollNumber) { this->rollNumber = rollNumber; }
    int getRollNumber() { return rollNumber; }
    void setMarks(double marks) { this->marks = marks; }
    double getMarks() { return marks; }

    void accept()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << " name: " << name << endl;
        cout << " roll number: " << rollNumber << endl;
        cout << " marks: " << marks << endl;
        cout << endl;
    }
};

#include <iostream>
using namespace std;

class Node
{
public:
    User *value;
    Node *next;
};

class LinkedList
{
    Node *head = nullptr;

public:
    void preappend(User *user)
    {
        Node *newNode = new Node();
        newNode->value = user;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void add(User *user)
    {
        if (head == nullptr)
        {
            head = new Node();
            head->value = user;
            head->next = nullptr;
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *newNode = new Node();
        newNode->value = user;
        newNode->next = nullptr;

        temp->next = newNode;
    }

    void read()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            return;
        }
        while (temp != nullptr)
        {
            temp->value->display();
            temp = temp->next;
        }
    }
};

int menuList(LinkedList &list)
{
    cout << "1. Add in start" << endl;
    cout << "2. Add in end" << endl;
    cout << "3. Show users" << endl;
    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        {
            User *newUser = new User();
            newUser->accept();
            list.preappend(newUser);
            break;
        }

    case 2:
        {
            User *newUser = new User();
            newUser->accept();
            list.add(newUser);
            break;
        }
    case 3:{
        list.read();
        break;
        }
    }

    return choice;
}

int main()
{
    LinkedList list;

    while (menuList(list) != 0)
    {
    }

    // list.add(new User("Akram", 1001, 10));
    // list.add(new User("Akram", 1002, 500));
    // list.add(new User("Akram", 1003, 700));
    // list.add(new User("Akram", 1004, 100));

    // list.preappend(new User("Akash", 1005, 500));

    // list.read();

    return 0;
}