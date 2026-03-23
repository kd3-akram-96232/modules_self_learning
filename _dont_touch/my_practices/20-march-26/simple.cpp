#include <iostream>
#include <string>
#include <exception>

using namespace std;

// User-Defined Exception
class InvalidPriceException : public exception {
public:
    const char* what() const throw() {
        return "Invalid input! Price/Charge cannot be negative.";
    }
};

// Base Class
class Servicing {
protected:
    string customerName;
    string vehicleNo;
    string mobileNo;
    double totalBill;

public:
    Servicing() : totalBill(0.0) {}
    virtual ~Servicing() {}

    // Getters and Setters
    void setCustomerName(string name) { customerName = name; }
    string getCustomerName() { return customerName; }

    void setVehicleNo(string vNo) { vehicleNo = vNo; }
    string getVehicleNo() { return vehicleNo; }

    void setMobileNo(string mNo) { mobileNo = mNo; }
    string getMobileNo() { return mobileNo; }

    void setTotalBill(double bill) { totalBill = bill; }
    double getTotalBill() { return totalBill; }

    virtual void calculateTotalBill() = 0;
    
    virtual void displayBill() {
        cout << "\n--- Bill Details ---\n";
        cout << "Customer Name: " << customerName << endl;
        cout << "Mobile Number: " << mobileNo << endl;
        cout << "Vehicle Number: " << vehicleNo << endl;
    }
    
    void inputBasicDetails() {
        cout << "Enter customer name: ";
        cin >> ws; getline(cin, customerName);
        cout << "Enter mobile number: ";
        cin >> mobileNo;
        cout << "Enter vehicle number: ";
        cin >> ws; getline(cin, vehicleNo);
    }
};

// Derived Class 1
class Maintenance : public Servicing {
private:
    string partName;
    double partPrice;
    double labourCharge;

public:
    void inputDetails() {
        inputBasicDetails();
        cout << "Enter part name to be replaced: ";
        cin >> ws; getline(cin, partName);
        cout << "Enter part price: ";
        cin >> partPrice;
        cout << "Enter labour charge: ";
        cin >> labourCharge;

        if (partPrice < 0 || labourCharge < 0) {
            throw InvalidPriceException();
        }
    }

    void calculateTotalBill() override {
        double partWithGST = partPrice + (partPrice * 0.05); // 5% GST on part
        double labourWithGST = labourCharge + (labourCharge * 0.05); // 5% GST on labour
        totalBill = partWithGST + labourWithGST;
    }

    void displayBill() override {
        Servicing::displayBill();
        cout << "Service Type: Maintenance / Repairing\n";
        cout << "Part Replaced: " << partName << " (Rs. " << partPrice << ")\n";
        cout << "Labour Charge: Rs. " << labourCharge << "\n";
        cout << "Total Bill (inclusive of 5% GST): Rs. " << totalBill << endl;
    }
};

// Derived Class 2
class OilChange : public Servicing {
private:
    string oilName;
    double oilPrice;

public:
    void inputDetails() {
        inputBasicDetails();
        cout << "Enter oil brand name: ";
        cin >> ws; getline(cin, oilName);
        cout << "Enter oil price: ";
        cin >> oilPrice;

        if (oilPrice < 0) {
            throw InvalidPriceException();
        }
    }

    void calculateTotalBill() override {
        totalBill = oilPrice + (oilPrice * 0.12); // 12% GST on oil
    }

    void displayBill() override {
        Servicing::displayBill();
        cout << "Service Type: Engine / Gear Oil Change\n";
        cout << "Oil Brand: " << oilName << " (Rs. " << oilPrice << ")\n";
        cout << "Total Bill (inclusive of 12% GST): Rs. " << totalBill << endl;
    }
};

int main() {
    int choice;
    do {
        cout << "\n--- Vehicle Service Station ---\n";
        cout << "1. Maintenance / Repairing\n";
        cout << "2. Engine / Gear Oil Change\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            if (choice == 1) {
                Maintenance m;
                m.inputDetails();
                m.calculateTotalBill();
                m.displayBill();
            } else if (choice == 2) {
                OilChange o;
                o.inputDetails();
                o.calculateTotalBill();
                o.displayBill();
            } else if (choice == 3) {
                cout << "Exiting program...\n";
            } else {
                cout << "Invalid choice! Please try again.\n";
            }
        } catch (const InvalidPriceException& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 3);

    return 0;
}