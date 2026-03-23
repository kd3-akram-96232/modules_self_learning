#include<iostream>
#include<vector>

using namespace std;

template<typename T>

class Queue {

    vector<T> arr;

    public:
        Queue(){}

        void enqueue(T value){
            arr.push_back(value);
        }

        void dequeue(){
            arr.erase(arr.begin());
        }
        void printList(){
            cout << "************" << endl;
            for(int i = 0; i<arr.size(); i++){
                cout << "value: " << arr[i] << endl;
            }
            cout << "************" << endl;
        }

};

void printChoices(){
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. show queue" << endl;
}

int menuList(Queue<int> &queue){
    printChoices();

    int choice;
    cout << "Enter choice: ";
    cin >> choice;

    
    switch (choice)
    {
    case 1:{
        int value;
        cout << "Enter enqueue value: ";
        cin >> value;
        queue.enqueue(value);
        break;
    }
    
    case 2:
        queue.dequeue();
        cout << "ok" << endl;
        break;
    
    case 3:
        queue.printList();
        break;
    }

    

    return choice;
}

int main(){

    Queue<int> q;

    while(menuList(q) != 0);


    return 0;
}