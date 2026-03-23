#include<iostream>
using namespace std;


class Date {
    int day, month, year;
    public:
    Date(): day(0), month(0), year(0){}
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void acceptDate(){
        cout << "Enter Day: ";
        cin >> this->day;
        cout << "Enter Month: ";
        cin >> this->month;
        cout << "Enter Year: ";
        cin >> this->year;
    }

    void setDate(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void display(){
        cout << "day: " << this->day << ", month: " << this->month << ", year: "<< this->year << endl;
    }
};

class Employee {
    string empName;
    double sal;
    Date joinDate;

    public:
    Employee(): empName(""), sal(0), joinDate(0,0,0) {}
    Employee(string name, int sal, int day=0, int month=0, int year=0){
        this->empName = name;
        this->sal = sal;
        this->joinDate.setDate(day, month, year);
    }
        Employee(string name, int sal, Date joinDate){
        this->empName = name;
        this->sal = sal;
        this->joinDate = joinDate;
    }

    void printEmp(){
        cout << "emp name: " << empName <<endl;
        cout << "emp sal: " << sal <<endl;
        joinDate.display();
    }

};

int main(){

    // Date *d = new Date();
    Date d;
    d.acceptDate();

    Employee emp("Akram", 1200, d);

    emp.printEmp();

    return 0;
}