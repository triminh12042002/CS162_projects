#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
void CreateYear(Year* pHeadYear) {
	cout << "Please enter the schoolyear (e.g. School year 2020-2021, input 2020); 0= exit: ";
	int x;
	cin >> x;
	if (!pHeadYear) {
		pHeadYear = new Year;
		pHeadYear->Start = x;
		pHeadYear->End = x + 1;
		pHeadYear->pNextYear = nullptr;
		return;
	}
	Year* pCurYear = pHeadYear->pNextYear;
	while (pHeadYear && x != 0;) {
		pCurYear = new Year;
		pCurYear->Start = x;
		pCurYear->End = x + 1;
		pCurYear = pCurYear->pNextYear;
		cout << "Please enter the schoolyear (e.g. School year 2020-2021, input 2020); 0= exit: ";
		cin >> x;
	}
void CreateClass(Student* pHeadStudent) {
	Class* pHeadClass = new Class;
	Class* pCurClass = pHeadClass;
	Student* pCurStudent = pHeadClass->pHeadStudent;
	while (pCurClass != nullptr) {
		while (pCurStudent != pCurClass->pTailStudent) {
			//Input Student
			pCurStudent = pCurStudent->pNextStudent;
		}
		int Fin;
		cout << "Move to the next Class? (1= Next, 0= Exit): ";
		cin >> Fin;
		if (Fin == 0) {
			pCurClass->pNext = nullptr;
			pCurClass = pCurClass->pNext;
		}
		else {
			pCurClass->pNext = new Class;
			pCurClass = pCurCLass->pNext;
		}
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
void deleteCourse(Semester *&pHead){
	string nameOfCourse, idOfCourse;
	cout << "Input name of the course that you want to delete : "; cin >> nameOfCourse;
	
	Course *courseHead = pHead->pHeadCourse;
	if (courseHead->courseName == nameOfCourse){
		pHead->pHeadCourse = courseHead->pNext;
		delete courseHead;
		return;
	}
	    
	Course *temp = courseHead;
	courseHead = courseHead->pNext;	
	while (courseHead){
		if (courseHead->courseName == nameOfCourse){
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
void addCourseToSemester(Semester *&pHead){
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
	
	cout << "Input hour 1 : "; cin >> hour1x;
	newCourse->hour1 = hour1x;
	
	cout << "Input day 2 : "; cin >> day2x;
	newCourse->day2 = day2x;
	
	cout << "Input hour 2 : "; cin >> hour2x;
	newCourse->hour2 = hour2x;
	
	Course *temp = pHead->pHeadCourse;
	while (temp->pNext)
		temp = temp->pNext;
	temp->pNext = newCourse;
}
void CreateCourseRegistration(Course*& pHeadCourse, Semester* pSemester, string path)
{
	ofstream read;
	read.open(path + pSemester->semesterName + "RegistrationDate", ios::app);//string path="semester";
	Course* pCur = nullptr;
	if (pHeadCourse == nullptr)
	{
		pHeadCourse = new Course;
		pHeadCourse->pNext = nullptr;
	}
	pCur = pHeadCourse;
	cout << "The Date of Starting a Course Registration";
	cin >> pCur->startDate;
	cout << "The Date of Ending a Course Registration";
	cin >> pCur->endDate;
	read << pCur->startDate << ',' << pCur->endDate << '\n';
	read.close();
	//There is a file for saving Date of Registration
}
void SemesterOfYear(Semester*& pSemester, Course*& pHeadCourse, char* path) //char path="semester"
{
	ofstream read;
	read.open(path, ios::app);
	Semester* pCur = nullptr;
	int i = 1;
	while (i <= 3)
	{
		if (pSemester == nullptr)
		{
			pSemester = new Semester;
			pSemester->pNext = nullptr;
			pCur = pSemester;
		}
		cout << "The Semester: ";
		cin >> pCur->semesterName;
		cout << "School Year: ";
		cin >> pCur->schoolYear;
		cout << "The Date of Starting semester: ";
		cin >> pCur->startDate;
		cout << "The Date of Ending semester: ";
		cin >> pCur->endDate;
		read << pCur->schoolYear << ',' <<pCur->semesterName << ',' << pCur->startDate << ',' <<pCur-> endDate << '\n';
		CreateCourseRegistration(pCur->pHeadCourse, pCur, path);
		//Create new semester
		pCur->pNext = new Semester;
		pCur = pCur->pNext;
	}
	pCur = nullptr;
	read.close();
}
void UpdateCourseInformation(Course*& pHeadCourse, char* path)// string path="semester"
{
	ifstream read;
	read.open(path);
	ofstream write;
	Course* pCur = nullptr;
	string searchIdCourse;
	while (!read.eof())
	{
		if (pHeadCourse == nullptr)
		{
			pHeadCourse = new Course;
			pCur = pHeadCourse;
		}
		else {
			pCur->pNext = new Course;
			pCur = pCur->pNext;
		}
		getline(read, pCur->courseName, ',');
		getline(read, pCur->id, ',');
		getline(read, pCur->teacherName, ',');
		getline(read, pCur->numOfCredits, ',');
		getline(read, pCur->maxNumOfStudents, ',');
		getline(read, pCur->day1, ',');
		getline(read, pCur->hour1, ',');
		getline(read, pCur->day2, ',');
		getline(read, pCur->hour2, '\n');
		pCur->pNext = nullptr;
	}
	//
	pCur = pHeadCourse;
	cout << "Which Course do you want to Update? Please Input the ID Course: ";
	getline(cin, searchIdCourse);
	while (pCur != nullptr && pCur->id != searchIdCourse)
		pCur = pCur->pNext;
	//
	cout << "What you want to change: " << endl;
	cout << "1.Course Name" << endl;
	cout << "2.Id" << endl;
	cout << "3.Teacher's Name" << endl;
	cout << "4.NumOfCredits" << endl;
	cout << "5.MaxNumOfStudent" << endl;
	cout << "6.Day 1" << endl;
	cout << "7.Hour 1" << endl;
	cout << "8.Day 2" << endl;
	cout << "9.Hour 2" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
	{
		getline(cin, pCur->courseName);
		break;
	}
	case 2:
	{
		getline(cin, pCur->id);
		break;
	}
	case 3:
	{
		getline(cin, pCur->teacherName);;
		break;

	}
	case 4:
	{
		getline(cin, pCur->numOfCredits);
		break;
	}
	case 5:
	{
		getline(cin, pCur->maxNumOfStudents);
		break;
	}
	case 6:
	{
		getline(cin, pCur->day1);
		break;
	}
	case 7:
	{
		getline(cin, pCur->hour1);
		break;
	}
	case 8:
	{
		getline(cin, pCur->day2);
		break;
	}
	case 9:
	{
		getline(cin, pCur->hour2);
		break;
	}
	default:
		break;
	}
	read.close();
	//
	pCur = pHeadCourse;
	write.open("Toan.txt");
	while (pCur != nullptr)
	{
		write << pCur->courseName << ",";
		write << pCur->id << ",";
		write << pCur->teacherName << ",";
		write << pCur->numOfCredits << ",";
		write << pCur->maxNumOfStudents << ",";
		write << pCur->day1 << ",";
		write << pCur->hour1 << ",";
		write << pCur->day2 << ",";
		write << pCur->hour2 << "\n";
		pCur = pCur->pNext;
	}
	write.close();
}
void viewListOfStudents(Class *pHead){

	cout << "LIST OF STUDENTS IN CLASS " << pHead->className << endl;
	Student *pTemp = pHead->pHeadStudent;
	cout << "No\tID\tFirst Name\tLast Name\tGender\tDate of Birth\tSocial ID\n";
	while(pTemp==nullptr){
		cout << pTemp->no << "\t" << pTemp->id << "\t" << pTemp->firstName << "\t" << pTemp->lastName << "\t" << pTemp->gender << "\t" << pTemp->dateOfBirth << "\t" << pTemp->socialId << endl;
		pTemp = pTemp->pNext;
	}
}
void viewListOfCourses(Semester *pHead){
	cout << "LIST OF COURSES IN SEMESTER " << pHead->semesterName << endl;
	Course *pTemp = pHead->pHeadCourse;
	cout << "Course ID\tCourse Name\tNumber of Credits\tTeacher Name\n";
	while(!pTemp){
		cout << pTemp->id << "\t" << pTemp->courseName << "\t" << pTemp->numOfCredits << "\t" << pTemp->teacherName << endl;
		pTemp = pTemp->pNext;
	}
}
void viewListOfClasses(Class *pHead){
	cout << "LIST OF CLASSES" << endl;
	int i = 1;
	while(!pHead){
		cout << i << ". " << pHead->className << endl;
		pHead = pHead->pNext;
		i++;
	}
}
void ViewCourse(Student* pHead) {
	Course* pCur = pHead->pHeadCourse;
	while (pCur != nullptr) {
		cout << "LIST OF ENROLLED COURSES: " << endl;
		cout << pCur->courseName << endl;
		pCur = pCur->pNext;
	}
}
void enrollCourse(Semester* pSemester, Student* pStudent) {
	Course* pTemp = pSemester->pHeadCourse;
	int count = 0;
	int size = 0;
	while (pTemp != nullptr) {
		count++;
		pTemp = pTemp->pNext;
	}
	if (count >= 5) {
		cout << "You have enroll enough courses (5 course per Semester)\n";
		return;
	}
	pTemp = pSemester->pHeadCourse;		// pTemp is in Semester's course
	viewListOfCourses(pSemester);
	cout << "Enter Courses Name that you want to enroll\n";
	string name;
	getline(cin, name);
			
	while (pTemp != nullptr && pTemp->courseName != name) {
		pTemp = pTemp->pNext;
	}
	if (pTemp != nullptr) {
		Course* pCur = pStudent->pHeadCourse;		// pCur is in Student's course
		if (pCur == nullptr) {
			pCur = new Course;
			*pCur = *pTemp;
			cout << "Successfully enroll\n";
		}
		else {
			bool canEnroll = true;
			while (pCur->pNext != nullptr) {
				if (pTemp->courseName == pCur->courseName) {
					canEnroll = false;
					cout << "Course has already been enrolled.\n";
					break;
				}
				else if (pTemp->day1 == pCur->day1) {
					if (pTemp->hour1 == pCur->hour1) {
						canEnroll = false;
						cout << "The 2 sessions are conflicted.";
						break;
					}
				}
				else if (pTemp->day2 == pCur->day2) {
					if (pTemp->hour2 == pCur->hour2) {
						canEnroll = false;
						cout << "The 2 sessions are conflicted.";
						break;
					}
				}
				else {
					pCur = pCur->pNext;
				}			
			} if (canEnroll == true) {
				pCur->pNext = new Course;
				pCur = pCur->pNext;
				*pCur = *pTemp;			
				pCur->pNext = nullptr;
				cout << "Successfully enroll\n";
			}
			else {
				cout << "cannot enroll\n";
			}
		}
		
	}
	else {
		cout << "Cannot find the course name that you enter.\n Please enter exactly.\n";
	}
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
	Course* pHeadCourse = nullptr;
	char path[] = "Toan";
	UpdateCourseInformation(pHeadCourse, path);
	return 0;
}
