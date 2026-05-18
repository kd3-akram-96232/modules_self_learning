#include <iostream>
using namespace std;

class Programmer{

public:
    Programmer(){
        cout << "Programmer Constructor" << endl;
    }

    void work(){
        cout << "Programmer - work" << endl;
    }
};

class Teacher{
public:
    Teacher(){
        cout << "Teacher Constructor" << endl;
    }

    void work(){
        cout << "Teacher - work" << endl;
    }
};

class ProgrammingTeacher : public Programmer, public Teacher{
    public:
    ProgrammingTeacher(){
        cout << "PROGRAMMING TEACHER" << endl;
    }
};

int main(){

    ProgrammingTeacher pt;

    pt.Programmer::work();
    pt.Teacher::work();

    return 0;
}