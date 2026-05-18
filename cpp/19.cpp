/*
19. Create `list<int>` and store 10 random numbers.
Do the following operations one after
another.
- Display list in reverse order using iterator.
- Increment each number in the list by 5 using iterator.
- Display list in using const iterator.
- Sort the list using appropriate STL algorithm.
- Display modified list using default iterator.
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> myList = {10, 50, 60, 5, 90, 1, 5, 42, 15, 80};

    // print rever list
    list<int>::reverse_iterator rit;

    for (rit = myList.rbegin(); rit != myList.rend(); ++rit)
    {
        cout << *rit << endl;
    }

    cout << "Reversed Order: ";
    for (list<int>::reverse_iterator rit = myList.rbegin(); rit != myList.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;

    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
    {
        *it += 5;
    }

    cout << "After Incrementing (using const_iterator): ";
    for (list<int>::const_iterator cit = myList.cbegin(); cit != myList.cend(); ++cit)
    {
        cout << *cit << " ";
    }
    cout << endl;

    cout << "\n--- Sorting Operations ---" << endl;

    myList.sort();
    cout << "List has been sorted." << endl;

    cout << "Final Sorted List: ";
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}