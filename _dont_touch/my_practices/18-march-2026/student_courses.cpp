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

// Store initially all courses in vector list
void storeAllCoursesInList(vector<Course*> &courseList){
	courseList.push_back(new Course(1, "Java"));
	courseList.push_back(new Course(2, "C"));
	courseList.push_back(new Course(3, "C++"));
	courseList.push_back(new Course(4, "Golang"));
	courseList.push_back(new Course(5, "Lamborge"));
}
// Store initially all Students in vector list
void storeAllStudentsInList(vector<Student*> &studentList){
	studentList.push_back(new Student(1001, "Akram"));
	studentList.push_back(new Student(1002, "Akash"));
	studentList.push_back(new Student(1003, "Mahesh"));
	studentList.push_back(new Student(1004, "Vijay"));
	studentList.push_back(new Student(1005, "Tejas"));
}

// display all courses for menu.
void displayAllCourses(vector<Course*> courseList){
	cout << endl;
	cout << "Courses:-"<<endl;
	for(int i = 0; i < courseList.size(); i++){
		courseList[i]->displayCourse();
	}
	cout << "*******"<<endl;

}
// display all students for menu.
void displayAllStudents(vector<Student*> studentList){
	cout << endl;
	cout << "Students:-"<<endl;
	
	for(int i = 0; i < studentList.size(); i++){
		studentList[i]->displayStudent();
	}
	cout << "*******"<<endl;
}

// get course index using value
int getStudentIndexByRollnumber(vector<Student*> studentList, int rollNumber){
	for(int i = 0; i < studentList.size(); i++){
		const int rNumber = studentList.at(i)->getRollNumber();
		if(rollNumber == rNumber){
			return i;
		}	
	}

	return -1;
}

void displayStudentWithCoursesByRollnumber(vector<Student*> studentList){

	int rollNumber;
	cout << "---Enter roll number: ";
	cin >> rollNumber;

	cout << endl;
	cout << "Student:-"<<endl;
	
	for(int i = 0; i < studentList.size(); i++){

		if(i == getStudentIndexByRollnumber(studentList, rollNumber)){
			studentList[i]->displayStudentWithCourses();
		}
	}
	cout << "*******"<<endl;
}

void displayAllStudentsWithCoursesByRollnumber(vector<Student*> studentList){

	cout << endl;
	cout << "Students:-"<<endl;
	
	for(int i = 0; i < studentList.size(); i++){
			studentList[i]->displayStudentWithCourses();
	}
	cout << "*******"<<endl;
}

// get student index using value
int getCourseIndexByCourseId(vector<Course*> courseList, int courseId){
	for(int i = 0; i < courseList.size(); i++){
		const int cId =  courseList.at(i)->getCourseId();
		if(courseId == cId){
			return i;
		}
	}

	return -1;
}

// assign Course to any Student
void assignCourseToStudent(vector<Student*> &studentList, vector<Course*> courseList){

	int rollNumber;
	int courseId;

	// take from user
	cout << "---Enter Roll number: ";
	cin>>rollNumber;
	cout << "---Enter courseId: ";
	cin>>courseId;

	const int studentIndex = getStudentIndexByRollnumber(studentList, rollNumber);
	const int courseIndex = getCourseIndexByCourseId(courseList, courseId);

	if(studentIndex == -1){
		cout << "-------You enter wrong student roll number.-------"<<endl;
		return;
	}
	if(courseIndex == -1){
		cout << "-------You enter wrong course id.-------"<<endl;
		return;
	}

	// add course in student
	studentList[studentIndex]->addCourse(courseList[courseIndex]);
}

void printActions(){
	cout << "++++++++++++++"<<endl;
	cout << "1. Add Course"<<endl;
	cout << "2. Add Student"<<endl;
	cout << "3. Display all courses"<<endl;
	cout << "4. Display All students"<<endl;
	cout << "5. Perchase course"<<endl;
	cout << "6. Display all student with courses"<<endl;
	cout << "7. Display perticular student with courses"<<endl;
	cout << "0. Exit!"<<endl;
	cout << "++++++++++++++"<<endl;
}

// create user menu list
int menuList(vector<Student*> &studentList, vector<Course*> &courseList){
	printActions();
	int choice = 0;
	cout << "Enter choice: ";
	cin >> choice;

	switch (choice){
	case 1:{
		Course *c = new Course();
		c->acceptCourse();
		courseList.push_back(c);
		break;
	}
	case 2:{
		Student *s = new Student();
		s->acceptStudent();
		studentList.push_back(s);
		break;
	}
	case 3:
		displayAllCourses(courseList);
		break;
	case 4:
		displayAllStudents(studentList);
		break;
	case 5:
		assignCourseToStudent(studentList, courseList);
		break;
	case 6:
		displayAllStudentsWithCoursesByRollnumber(studentList);
		break;
	case 7:
		displayStudentWithCoursesByRollnumber(studentList);
		break;
	}

	return choice;

}

int main(){

	vector<Student*> studentList;
	vector<Course*> courseList;

	// add initial courses;
	storeAllCoursesInList(courseList);
	// add initial students;
	storeAllStudentsInList(studentList);

	// run menulist in loops
	while(menuList(studentList, courseList) != 0);

	return 0;
}