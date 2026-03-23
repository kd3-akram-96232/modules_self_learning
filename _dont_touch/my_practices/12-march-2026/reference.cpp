#include <iostream>
using namespace std;


void swapWithPointer(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void swapWithReference(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    int a = 10;
    int b = 20;

    swapWithPointer(&a, &b);
    swapWithReference(a, b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}