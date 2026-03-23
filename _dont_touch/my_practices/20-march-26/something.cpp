#include <iostream>
#include <vector>
using namespace std;

class Course
{
    string cname;
    double cprice;

public:
    Course() {}
    Course(string cname, double cprice)
    {
        this->cname = cname;
        this->cprice = cprice;
    }

    void accept()
    {
        cout << "---Enter cname: ";
        cin >> cname;
        cout << "---Enter cprice: ";
        cin >> cprice;
    }
    void display()
    {
        cout << "---cname: " << cname << endl;
        cout << "---cprice: " << cprice << endl;
    }
};

int menuList(vector<Course *> &clist)
{
    cout << "1. Add course" << endl;
    cout << "2. Display course" << endl;

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        Course *c = new Course();
        c->accept();
        clist.push_back(c);
        break;
    }
    case 2:
    {
        cout << "*****" << endl;
        for (int i = 0; i < clist.size(); i++)
        {
            clist[i]->display();
            cout << endl;
        }
        cout << "*****" << endl;
        break;
    }
    }
    return choice;
}

int main()
{

    vector<Course *> clist;

    while(menuList(clist) != 0){}

    return 0;
}