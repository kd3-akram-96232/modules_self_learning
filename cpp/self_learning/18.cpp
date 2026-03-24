// 18. Write a generic class for `Array` to store user-defined data types using templates.
// Overload required operators. Prevent memory leakage.

#include<iostream>
using namespace std;

template<typename T>

class Array {
    T *arr;
    int size;

    public:
        Array(int size){
            this->size = size;
            arr = new T[size];
        }

        void push(int index, T value){
            arr[index] = value;
        }

        T getAt(int index){
            return arr[index];
        }

};

int main(){

    Array<string> arr(5);
    arr.push(0, "Akram");
    arr.push(1, "Khan");
    arr.push(2, "Something");

    cout << arr.getAt(0) << endl;
    cout << arr.getAt(1) << endl;

    return 0;
}