#include <iostream>
using namespace std;

class Student{
	string name;
	int rollNumber;

	Student(string name, int rollNumber){
		this->name = name;
		this->rollNumber = rollNumber;
	}

	void setName(string name, int rollNumber){
		this->name = name;
	}

	string getName(){
		return this->name;
	}
	
	void setRollNumber(int rollNumber){
		this->rollNumber = rollNumber;
	}

	int getRollNumber() {
		return this->rollNumber;
	}

	void printStudent() {
		cout << "Name: " << this->name << endl;
		cout << "Roll: " << this->rollNumber << endl;
	}


}

int main(){

	Student student("Akram", 121212);

	student.printStudent();
}
