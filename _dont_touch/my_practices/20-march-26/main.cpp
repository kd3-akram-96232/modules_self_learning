#include<iostream>
using namespace std;

class Servicing {
    string customerName;
    string vehicleNo;
    string mobileNo;
    double totalBill;

    public:
    Servicing(): totalBill(0.0){}
    Servicing(string customerName, string vehicleNo, string mobileNo){
        this->customerName = customerName;
        this->vehicleNo = vehicleNo;
        this->mobileNo = mobileNo;
        this->totalBill = 0.0;
    }

    string getCustomerName() const {
        return customerName;
    }

    void setCustomerName(string value) {
        customerName = value;
    }

    string getVehicleNo() const {
        return vehicleNo;
    }

    void setVehicleNo(string value) {
        vehicleNo = value;
    }

    string getMobileNo() const {
        return mobileNo;
    }

    void setMobileNo(string value) {
        mobileNo = value;
    }

    double getTotalBill() const {
        return totalBill;
    }

    void setTotalBill(double value) {
        totalBill = value;
    }

    void accept(){
        cout << "*****Basic Information*****" <<  endl;
        cout << "Enter customer name: ";
        cin >> customerName;
        cout << "Enter vehicle no: ";
        cin >> vehicleNo;
        cout << "Enter mobile no: ";
        cin >> mobileNo;
        cout << "---";
    }

    virtual void calculateTotalBill() = 0;
    virtual void displayBill() = 0;
};

class Maintenance : public Servicing{
    string partName;
    double partPrice;
    double labourCharge;

public: 
    Maintenance(): partPrice(0), labourCharge(0){}
    Maintenance(string partName, double partPrice, double labourCharge){
        this->partName = partName;
        this->partPrice = partPrice;
        this->labourCharge = labourCharge;
    }

    string getPartName() const {
        return partName;
    }

    void setPartName(string value) {
        partName = value;
    }

    double getPartPrice() const {
        return partPrice;
    }

    void setPartPrice(double value) {
        partPrice = value;
    }

    double getLabourCharge() const {
        return labourCharge;
    }

    void setLabourCharge(double value) {
        labourCharge = value;
    }

    void accept(){
        Servicing::accept();
        cout << "So which part do you replace?: ";
        cin >> partName;
        cout << "Enter part price: ";
        cin >> partPrice;
        cout << "Enter labour charge: ";
        cin >> labourCharge;
    }

    void calculateTotalBill(){
        
    }

    void displayBill(){

    }

    
};

class OilChange : public Servicing{
    string oilName;
    double oilPrice;

public:
    OilChange(){}
    OilChange(string oilName, double oilPrice){
        this->oilName = oilName;
        this->oilPrice = oilPrice;
    }

    string getOilName() const {
        return oilName;
    }

    void setOilName(string value) {
        oilName = value;
    }

    double getOilPrice() const {
        return oilPrice;
    }

    void setOilPrice(double value) {
        oilPrice = value;
    }

    void accept(){

    }

    
};

int main(){
    return 0;

}