#include<iostream>
using namespace std;

class Person {
    string name;
    int age;

    public:
    void display(){
        cout << "pname: " << name<<endl;
        cout << "page: " << endl;
    }

    virtual void work() = 0;
};


class Student : public Person {
    int marks;

    public:
    void study (){

    }

    void work() override{
        cout << "student work" <<  endl;
    }
};

class Teacher: public Person {
    double salary;
    public:
    void teach(){

    }

    void work() override{
        cout << "student work" <<  endl;
    }
};


int main(){

    Student st;
    Teacher t;

    st.work();
    t.work();

    return 0;
}
