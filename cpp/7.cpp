#include <iostream>
using namespace std;

namespace college
{
    class Student
    {
        int rollNumber;
        string name;
    };
    
    class Teacher
    {
        int id;
        string subject;
    };
};

int main()
{

    using namespace college;

    college::Student st;
    college::Teacher t;    // Source - https://stackoverflow.com/a/78238727


    return 0;
}