#include<iostream>
using namespace std;

class Shape {
    protected:
        float area;
    public:
        virtual void acceptRecord(void) = 0;
        virtual void calculateArea() = 0;

        void printArea(){
            cout << "Area: " << area << endl;
        }
};



class Ractangle: public Shape {
    float length;
    float breadth;

    void acceptRecord() override {
        cout << "Length: ";
        cin >> length;
        cout << "breadth: ";
        cin >> breadth;
    }

    void calculateArea() override {
        area = length * breadth;
    }

};

class Circle: public Shape {
    float radius;

    void acceptRecord() override {
        cout << "radius: ";
        cin >> radius;
    }

    void calculateArea() override {
        area = 22/7 * radius * radius;
    }

};

class ShapeFactory {
    public:
    // get shape
    static Shape* getInstance(int choice){
        Shape *shape = nullptr;

        switch(choice){
            case 1: 
                shape = new Circle();
                break;
            case 2:
                shape = new Ractangle();
                break;
        }

        return shape;
    }

    // get menu list
    static int menuList(){
        int choice;
        cout << "0.Exit" << endl;
        cout << "1.Circle" << endl;
        cout << "2.Rectangle" << endl;
        cout << "Enter the choice : ";
        cin >> choice;
        return choice;
    }

};

int main(){

    int choice;

    while ((choice = ShapeFactory::menuList()) != 0)
    {
        Shape *shape = ShapeFactory::getInstance(choice);
        
        if(shape != nullptr){
            shape->acceptRecord();
            shape->printArea();
            delete shape;
        }
        shape = nullptr;
    }
    

}