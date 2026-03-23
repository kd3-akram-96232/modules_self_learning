#include<iostream>
using namespace std;

int main(){

    int number  = 23;
    int number2 = 3;

    const int * ptr = &number;
    // ptr = &number2;
    // *ptr = 23523;

    // int *ptr = &number; 
    // ptr = &number2;
    // *ptr = 24324;


    printf("%d", number);
    printf("%d", number2);

    return 0;
}