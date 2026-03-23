#include<iostream>
using namespace std;

int main(){

    int *ptr = new int[20];

    // int *ptr = (int *) malloc( 1 );

    cout << sizeof(int) << endl;


    for(int i=0; i <= 30; i++){
        ptr[i] = i*2 + 10;
    }

    // 24

    for(int i=0; i <= 30; i++){
        cout << ptr[i] << endl;
    }

    for(int i = 0; i <= 30; i++){
        delete[] ptr;
    }

    return 0;
}