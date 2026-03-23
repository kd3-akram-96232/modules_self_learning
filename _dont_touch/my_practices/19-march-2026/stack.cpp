#include<iostream>
using namespace std;

// template<typename T>

class MyStack {
    int size;
    int *arr;
    int top = -1;

    public:
        MyStack(int size){
                arr = new int[size];
        }

        void push(int value){
            top++;
            arr[top] = value;
        }

        void pop(){
            top --;
        }

        int peek(){
            return this->arr[top];
        }
};

int main(){
    MyStack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << stack.peek() << endl;
    
    stack.pop();
    
    cout << stack.peek() << endl;
    
    stack.push(40);
    
    cout << stack.peek() << endl;

    return 0;
}