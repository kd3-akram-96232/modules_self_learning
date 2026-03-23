#include<iostream>

using namespace std;

class Ractangle {
    private: 
    float length;
    float breadth;
    float area;

    public : 

    void acceptRecord(){
        cout<<"Length : "; 
        cin>>length; 
        cout<<"Breadth : "; 
        cin>>breadth; 
    }

    float getArea( void ){
        return breadth * length;
    }

    void printRecord(){
        cout << "Area: " << getArea() << endl;
    }

};

class Math {
    public:
    const static float PI;
    const static float pow(float base, float index){

        float result = 1;
        for(int i = 0; i<index; i++){
            result = result * base;
        }

        return result;

    }
};

const float Math::PI =  22/7;

class Circle {
    int radius;

    public:
        void acceptRecord(){
            cout << "Enter radius: ";
            cin >> radius;
        }

        float getArea () {
            return Math::PI * Math::pow(radius, 2);
        }

        void printRecord(){
            cout << "Area: " << getArea() << endl;
        }
};

int main(){

    Ractangle r;
    r.acceptRecord();
    cout << r.getArea()<<endl;
    r.printRecord();


    Circle c;
    c.acceptRecord();
    cout << c.getArea() << endl;
    c.printRecord();


    return 0;
}