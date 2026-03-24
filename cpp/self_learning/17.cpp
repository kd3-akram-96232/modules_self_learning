#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include<sstream>

class Student
{
    string name;
    int age;

public:
    Student() {}
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }

    void accept()
    {
        cout << "---Enter name: ";
        cin >> name;
        cout << "---Enter age: ";
        cin >> age;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

void saveStudent(Student *user)
{
    ofstream outFile("17.txt", ios::app);

    outFile << user->getName() << ',' << user->getAge() << endl;
    // cout << user->getName() << "," << user->getAge() << endl;
    outFile.close();
}

void printActions()
{
    cout << "1. Add user." << endl;
    cout << "2. Show user." << endl;
}

int menuList(vector<Student *> &studentList)
{
    printActions();
    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        Student *newStudent = new Student();
        newStudent->accept();
        studentList.push_back(newStudent);
        saveStudent(newStudent);
        break;
    }

    case 2:
    {
        for (int i = 0; i < studentList.size(); i++)
        {
            studentList[i]->display();
        }
        break;
    }
    }

    return choice;
}

void loadStudentsFromFile(vector<Student *> &list)
{
    ifstream inFile("17.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            string name;
            string ageStr;

            stringstream data(line);
            getline(data, name, ',');
            getline(data, ageStr, ',');

            int age = stoi(ageStr);

            list.push_back(new Student(name, age));
            // cout << "name: " << name << " age: " << age << endl;
        }
    }
}

int main()
{
    vector<Student *> studentList;

    Student *s = new Student("Akram", 12);

    loadStudentsFromFile(studentList);

    while (menuList(studentList) != 0)
    {
    }

    return 0;
}