class Base{
   public:

   virtual void f1(){

   }
};

class Derived : public Base {
    void f1() override {

    }
    // void f2() override {
        
    // }
};


int main(){

    Derived d;
    // d.f1();

    return 0;
}