#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial_balance = 0.0) : balance(initial_balance) {}

    void deposit(double amount) {
        if (amount < 0) {
            throw amount;
        }
        balance += amount;
        cout << "Deposited: Rs. " << amount << " | New Balance: Rs. " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount < 0) {
            throw amount;
        }
        if (amount > balance) {
            throw string("Withdrawal failed: Insufficient balance!"); 
        }
        balance -= amount;
        cout << "Withdrew: Rs. " << amount << " | New Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount myAccount(5000.0);

    try {
        cout << "Attempting to deposit Rs. 2000..." << endl;
        myAccount.deposit(2000.0);

        cout << "\nAttempting to withdraw Rs. -500..." << endl;
        myAccount.withdraw(-500.0);
        
        cout << "\nAttempting to withdraw Rs. 10000..." << endl;
        myAccount.withdraw(10000.0); 
    }
    catch (double negativeAmount) {
        cout << "Error: Cannot process a negative amount (Rs. " << negativeAmount << ")." << endl;
    }
    catch (const string& errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }

    return 0;
}