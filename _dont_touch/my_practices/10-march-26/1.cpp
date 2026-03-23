#include <iostream>
using namespace std;

int handleActions()
{
    int action;
    int val;
    cout << "Choose option: ";
    cin >> action;

    switch (action)
    {
    case 1:
        cout << "Enter Val: ";
        cin >> val;
        return 1;
    case 2:
        cout << "Value is: " << val << endl;
        return 1;

    case 0:
        return 0;
    default:
        cout << "You choose wrong option" << endl;
        return 0;
    }
}

int main()
{

    cout << "Actions" << endl;
    cout << "1: add value" << endl;
    cout << "2: print value" << endl;
    cout << "0: Exit." << endl;

    while (handleActions() != 0)
    {
    }
}