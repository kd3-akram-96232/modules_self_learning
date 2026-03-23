#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next;
    }
    Node(int value, Node *node)
    {
        this->value = value;
        node->next = node;
    }
};

class LinkedList
{
    Node *head = nullptr;

public:
    void prepend(int value)
    {
        // Node *temp = head;
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;

    }
    void append(int value)
    {
        Node *h = head;
        while (h->next != nullptr)
        {
            h = h->next;
        }

        h->next = new Node(value);
        head = h;   
    }

    void traverse(){
        Node *h = head;
        while (h->next != nullptr)
        {
            cout << h->value << endl;
            h = h->next;
        }
        
    }
};

int main()
{

    LinkedList *li;

    li->append(10);
    li->append(20);
    li->append(30);
    li->append(40);

    li->prepend(10);
    li->prepend(20);
    li->prepend(50);

    li->traverse();

}