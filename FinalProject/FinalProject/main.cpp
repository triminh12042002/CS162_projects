#include <iostream>
#include <string>
#include <fstream>
#include "function.h"
#include "Header.h"
using namespace std;

void inputStudentData(Student* &pHeadStudent, Student* &pTailStudent, char path[]) {
	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open())
	{
		cout << "Khong mo duoc file!";
		return;
	}
	Student* pTemp = nullptr;
	int n;
	ifs >> n;
	string temp;
	getline(ifs,temp,'\n');
	for(int i = 0 ; i < n; ++i) {
		pTemp = new Student;
		pTemp->pNext = nullptr;
		getline(ifs, pTemp->no, ',');
		getline(ifs, pTemp->id, ',');
		getline(ifs, pTemp->firstName, ',');
		getline(ifs, pTemp->lastName, ',');
		getline(ifs, pTemp->gender, ',');
		getline(ifs, pTemp->dateOfBirth, ',');
		getline(ifs, pTemp->socialId, '\n');
		if (pTailStudent != nullptr) {
			pTailStudent->pNext = pTemp;
			pTailStudent = pTemp;
		}
		else {
			pHeadStudent = pTailStudent = pTemp;
		}
	}
}
void OutputCSVFIle(Student* pHeadStudent, char path[]) {
	if (pHeadStudent == nullptr) return;
	ofstream ofs;
	ofs.open(path);
	if (!ofs.is_open()) {
		cout << "Khong mo duoc file.";
		return;
	}
	Student* pCur = pHeadStudent;
	int count = 0;
	while (pCur != nullptr) {
		count += 1;
		pCur = pCur->pNext;
	}
	ofs << count << "\n";
	pCur = pHeadStudent;
	while (pCur != nullptr) {
		ofs << pCur->no << ",";
		ofs << pCur->id << ",";
		ofs << pCur->firstName << ",";
		ofs << pCur->lastName << ",";
		ofs << pCur->gender << ",";
		ofs << pCur->dateOfBirth << ",";
		ofs << pCur->socialId << "\n";
		pCur = pCur->pNext;
	}
}
void signUp(){
	string us,pw;
	
	cout << "Enter username : "; cin >> us;
	cout << "Enter password : "; cin >> pw;
	
	ofstream write;
	write.open("loginData.txt",ios::app);
	write << us << ',' << pw << '\n'; 
	write.close();
}
bool login(account* &pLogin, string loginPath)
{
	
	string username, password;
	cout << "Enter username : "; 
	getline(cin, username);
	cout << "Enter password : "; 
	getline(cin, password);
	
	account* pCur = nullptr;
	
	ifstream read;
	read.open(loginPath);
	while (!read.eof())
	{
		if (pCur == nullptr) {
			pLogin = pCur = new account;
			pCur->next = nullptr;
		}
		else {
			pCur->next = new account;
			pCur = pCur->next;
		}
		
		getline(read, pCur->us, ',');
		getline(read, pCur->pw, '\n');

	}
	pCur = pLogin;
	while (pCur != nullptr)
	{
		if (pCur->us == username && pCur->pw == password)
			return true;
		else pCur = pCur->next;
	}
	return false;
	read.close();
}
void createSchoolYear(SchoolYear* &pHeadSchoolYear) {
	pHeadSchoolYear = new SchoolYear;
	pHeadSchoolYear->pNext = nullptr;
	pHeadSchoolYear->pHeadSemester = nullptr;
	cout << "Enter school year's name\n";
	getline(cin, pHeadSchoolYear->schoolYearName);
}
void addAllStudentsToClass(Class* &pClass) {
	if (pClass == nullptr) {
		pClass = new Class;		
	}
	pClass->pHeadStudent = nullptr;
	pClass->pTailStudent = nullptr;
	char inputPath[] = "input.csv";
	inputStudentData(pClass->pHeadStudent, pClass->pTailStudent, inputPath);
}
void create1Student(Student* &pStudent) {
	if (pStudent == nullptr) {
		pStudent = new Student;
	}
	cout << "Enter student data\n";
	cout << "no: ";
	getline(cin,pStudent->no);
	cout << "id: ";
	getline(cin, pStudent->id);
	cout << "firstName: ";
	getline(cin, pStudent->firstName);
	cout << "lastName: ";
	getline(cin, pStudent->lastName);
	cout << "gender: ";
	getline(cin, pStudent->gender);
	cout << "dateOfBirth: ";
	getline(cin, pStudent->dateOfBirth);
	cout << "socialId: ";
	getline(cin, pStudent->socialId);
	pStudent->pNext = nullptr;
}
void add1StudentToClass(Class* &pClass) {
	if (pClass == nullptr) {
		pClass = new Class;
	}
	Student* pStudent = new Student;
	create1Student(pStudent);
	pClass->pTailStudent->pNext = pStudent;
	pClass->pTailStudent = pStudent;
}
void deleteCourse(Semester *pHead){
	string nameOfCourse, idOfCourse;
	cout << "Input name of the course that you want to delete : "; cin >> nameOfCourse;
	cout << "Input id of the course that you want to delete : "; cin >> idOfCourse;
	
	Course *courseHead = pHead->pHeadCourse;
	if (courseHead->courseName.compare(nameOfCourse)==0&&courseHead->id.compare(idOfCourse)==0{
		pHead->pHeadCourse = courseHead->pNext;
		delete courseHead;
		return;
	}
	    
	Course *temp = courseHead;
	courseHead = courseHead->pNext;	
	while (courseHead){
		if (courseHead->courseName.compare(nameOfCourse)==0&&courseHead->id.compare(idOfCourse)==0){
			temp->pNext = courseHead->pNext;
			delete courseHead;
			return;
		}
		temp = courseHead;
		courseHead = courseHead->pNext;
	}
	cout << "The course that you want to delete does not exits in this semester. " << endl;
	return;
}
void addCourseToSemester(Semester *pHead){
	Course *newCourse = new Course;
	string startDate1,endDate1,courseName1,id1,teacherName1,numOfCredits1,maxNumOfStudents1,day1x,hour1x,day2x,hour2x;
	
	cout << "Input course start date : "; cin >> startDate1;
	newCourse->startDate = startDate1;
	
	cout << "Input course end date : "; cin >> endDate1;
	newCourse->endDate = endDate1;
	
	cout << "Input course name : "; cin >> courseName1;
	newCourse->courseName = courseName1;
	
	cout << "Input course id : "; cin >> id1;
	newCourse->id = id1;
	
	cout << "Input teacher name : "; cin >> teacherName1;
	newCourse->teacherName = teacherName1;
	
	cout << "Input number of credits in the course : "; cin >> numOfCredits1;
	newCourse->numOfCredits = numOfCredits1;
	
	cout << "Input the maximun number of students : "; cin >> maxNumOfStudents1;
	newCourse->maxNumOfStudents = maxNumOfStudents1;
	
	cout << "Input day 1 : "; cin >> day1x;
	newCourse->day1 = day1x;
	
	cout << "Input hour 1 : " cin >> hour1x;
	newCourse->hour1 = hour1x;
	
	cout << "Input day 2 : "; cin >> day2x;
	newCourse->day2 = day2x;
	
	cout << "Input hour 2 : "; cin >> hour2x;
	newCourse->hour2 = hour2x;
	
	Course *temp = pHead->pHeadCourse;
	while (temp->pNext)
		temp = temp->pNext;
	temp-pNext = newCourse;
}
int main() {

	// input student from csv file to a list
	// output student data to a csv file

	/*Student* pHeadStudent = nullptr;
	Student* pTailStudent = nullptr;
	char inputPath[] = "input.csv";
	inputStudentData(pHeadStudent, pTailStudent, inputPath);
	Student* pTemp = pHeadStudent;
	while (pTemp != nullptr) {
		cout << pTemp->firstName << endl;
		pTemp = pTemp->pNext;
	}
	cout << endl;
	char outputPath[] = "output.csv";
	OutputCSVFIle(pHeadStudent, outputPath);*/
	

	/*signUp();
	string temp;
	getline(cin, temp);
	*/


	/*account* pLogin = nullptr;
	string loginPath = "loginData.txt";
	cout << login(pLogin, loginPath);
	*/

	/*
	// create 1 class
	Class* pClass = new Class;	
	// input student data from csv file to class list of student
	addAllStudentsToClass(pClass);
	// add 1 more student to this class
	add1StudentToClass(pClass);
	cout << "tail: " << pClass->pTailStudent->no;
	*/
	return 0;
}
