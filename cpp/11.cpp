#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

class LinkedList
{
    Node *head = nullptr;

public:

    void preappend(int val){
        Node *newNode = new Node();
        newNode->value = val;

        if(head->next == nullptr){
            head = newNode;
        }else{
            newNode = head->next;
            head = newNode;

        }
    }

    void add(int val)
    {
        if(head == nullptr){
            head = new Node();
            head->value = val;
            head->next = nullptr;
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *newNode = new Node();
        newNode->value = val;
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
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    // list.preappend(500);

    list.read();

    return 0;
}
