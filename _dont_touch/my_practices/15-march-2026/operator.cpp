// #include <iostream>
// using namespace std;
// int main(){

//     bool isActive = 12;

//     cout << !isActive <<endl;

//     return 0;
// }


#include<iostream>
using namespace std;

class A {
    const static int var = 10;

    void setVar(){
        // this->var = "Something"
    }
};

int main(){
    int a = 6;
    int b = 4;

    cout << "binary &: " << (a&b)<<endl;
    return 0;
}