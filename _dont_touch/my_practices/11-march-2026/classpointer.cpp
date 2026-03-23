#include<iostream>
using namespace std;

class Student {
    string name;
    int rollNumber;

    public:
    Student(): name(""), rollNumber(1001){

    }

    Student(string name, int rollNumber){
        this->name = name;
        this->rollNumber = rollNumber;
    }

    void printStudent(){
        cout << "Name: " << this->name << endl;
        cout << "Roll Number" << this->rollNumber << endl;
    }

};

int main(){

    Student **stu = new Student*[3];

    stu[0] = new Student("Akram", 1001);
    stu[1] = new Student("Akash", 1001);
    stu[2] = new Student("Vijay", 1001);

    for(int i = 0; i<3; i++){
        stu[i]->printStudent();
    }

    for(int i = 0; i < 3; i++){
        delete [] stu[i];
        stu[i] = NULL;
    }

    stu = NULL;



}