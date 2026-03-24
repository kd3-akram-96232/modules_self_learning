#include <iostream>
#include <cstring>

using namespace std;

class Payment {
public:
    virtual void makePayment(double amount) = 0;
    
    virtual ~Payment() {} 
};

class CreditCard : public Payment {
public:
    void makePayment(double amount) override {
        cout << "[CreditCard] Processing payment of Rs. " << amount << "..." << endl;
        cout << "[CreditCard] Payment successful! Transaction recorded." << endl;
    }
};

class UPI : public Payment {
public:
    void makePayment(double amount) override {
        cout << "[UPI] Pinging UPI server for Rs. " << amount << "..." << endl;
        cout << "[UPI] Payment successful! Amount transferred." << endl;
    }
};

class Cash : public Payment {
public:
    void makePayment(double amount) override {
        cout << "[Cash] Receiving cash payment of Rs. " << amount << "..." << endl;
        cout << "[Cash] Payment successful! Change returned if any." << endl;
    }
};

class PaymentFactory {
public:
    static Payment* create(const char* mode) {
        if (strcmp(mode, "CreditCard") == 0) {
            return new CreditCard();
        } 
        else if (strcmp(mode, "UPI") == 0) {
            return new UPI();
        } 
        else if (strcmp(mode, "Cash") == 0) {
            return new Cash();
        } 
        else {
            cout << "Error: Unknown payment mode." << endl;
            return nullptr;
        }
    }
};

int main() {
    cout << "--- Testing Payment System ---" << endl << endl;

    double amountToPay = 2500.50;

    Payment* pay1 = PaymentFactory::create("UPI");
    if (pay1 != nullptr) {
        pay1->makePayment(amountToPay);
        delete pay1;
    }
    cout << endl;

    Payment* pay2 = PaymentFactory::create("CreditCard");
    if (pay2 != nullptr) {
        pay2->makePayment(15000.00);
        delete pay2; 
    }
    cout << endl;

    Payment* pay3 = PaymentFactory::create("Cash");
    if (pay3 != nullptr) {
        pay3->makePayment(450.00);
        delete pay3;
    }

    return 0;
}