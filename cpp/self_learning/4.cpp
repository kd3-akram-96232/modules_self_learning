#include <iostream>
using namespace std;

class Laptop{
    int brandId;
    int price;

    public:
    Laptop(): brandId(1), price(50000){
        cout << "Laptop constructor called"<<endl;
    }

    ~Laptop(){
        cout << "Laptop Destructor called";
    }
};

int main(){

    Laptop lp;

    return 0;
}