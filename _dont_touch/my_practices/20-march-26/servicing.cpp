#include <iostream>
using namespace std;

class ErrorHandling {
    string msg;
    public:
    ErrorHandling(string msg){
        this->msg = msg;
    }

    string getMessage(){
        return msg;
    }
};

class Servicing
{
    string customerName;
    string vehicleNo;
    string mobileNo;
    double totalBill;

public:
    Servicing() {}
    Servicing(string customerName, string vehicleNo, string mobileNo)
    {
        this->customerName = customerName;
        this->vehicleNo = vehicleNo;
        this->mobileNo = mobileNo;
    }

    void accept()
    {
        cout << "---Enter customer name: ";
        cin >> customerName;
        // ;getline(cin, customerName);
        cout << "---Enter vehicleNo: ";
        cin >> vehicleNo;
        cout << "---Enter mobileNo: ";
        cin >> mobileNo;
    }

    string getCustomerName() const
    {
        return customerName;
    }

    void setCustomerName(string value)
    {
        customerName = value;
    }

    string getVehicleNo() const
    {
        return vehicleNo;
    }

    void setVehicleNo(string value)
    {
        vehicleNo = value;
    }

    string getMobileNo() const
    {
        return mobileNo;
    }

    void setMobileNo(string value)
    {
        mobileNo = value;
    }

    void setTotalBill(double total_bill)
    {
        this->totalBill = total_bill;
    }

    double getTotalBill()
    {
        return totalBill;
    }

    virtual void calculateTotalBill() = 0;

    virtual void displayBill() = 0;
};

class Maintenence : public Servicing
{
    string partName;
    double partPrice;
    double labourCharge;

public:
    Maintenence() {}
    Maintenence(string partName, double partPrice, double labourCharge)
    {
        this->partName = partName;
        this->partPrice = partPrice;
        this->labourCharge = labourCharge;
    }

    void accept()
    {
        Servicing::accept();
        cout << "---Enter partname: ";
        // getline(cin, partName);
        cin >> partName;
        cout << "---Enter part price: ";
        cin >> partPrice;
        cout << "---Enter labourcharge: ";
        cin >> labourCharge;

        if(partPrice < 0 || labourCharge < 0){
            throw ErrorHandling("invalid price.");
        }

        // if(partPrice < 0){
        // throw ""
        // }
    }

    string getPartName() const
    {
        return partName;
    }

    void setPartName(string value)
    {
        partName = value;
    }

    double getPartPrice() const
    {
        return partPrice;
    }

    void setPartPrice(double value)
    {
        partPrice = value;
    }

    double getLabourCharge() const
    {
        return labourCharge;
    }

    void setLabourCharge(double value)
    {
        labourCharge = value;
    }

    void calculateTotalBill() override
    {
        double partPriceWithGst = (partPrice * 0.05) + partPrice;
        double labourChargeWithGst = labourCharge * 0.05 + labourCharge;

        this->setTotalBill(partPriceWithGst + labourChargeWithGst);
    }

    void displayBill()
    {
        cout << "Maintanance total bill with gst: " << this->getTotalBill() << endl;
    }
};

class OilChange : Servicing
{
    string oilName;
    double oilPrice;

public:
    OilChange() {}
    OilChange(string oilName, double oilPrice)
    {
        this->oilName = oilName;
        this->oilPrice = oilPrice;
    }

    void accept()
    {
        Servicing::accept();
        cout << "---Enter oil name: ";
        cin >> oilName;
        cout << "---Enter oil price: ";
        cin >> oilPrice;

        if(oilPrice < 0){
            throw ErrorHandling("invalid price.");
        }
    }

    string getOilName() const
    {
        return oilName;
    }

    void setOilName(string value)
    {
        oilName = value;
    }

    double getOilPrice() const
    {
        return oilPrice;
    }

    void setOilPrice(double value)
    {
        oilPrice = value;
    }

    void calculateTotalBill() override
    {
        double oilPriceWithGst = (oilPrice * 0.15) + oilPrice;

        this->setTotalBill(oilPriceWithGst);
    }

    void displayBill()
    {
        cout << "Oil change total bill with gst: " << this->getTotalBill() << endl;
    }
};

void printChoices()
{
    cout << "1. Maintanence" << endl;
    cout << "2. oil Change" << endl;
}

int menuList()
{
    printChoices();
    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    try{


    switch (choice)
    {
    case 1:
    {
        Maintenence *m = new Maintenence();
        m->accept();
        m->calculateTotalBill();
        m->displayBill();
        delete m;
        break;
    }
    case 2:
    {
        OilChange *o = new OilChange();
        o->accept();
        o->calculateTotalBill();
        o->displayBill();
        delete o;
        break;
    }
    default:
        break;
    }

    }
    catch(ErrorHandling e){
        cout << e.getMessage() << endl;
    }


    return choice;
}

int main()
{


    while (menuList() != 0)
    {
    }

    return 0;
}
