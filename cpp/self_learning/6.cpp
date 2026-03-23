#include<iostream>
using namespace std;


class Customer {
    
};


class BankAccount {
    int accountNumber;
    string accountHolderName;
    double balance;

    public:
    BankAccount(): accountNumber(0), accountHolderName(""), balance(0){}

    void deposit(double money){
        this->balance = this->balance + money;
    }

    void withdrawal(double money){
        if(this->balance >= money){

            this->balance = this->balance - money;
        }else{
            cout << "Insufficient balance" << endl;
        }
    }

    void displayBalance(){
        cout << "Balance: " << this->balance<<endl;
    }
};

int main(){

    BankAccount ba;

    ba.deposit(5000);
    ba.deposit(1000);
    ba.displayBalance();
    ba.withdrawal(5000);
    // ba.withdrawal(1100);

    ba.displayBalance();

    return 0;
}