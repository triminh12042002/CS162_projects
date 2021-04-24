
#include "Header.h"

using namespace std;
// ctrl + m + o  de thu nho code
// ctrl + m + p de phong to code
void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void inputStudentData(Student*& pHeadStudent, Student*& pTailStudent, char path[]) {
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
	getline(ifs, temp, '\n');
	for (int i = 0; i < n; ++i) {
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
void signUp() {
	string us, pw;

	cout << "Enter username : ";
	getline(cin,us);
	cout << "Enter password : ";
	getline(cin,pw);
	ofstream write;
	write.open("loginData.txt", ios::app);
	write << us << ',' << pw << '\n';
	write.close();
}
bool login(account*& pLogin, string loginPath)
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
	int i = 1;
	while (pCur != nullptr)
	{	
		cout << i++;
		if (pCur->us == username && pCur->pw == password)
			return true;
		else pCur = pCur->next;
	}
	read.close();
	return false;
	
}
void createSchoolYear(SchoolYear*& pHeadSchoolYear) {
	ofstream write;
	write.open("SchoolYear.txt",ios::app);
	pHeadSchoolYear = new SchoolYear;
	pHeadSchoolYear->pNext = nullptr;
	pHeadSchoolYear->pHeadSemester = nullptr;
	cout << "Enter school year's name\n";
	getline(cin, pHeadSchoolYear->schoolYearName);
	write << pHeadSchoolYear->schoolYearName << "\n";
	write.close();
}
void CreateYear(SchoolYear*& pHeadYear) {
	cout << "Input the School Year to direct into year's data(Input STOP to exit): ";
	string year;
	getline(cin, year, '\n');
	if (!pHeadYear) {
		pHeadYear = new SchoolYear;
		pHeadYear = new SchoolYear;
		pHeadYear->schoolYearName = year;
		pHeadYear->pHeadSemester = nullptr;
		pHeadYear->pNext = nullptr;
	}
	SchoolYear* pCurYear = pHeadYear->pNext;
	while (pHeadYear && year != "STOP") {
		pCurYear = new SchoolYear;
		pCurYear->schoolYearName = year;
		pHeadYear->pHeadSemester = nullptr;
		pCurYear->pNext = nullptr;
		pCurYear = pCurYear->pNext;
		cout << "Input the School Year to direct into year's data(Input STOP to exit): ";
		getline(cin,year, '\n');
	}
}

void CreateClass(Student* pHeadStudent) {
	Class* pHeadClass = new Class;
	Class* pCurClass = pHeadClass;
	Student* pCurStudent = pHeadClass->pHeadStudent;
	while (pCurClass != nullptr) {
		while (pCurStudent != pCurClass->pTailStudent) {
			//Input Student
			pCurStudent = pCurStudent->pNext;
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
			pCurClass = pCurClass->pNext;
		}
	}
}
	
void addAllStudentsToClass(Class*& pClass) {
	if (pClass == nullptr) {
		pClass = new Class;
	}
	pClass->pHeadStudent = nullptr;
	pClass->pTailStudent = nullptr;
	char inputPath[] = "input.csv";
	inputStudentData(pClass->pHeadStudent, pClass->pTailStudent, inputPath);
}
void create1Student(Student*& pStudent) {
	if (pStudent == nullptr) {
		pStudent = new Student;
	}
	cout << "Enter student data\n";
	cout << "no: ";
	getline(cin, pStudent->no);
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
void add1StudentToClass(Class*& pClass) {
	if (pClass == nullptr) {
		pClass = new Class;
	}
	Student* pStudent = new Student;
	create1Student(pStudent);
	pClass->pTailStudent->pNext = pStudent;
	pClass->pTailStudent = pStudent;
}
void deleteCourse(Semester*& pHead) {
	string nameOfCourse, idOfCourse;
	cout << "Input name of the course that you want to delete : "; cin >> nameOfCourse;

	Course* courseHead = pHead->pHeadCourse;
	if (courseHead->courseName == nameOfCourse) {
		pHead->pHeadCourse = courseHead->pNext;
		delete courseHead;
		return;
	}

	Course* temp = courseHead;
	courseHead = courseHead->pNext;
	while (courseHead) {
		if (courseHead->courseName == nameOfCourse) {
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
void addCourseToSemester(Course*& pCourse) {
	cout << "Input course name : ";
	getline(cin, pCourse->courseName);

	cout << "Input course id : ";
	getline(cin, pCourse->id);

	cout << "Input teacher name : ";
	getline(cin, pCourse->teacherName);

	cout << "Input number of credits in the course : ";
	getline(cin, pCourse->numOfCredits);

	cout << "Input the maximun number of students : ";
	getline(cin, pCourse->maxNumOfStudents);

	cout << "Input day 1 : ";
	getline(cin, pCourse->day1);

	cout << "Input hour 1 : ";
	getline(cin, pCourse->hour1);

	cout << "Input day 2 : ";
	getline(cin, pCourse->day2);

	cout << "Input hour 2 : ";
	getline(cin, pCourse->hour2);
}
void CreateCourseRegistration(Course*& pHeadCourse, Semester* pSemester, string path)
{
	ofstream write;
	write.open(path + pSemester->semesterName);//semester+1. ALL course in the semester 1
	Course* pCur = nullptr;
	//cout << "The Date of Starting a Course Registration";
	//cin >> pCur->startDate;
	//cout << "The Date of Ending a Course Registration";
	//cin >> pCur->endDate;
	//read << pCur->startDate << ',' << pCur->endDate << '\n';
	int x = 1;
	while (x != 0)//0 means STOP
	{
		if (pHeadCourse == nullptr)
		{
			pHeadCourse = new Course;
			pHeadCourse->pNext = nullptr;
			pCur = pHeadCourse;
		}
		else {
			pCur->pNext = new Course;
			pCur = pCur->pNext;
		}
		pCur->pNext = nullptr;
		addCourseToSemester(pCur);
		cout << "You want to add a new Course to this Semester,please press 0 to stop.";
		cin >> x;
	}
	pCur = pHeadCourse;
	Course* pCourse;
	while (pCur != nullptr)
	{
		pCourse = pCur;
		write << pCourse->courseName << ",";
		write << pCourse->id << ",";
		write << pCourse->teacherName << ",";
		write << pCourse->numOfCredits << ",";
		write << pCourse->maxNumOfStudents << ",";
		write << pCourse->courseName << ",";
		write << pCourse->day1 << ",";
		write << pCourse->hour1 << ",";
		write << pCourse->day2 << ",";
		write << pCourse->hour2 << "\n";
		pCur = pCur->pNext;
	}
	write.close();
	//There is a file for saving Date of Registration
}
void CreateSemesterOfYear(Semester*& pSemester, char* path) //char path="semester"
{
	ofstream read;
	read.open(path,ios::app);
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
		else {
			pCur->pNext = new Semester;
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
		}
		//information of each Semester in year
		cout << "The Semester: ";
		cin >> pCur->semesterName;
		cout << "School Year: ";
		cin >> pCur->schoolYear;
		cout << "The Date of Starting semester: ";
		cin >> pCur->startDate;
		cout << "The Date of Ending semester: ";
		cin >> pCur->endDate;
		read << pCur->schoolYear << ',' << pCur->semesterName << ',' << pCur->startDate << ',' << pCur->endDate << '\n';
		CreateCourseRegistration(pCur->pHeadCourse, pCur, "semester");
		//Create new semester
		i++;
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
void viewListOfStudents(Class* pHead) {

	cout << "LIST OF STUDENTS IN CLASS " << pHead->className << endl;
	Student* pTemp = pHead->pHeadStudent;
	cout << "No\tID\tFirst Name\tLast Name\tGender\tDate of Birth\tSocial ID\n";
	while (pTemp) {
		cout << pTemp->no << "\t" << pTemp->id << "\t" << pTemp->firstName << "\t" << pTemp->lastName << "\t" << pTemp->gender << "\t" << pTemp->dateOfBirth << "\t" << pTemp->socialId << endl;
		pTemp = pTemp->pNext;
	}
}
void viewListOfCourses(Semester* pHead) {
	cout << "LIST OF COURSES IN SEMESTER " << pHead->semesterName << endl;
	Course* pTemp = pHead->pHeadCourse;
	cout << "Course ID\tCourse Name\tNumber of Credits\tTeacher Name\n";
	while (pTemp) {
		cout << pTemp->id << "\t" << pTemp->courseName << "\t" << pTemp->numOfCredits << "\t" << pTemp->teacherName << endl;
		pTemp = pTemp->pNext;
	}
}
void viewListOfClasses(Class* pHead) {
	cout << "LIST OF CLASSES" << endl;
	int i = 1;
	while (pHead) {
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
void RemoveTheEnrolledCourse(Course* pCourse, char* path, string IdSearched)//remove the student in that course in file.txt
{													  //id,Name\n
	ifstream read;									  //char path[]="NameofCourse".cin>>path the main function
	ofstream write;									  //Ask student to input his/her id before Removing the Enrolled Course 	
	read.open(path);
	Student* pCur = nullptr;
	while (!read.eof())
	{
		if (pCourse->pHeadStudentEnroll == nullptr)
		{
			pCourse->pHeadStudentEnroll = new Student;
			pCourse->pHeadStudentEnroll->pNext = nullptr;
			pCur = pCourse->pHeadStudentEnroll;
		}
		else {
			pCur->pNext = new Student;
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
		}
		getline(read, pCur->id, ',');
		getline(read, pCur->firstName, '\n');
	}
	pCur = pCourse->pHeadStudentEnroll;
	Student* temp = pCur;
	while (pCur != nullptr)
	{
		if (pCourse->pHeadStudentEnroll->id == IdSearched)
		{
			temp = pCourse->pHeadStudentEnroll;
			pCourse->pHeadStudentEnroll = pCourse->pHeadStudentEnroll->pNext;
			delete temp;
		}
		else if (pCur->pNext->id == IdSearched)
		{
			temp = pCur->pNext;
			pCur->pNext = pCur->pNext->pNext;
			delete temp;
		}
		pCur = pCur->pNext;
	}
	pCur = pCourse->pHeadStudentEnroll;
	write.open(path);
	while (pCur != nullptr)
	{
		write << pCur->id << ",";
		write << pCur->firstName << "\n";
		pCur = pCur->pNext;
	}
	read.close();
	write.close();
}
void ViewListOfStudentInCourse(Course* pCourse, char* path)
{
	ifstream read;
	read.open(path);
	Student* pCur = nullptr;
	while (!read.eof())
	{
		if (pCourse->pHeadStudentEnroll == nullptr)
		{
			pCourse->pHeadStudentEnroll = new Student;
			pCourse->pHeadStudentEnroll->pNext = nullptr;
			pCur = pCourse->pHeadStudentEnroll;
		}
		else {
			pCur->pNext = new Student;
			pCur = pCur->pNext;
			pCur->pNext = nullptr;
		}
		getline(read, pCur->id, ',');
		getline(read, pCur->firstName, '\n');
	}
	pCur = pCourse->pHeadStudentEnroll;
	while (pCur != nullptr)
	{
		cout << "The List of Students in Course: ";
		cout << pCur->id << ",";
		cout << pCur->firstName << endl;
		pCur = pCur->pNext;
	}
	read.close();
}
void InputSchoolYear(SchoolYear*& pSchool, char* path)//Ex: char path[]="Year2020-2021";
{
	CreateSemesterOfYear(pSchool->pHeadSemester, path);
}
