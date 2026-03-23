#include <iostream>
using namespace std;

class Student
{
    int rollNo;
    int marks;

public:
    static int topper;
    static int highestMarks;

    Student() : rollNo(0), marks(0) {}
    Student(int rollNo, int marks)
    {
        this->rollNo = rollNo;
        this->marks = marks;
    }

    void printStudent()
    {
        cout << "roll no: " << rollNo << endl;
        cout << "marks: " << marks << endl;
    }

    void acceptStudent(int index)
    {
        cout << "for student no.: " << index << ", Enter roll no.: ";
        cin >> this->rollNo;
        cout << "Enter marks: ";
        cin >> this->marks;

         if (this->marks> Student::highestMarks)
        {
            Student::topper = this->rollNo;
            Student::highestMarks = this->marks;
        }
    }
    static void printHighestMarks()
    {

        int topper = Student::topper;
        int highMarks = Student::highestMarks;

        cout << "Print highest marks: " << endl;

        cout << "Student: " << topper << ", marks: " << highMarks << endl;
    }
};

int Student::topper = 0;
int Student::highestMarks = 0;

int main()
{

    int arrSize;
    cout << "Enter student size: ";
    cin >> arrSize;

    Student *student = new Student[arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        student->acceptStudent(i);
    }

    cout << "Print Students: " << endl;

    for (int i = 0; i < arrSize; i++)
    {
        student->printStudent();
    }


    Student::printHighestMarks();
}