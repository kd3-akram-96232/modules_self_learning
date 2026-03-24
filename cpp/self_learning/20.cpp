#include <iostream>
#include <memory> // Required for smart pointers

using namespace std;

class Resource {
public:
    Resource() { cout << "  [Resource Allocated in Memory]" << endl; }
    ~Resource() { cout << "  [Resource Destroyed & Memory Freed]" << endl; }
    void use() { cout << "  Using the resource..." << endl; }
};

int main() {
    cout << "unique_ptr (Ownership Transfer)" << endl;
    {
        unique_ptr<Resource> ptr1 = make_unique<Resource>();
        

        cout << "Transferring ownership from ptr1 to ptr2..." << endl;
        unique_ptr<Resource> ptr2 = std::move(ptr1); 

        if (ptr1 == nullptr) {
            cout << "ptr1 is now completely empty." << endl;
        }
        if (ptr2 != nullptr) {
            cout << "ptr2 now owns the memory: ";
            ptr2->use();
        }
    }


    cout << "2. shared_ptr (Shared Ownership)" << endl;
    {
        shared_ptr<Resource> shared1 = make_shared<Resource>();
        cout << "Reference Count (shared1): " << shared1.use_count() << endl;

        {
            shared_ptr<Resource> shared2 = shared1; 
            cout << "Reference Count after creating shared2: " << shared1.use_count() << endl;
        }

        cout << "Reference Count after shared2 was destroyed: " << shared1.use_count() << endl;
    }


    cout << "3. weak_ptr (Non-Owning Reference)" << endl;
    {
        shared_ptr<Resource> mainPtr = make_shared<Resource>();
        
        weak_ptr<Resource> weakPtr = mainPtr; 
        
        cout << "Reference Count after creating weakPtr: " << mainPtr.use_count() << " (Notice it didn't increase!)" << endl;

        if (shared_ptr<Resource> tempPtr = weakPtr.lock()) {
            cout << "Successfully locked weakPtr to access memory safely." << endl;
        }

        cout << "Manually destroying mainPtr early..." << endl;
        mainPtr.reset(); 

        if (weakPtr.expired()) {
            cout << "weakPtr recognizes the memory has been freed. No dangling pointer!" << endl;
        }
    }

    return 0;
}