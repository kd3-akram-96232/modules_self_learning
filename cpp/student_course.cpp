#include<iostream>
#include<vector>
using namespace std;

class Course {
	int courseId;
	string courseName;

	public:
		Course(){}
		Course(int courseId, string courseName) {
			this->courseId = courseId;
			this->courseName = courseName;
		}

		void setCourseId(int courseId){
			this->courseId = courseId;
		}

		int getCourseId(){
			return this->courseId;
		}

		void setCourseName(int courseName){
			this->courseName = courseName;
		}

		string getCourseName(){
			return this->courseName;
		}

		void acceptCourse(){
			cout << "-----Enter course id: ";
			cin >> courseId;
			cout << "-----Enter course name: ";
			cin >> courseName;
		}
		void displayCourse(){
			 cout << " - " << this->courseId << " " << this->courseName << endl;
		}
};

class Student {
	int rollNumber;
	string studentName;
	vector<Course*> studentCourses;

	public:
	Student(){}
	Student(int rollNumber, string studentName){
		this->rollNumber = rollNumber;
		this->studentName = studentName;	
	}

	void setRollNumber(int rollNumber){
		this->rollNumber = rollNumber;
	}
	int getRollNumber(){
		return this->rollNumber;
	}

	void setStudentName(string studentName){
		this->studentName = studentName;
	}
	string getStudentName(){
		return this->studentName;
	}

	void acceptStudent(){
		cout << "-----Enter roll number: ";
		cin >> this->rollNumber;
		cout << "-----Enter student name: ";
		cin >> this->studentName;
	}

	void displayStudent(){
		cout << " - " << rollNumber  << " " << studentName << endl;
	}

	void displayStudentWithCourses(){
		cout << " - " << rollNumber  << " " << studentName << endl;
		for(int i = 0; i < studentCourses.size(); i++){
			const int courseId =  studentCourses.at(i)->getCourseId();
			const string courseName = studentCourses.at(i)->getCourseName();
			cout << " --- " << courseId  << " " << courseName << endl;
		}
	}

	void addCourse(Course* ptr){
		studentCourses.push_back(ptr);
	}
};