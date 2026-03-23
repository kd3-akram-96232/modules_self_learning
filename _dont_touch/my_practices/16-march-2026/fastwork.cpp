#ifndef FastWork
#define FastWork

#include <iostream>
#include <variant>
#include <initializer_list>

using namespace std;

using DATA = variant<int, string, float, double, bool>;


namespace FastWork{

    
    void printList(initializer_list<DATA> list){
        for (const auto &item : list){
            visit([](auto &&arg)
            { cout << arg << endl; }, item);
        }
    }

    template <typename T>

    void takeInput(string msg, T &ref){
        cout << msg;
        cin >> ref;
    };

}


#endif