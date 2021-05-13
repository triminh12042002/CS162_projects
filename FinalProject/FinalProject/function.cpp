
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

string createDate() {
	cout << "\nEnter Day :";
	string day;
	cin >> day;
	cout << "\nEnter Month :";
	string month;
	cin >> month;
	cout << "\nEnter Year :";
	string year;
	cin >> year;
	return  day + '/' + month + '/' + year;
}
/*void addAllStudentsToClass(Student*& pHeadStudent,int sizeOfListStudent, char path[]) {
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
		if (pHeadStudent != nullptr) {
			pHeadStudent->pNext = pTemp;
			pHeadStudent = pTemp;
		}
		else {
			pHeadStudent = pTail = pTemp;
		}
	}
}
*/
void OutputCSVFIle(Student* pHeadStudent, char path[]) {
	if (pHeadStudent == nullptr) return;
	ofstream ofs;
	ofs.open(path);
	if (!ofs.is_open()) {
		cout << "Khong mo duoc file.";
		return;
	}
	Student* pCur = pHeadStudent;
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
void signUp(string path) {
	string us, pw;

	cout << "\nEnter username : ";
	getline(cin,us);
	cout << "\nEnter password : ";
	getline(cin,pw);
	ofstream write;
	write.open(path, ios::app);
	write << us << ',' << pw << '\n';
	write.close();
}
bool login(account*& pLogin, string loginPath, string &user)
{

	string username, password;
	cout << "\nEnter username : ";
	getline(cin, username);
	user = username;
	cout << "\nEnter password : ";
	getline(cin, password);

	account* pCur = nullptr;
	string temp;
	ifstream read;
	read.open(loginPath);
	while (!read.eof())
	{
		getline(read, temp, ',');
		if (temp == "") break;

		if (pCur == nullptr) {
			pLogin = pCur = new account;
			pCur->next = nullptr;
		}
		else {
			pCur->next = new account;
			pCur = pCur->next;
		}

		pCur->us = temp;
		getline(read, pCur->pw, '\n');

	}
	pCur = pLogin;
	while (pCur != nullptr)
	{	
		if (pCur->us == username && pCur->pw == password)
			return true;
		else pCur = pCur->next;
	}
	read.close();
	return false;
	
}
void createSchoolYear(SchoolYear*& pHeadSchoolYear,int & schoolYearSize, char*path) {
	
	SchoolYear* pCur = nullptr;
	int t;
	cout << "\nInput the school year (E.g : 2020): ";
	cin >> t;
	if (pHeadSchoolYear == nullptr)
	{
		pHeadSchoolYear = new SchoolYear;
		pHeadSchoolYear->schoolYearName = to_string(t) + "-" + to_string(t+1);
		pHeadSchoolYear->pNext = nullptr;
		pHeadSchoolYear->pHeadSemester = nullptr;
		schoolYearSize++;
	}
	else {
		pCur = pHeadSchoolYear;
		while (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}
		SchoolYear* newyear = new SchoolYear;
		newyear->schoolYearName = to_string(t) + "-" + to_string(t + 1);;
		newyear->pNext = nullptr;
		newyear->pHeadSemester = nullptr;
		pCur->pNext = newyear;
		schoolYearSize++;
	}
	ofstream write;
	write.open(path);
	pCur = pHeadSchoolYear;
	while (pCur != nullptr)
	{
		write << pCur->schoolYearName << '\n';
		pCur = pCur->pNext;
	}
	write.close();
}
void createClass(Class* &pHeadClass, int& sizeOfClass, char* path) {
	Class* pCur = nullptr;
	if (pHeadClass == nullptr)
	{
		pHeadClass = new Class;
		cout << "\nEnter name of class";
		cin >> pHeadClass->className;
		pHeadClass->pNext = nullptr;
		pHeadClass->pHeadStudent = nullptr;
		sizeOfClass++;
	}
	else {
		pCur = pHeadClass;
		while (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}
		Class* newClass = new Class;
		cout << "\nEnter name of class";
		cin >> newClass->className;
		newClass->pNext = nullptr;
		newClass->pHeadStudent = nullptr;
		pCur->pNext = newClass;
		sizeOfClass++;
	}
	ofstream write;
	write.open(path);
	pCur = pHeadClass;
	while (pCur != nullptr)
	{
		write << pCur->className << '\n';
		pCur = pCur->pNext;
	}
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
void CreateClass(Student* pHeadStudent, int& sizeOfClass, char* path) {
	ofstream write;
	write.open(path);
	Class* pHeadClass = new Class;
	Class* pCurClass = pHeadClass;
	Student* pCurStudent = pHeadClass->pHeadStudent;
	while (pCurClass != nullptr) {
		while (pCurStudent != pCurClass->pTailStudent) {
			write << pCurStudent << "\n";
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
			sizeOfClass++;
		}
	}
	write.close();
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
void add1StudentToClass(Student*& pHeadStudent,int &sizeOfListStudent,char* path) {
	Student* pCur = nullptr;
	Student* newStudent = new Student;
	newStudent->pNext = nullptr;
	cout << "\ninput student data";
	cout << "\nno: ";
	getline(cin, newStudent->no);
	cout << "\nid: ";
	getline(cin, newStudent->id);
	cout << "\nfirstName: ";
	getline(cin, newStudent->firstName);
	cout << "\nlastName: ";
	getline(cin, newStudent->lastName);
	cout << "\ngender: ";
	getline(cin, newStudent->gender);
	cout << "\ndateOfBirth: ";
	getline(cin, newStudent->dateOfBirth);
	cout << "\nsocialId: ";
	getline(cin, newStudent->socialId);
	if (pHeadStudent == nullptr)
	{
		pHeadStudent = newStudent;
		sizeOfListStudent++;
	}
	else {
		pCur = pHeadStudent;
		while (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = newStudent;
		sizeOfListStudent++;
	}
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

	cout << "Input Starting Date : ";
	getline(cin, pCourse->startDate);

	cout << "Input Ending Date : ";
	getline(cin, pCourse->endDate);

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
void CreateCourseRegistration(Course*& pHeadCourse, int& size ,char* pathListOfCourseChar)
{
	ofstream write;
	write.open(pathListOfCourseChar);
	if (!write.is_open()) {
		cout << "cannot open";
		return;
	}
	Course* pCur = nullptr;
	if(pHeadCourse==nullptr)
	{
		pHeadCourse = new Course;
		pHeadCourse->pNext = nullptr;
		pCur = pHeadCourse;
	}
	else {
		pCur = pHeadCourse;
		while (pCur->pNext != nullptr)
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = new Course;
		pCur = pCur->pNext;
		pCur->pNext = nullptr;
	}
	addCourseToSemester(pCur);
	size++;
	pCur = pHeadCourse;
	while (pCur != nullptr)
	{
		write << pCur->courseName << ",";
		write << pCur->startDate << ",";
		write << pCur->endDate << ",";
		write << pCur->id << ",";
		write << pCur->teacherName << ",";
		write << pCur->numOfCredits << ",";
		write << pCur->maxNumOfStudents << ",";
		write << pCur->courseName << ",";
		write << pCur->day1 << ",";
		write << pCur->hour1 << ",";
		write << pCur->day2 << ",";
		write << pCur->hour2 << "\n";
		pCur = pCur->pNext;
	}
	write.close();
}
void CreateSemesterOfYear(SchoolYear* pTempSchoolYear, Semester*& pSemester,int &sizeOfSemester ,char* path)
{
	sizeOfSemester = 0;
	pSemester = nullptr;
	cout << "\nEnter the number of semesters ( 2 or 3 )";
	cout << "\nEnter 0 to return";
	int numSemester = 1;
	while (!(numSemester >= 2 && numSemester <= 3)) {
		cin >> numSemester;
		if (numSemester == 0) return;
	}
	sizeOfSemester = numSemester;
	ofstream write;
	write.open(path);
	Semester* pCur = pSemester;
	int i = 1;
	while (i <= numSemester)
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
		cout << "\nSemester " << i;
		pCur->semesterName = char('0' + i);
		pCur->schoolYear = pTempSchoolYear->schoolYearName;
		cout << "\nSchool Year: " << pCur->schoolYear;	// schoolYear of semester has been update before( choose schoolYear -> choose semester )
		cout << "\nThe Date of Starting semester: ";
		pCur->startDate = createDate();
		cout << "\nThe Date of Ending semester: ";
		pCur->endDate = createDate();
		cout << "\nThe Date of Starting Registration: ";
		pCur->regisStartDate = createDate();
		cout << "\nThe Date of Ending Registration: ";
		pCur->regisEndDate = createDate();
		write << pCur->schoolYear << ',' << pCur->semesterName << ',' << pCur->startDate << ',' << pCur->endDate << ',' << pCur->regisStartDate  << ',' << pCur->regisEndDate << '\n';
		i++;
	}
	write.close();
}
void UpdateCourseInformation(Course*& pHeadCourse,Semester*pSemester,SchoolYear*pSchool,char* path)//path="Course"
{
	ofstream write;
	write.open(path+pSemester->semesterName+pSchool->schoolYearName+".csv");
	//ofstream write;
	Course* pCur = nullptr;
	string searchIdCourse;
	pCur = pHeadCourse;
	cout << "Which Course do you want to Update? Please Input the ID Course: ";
	getline(cin, searchIdCourse);
	while (pCur != nullptr && pCur->id != searchIdCourse)
	{
		pCur = pCur->pNext;
	}
	//Look for the Course 
	if (pCur == nullptr)
	{
		cout << "This Course does not exist in this semester.";
		return;
	}
	if (pCur->id == searchIdCourse)
	{
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
		cout << "Please input number here: ";
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
	}
	//
	pCur = pHeadCourse;
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
void viewListOfCourses(Course* pHead) {
	Course* pTemp = pHead;
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
bool enrollCourse(Course* pCourse, Student* pStudent, string &pTempCourseName) {
	Course* pTemp = pCourse;	// pTemp is in Semester's course
	Course* pCur = pStudent->pHeadCourse;		// pCur is in Student's course
	int count = 0;
	int size = 0;
	while (pCur != nullptr) {
		count++;
		pCur = pCur->pNext;
	}
	if (count >= 5) {
		cout << "You have enroll enough courses (5 course per Semester)\n";
		return false;;
	}
	pTemp = pCourse;		
	viewListOfCourses(pCourse);
	cout << "Enter Courses Name that you want to enroll\n";
	string name;
	getline(cin, name);

	while (pTemp != nullptr && pTemp->courseName != name) {
		pTemp = pTemp->pNext;
	}
	if (pTemp != nullptr) {
		pCur = pStudent->pHeadCourse;	
		if (pCur == nullptr) {
			pStudent->pHeadCourse = pCur = new Course;
			*pCur = *pTemp;
			cout << "Successfully enroll\n";
			pTempCourseName = name;
			return true;
		}
		else {
			bool canEnroll = true;
			pCur = pStudent->pHeadCourse;
			while (pCur != nullptr) {
				if (pTemp->courseName == pCur->courseName) {
					canEnroll = false;
					cout << "Course has already been enrolled.\n";
					break;
				}
				else if (pTemp->day1 == pCur->day1) {
					if (pTemp->hour1 == pCur->hour1) {
						canEnroll = false;
						cout << "\n" << pCur->courseName << "\tday1:  " << pCur->day1 << "\thour1: " << pCur->hour1 << endl;
						cout << "\n" << pTemp->courseName << "\tday1:  " << pTemp->day1 << "\thour1: " << pTemp->hour1 << endl;
						cout << "The 2 sessions are conflicted.";
						break;
					}
				}
				else if (pTemp->day2 == pCur->day2) {
					if (pTemp->hour2 == pCur->hour2) {
						canEnroll = false;
						cout << "\n" << pCur->courseName << "\tday2:  " << pCur->day2 << "\thour2: " << pCur->hour2 << endl;
						cout << "\n" << pTemp->courseName << "\tday2:  " << pTemp->day2 << "\thour2: " << pTemp->hour2 << endl;
						cout << "\nThe 2 sessions are conflicted.";
						break;
					}
				}
				else {
					
				}
				pCur = pCur->pNext;
			} 
			if (canEnroll == true) {
				pCur = pStudent->pHeadCourse;
				while (pCur->pNext != nullptr) {
					pCur = pCur->pNext;
				}
				pCur->pNext = new Course;
				pCur = pCur->pNext;
				*pCur = *pTemp;
				pCur->pNext = nullptr;
				cout << "Successfully enroll\n";
				pTempCourseName = name;
				return true;
			}
			else {
				cout << "cannot enroll\n";
				return false;
			}
		}

	}
	else {
		cout << "Cannot find the course name that you enter.\n Please enter exactly.\n";
	}
	return false;
}
void RemoveTheEnrolledCourse(Course* pCourse,Semester*pSemester,SchoolYear*pSchool,char* path, string IdSearched)//char="Student"
{		
	//Ask student to input his/her id before Removing the Enrolled Course 									
	ofstream write;									  	
	Student* pCur = nullptr;
	pCur = pCourse->pHeadStudentEnroll;
	Student* temp = pCur;
	if (pCourse->pHeadStudentEnroll->id == IdSearched)
	{
		temp = pCourse->pHeadStudentEnroll;
		pCourse->pHeadStudentEnroll = pCourse->pHeadStudentEnroll->pNext;
		delete temp;
	}
	else {
		while (pCur->pNext != nullptr && pCur->pNext->id != IdSearched)
		{
			pCur = pCur->pNext;
		}
		if (pCur->pNext == nullptr)
		{
			cout << "Student does not enroll this course";
			return;
		}
		if (pCur->pNext->id == IdSearched)
		{
			temp = pCur->pNext;
			pCur->pNext = pCur->pNext->pNext;
			delete temp;
		}
	}
	pCur = pCourse->pHeadStudentEnroll;
	write.open(path+pCourse->courseName+pSemester->semesterName+pSchool->schoolYearName+".csv");
	while (pCur != nullptr)
	{
		write << pCur->id << ",";
		write << pCur->firstName << " ";
		write << pCur->lastName << "\n";
		pCur = pCur->pNext;
	}
	write.close();
}
void ViewListOfStudentInCourse(Course* pCourse)
{
	Student* pCur = nullptr;
	pCur = pCourse->pHeadStudentEnroll;
	if (pCourse->pHeadStudentEnroll == nullptr)
	{
		cout << "There is no Student in this Course";
		return;
	}
	cout << "The List of Students in Course: ";
		while (pCur != nullptr)
		{
			cout << pCur->id << ",";
			cout << pCur->firstName << " ";
			cout << pCur->lastName << endl;
			pCur = pCur->pNext;
		}
}
/*void ViewScoreBoard(int& numberOfStudent) {
    ifstream write;
    ScoreBoardOfCourse ScoreCourse;
    int i = 3;
    write.open("ScoreCourse.csv");
    if (!write.is_open()) {
        cout << "Error Loading File.";
    }
    else {
        Draw(15, numberOfStudent, 0, 0);
        GoTo(1, 1);
        cout << "NO";
        GoTo(8, 1);
        cout << "ID";
        GoTo(18, 1);
        cout << "FULL NAME";
        GoTo(41, 1);
        cout << "MID";
        GoTo(46, 1);
        cout << "FIN";
        GoTo(51, 1);
        cout << "TOT";
        GoTo(56, 1);
        cout << "OTH";
        while (!write.eof()) {
            getline(write,ScoreCourse.no, ',');
            getline(write, ScoreCourse.id, ',');
            getline(write, ScoreCourse.fullname, ',');
            getline(write, ScoreCourse.midtermMark, ',');
            getline(write, ScoreCourse.finalMark, ',');
            getline(write, ScoreCourse.totalMark, ',');
            getline(write, ScoreCourse.otherMark, ',');
            GoTo(2, i);
            cout << ScoreCourse.no;
            GoTo(5, i);
            cout << ScoreCourse.id;
            GoTo(16, i);
            cout << ScoreCourse.fullname;
            GoTo(42, i);
            cout << ScoreCourse.midtermMark;
            GoTo(47, i);
            cout << ScoreCourse.finalMark;
            GoTo(52, i);
            cout << ScoreCourse.totalMark;
            GoTo(57, i);
            cout << ScoreCourse.otherMark;
            i += 2;
        }
        
    }
    int wait;
    cin >> wait;
}*/
void DrawListofStudentInClass(int width, int height, int x, int y) {
	// top board
	GoTo(x, y);
	cout << char(201);
	for (int j = 1; j <= 4 * width - 1; ++j) {
		//if (j % 4 == 0) cout << char(209);
	   //else cout << char(205);
		switch (j)
		{
		case 3:
		{
			cout << char(209);
			break;
		}
		case 12:
		{
			cout << char(209);
			break;
		}
		case 27:
		{
			cout << char(209);
			break;
		}
		case 34:
		{
			cout << char(209);
			break;
		}
		case 45:
		{
			cout << char(209);
			break;
		}
		case 56:
		{
			cout << char(209);
			break;
		}
		default:
		{
			cout << char(205);
		}
		}
	}
	cout << char(187);
	// mid board
	cout << endl;
	GoTo(x, ++y);
	// final mark

	// 
	for (int i = 2; i <= 2 * height - 1 + 2; ++i) {
		if (i % 2 == 0) {
			cout << char(199);
			for (int j = 1; j <= 4 * width - 1; ++j) {
				// if (j % 4 == 0) cout << char(197);
				 //else cout << char(196);
				switch (j)
				{
				case 3:
				{
					cout << char(197);
					break;
				}
				case 12:
				{
					cout << char(197);
					break;
				}
				case 27:
				{
					cout << char(197);
					break;
				}
				case 34:
				{
					cout << char(197);
					break;
				}
				case 45:
				{
					cout << char(197);
					break;
				}
				case 56:
				{
					cout << char(197);
					break;
				}
				default:
				{
					cout << char(196);

				}
				}
			}
			cout << char(182);
			cout << endl;
			GoTo(x, ++y);
		}
		else {
			cout << char(186);
			for (int j = 1; j <= 4 * width - 1; ++j) {
				//if (j % 4 == 0) cout << char(179);// ve gach xuong
				//else cout << " ";
				switch (j)
				{
				case 3:
				{
					cout << char(179);
					break;
				}
				case 12:
				{
					cout << char(179);
					break;
				}
				case 27:
				{
					cout << char(179);
					break;
				}
				case 34:
				{
					cout << char(179);
					break;
				}
				case 45:
				{
					cout << char(179);
					break;
				}
				case 56:
				{
					cout << char(179);
					break;
				}
				default:
				{
					cout << " ";
				}
				}
			}
			cout << char(186);
			cout << endl;
			GoTo(x, ++y);
		}
	}
	// bot board
	cout << char(200);
	for (int j = 1; j <= 4 * width - 1; ++j) {
		//if (j % 4 == 0) cout << char(207);
		//else cout << char(205);
		switch (j)
		{
		case 3:
		{
			cout << char(207);
			break;
		}
		case 12:
		{
			cout << char(207);
			break;
		}
		case 27:
		{
			cout << char(207);
			break;
		}
		case 34:
		{
			cout << char(207);
			break;
		}
		case 45:
		{
			cout << char(207);
			break;
		}
		case 56:
		{
			cout << char(207);
			break;
		}
		default:
		{
			cout << char(205);

		}
		}
	}
	cout << char(188);
}
void ListofStudentInClass(int NumberOfStudent, Class* pHead)
{
	Student* pTemp = pHead->pHeadStudent;
	for (int i = 1; i < 2 * NumberOfStudent; i = i + 2)
	{
		GoTo(1, i);
		cout << pTemp->no;
		GoTo(4, i);
		cout << pTemp->id;
		GoTo(13, i);
		cout << pTemp->firstName + " " + pTemp->lastName;
		GoTo(28, i);
		cout << pTemp->gender;
		GoTo(35, i);
		cout << pTemp->dateOfBirth;
		GoTo(46, i);
		cout << pTemp->socialId;
		pTemp = pTemp->pNext;
	}
}
void ScoreBoardOfClass(int NumberOfStudent)
{
	//9 học sinh thì NumberOfStudnet = 10
	GoTo(1, 1);
	cout << "No";
	GoTo(6, 1);
	cout << "ID";
	GoTo(13, 1);
	cout << "Full Name";
	GoTo(28, 1);
	cout << "Subject 1";
	GoTo(39, 1);
	cout << "Subject 2";
	GoTo(50, 1);
	cout << "Subject 3";
	GoTo(61, 1);
	cout << "Subject 4";
	GoTo(72, 1);
	cout << "Subject 5";
	GoTo(83, 1);
	cout << "Subject 6";
	GoTo(94, 1);
	cout << "GPA";
	GoTo(101, 1);
	cout << "Note";
	int x = 1;
	for (int i = 3; i < 2 * NumberOfStudent; i = i + 2)
	{
		GoTo(1, i);
		cout << x;
		GoTo(4, i);
		cout << "20125121";
		GoTo(13, i);
		cout << "Thanh Tu";
		GoTo(32, i);
		cout << "8";
		GoTo(43, i);
		cout << "7";
		GoTo(54, i);
		cout << "10";
		GoTo(65, i);
		cout << "2";
		GoTo(76, i);
		cout << "5";
		GoTo(87, i);
		cout << "6";
		GoTo(95, i);
		cout << "8";
		x++;
	}
}
void DrawListofStudentInClass(int width, int height, int x, int y) {
	// top board
	GoTo(x, y);
	cout << char(201);
	for (int j = 1; j <= 4 * width - 1; ++j) {
		//if (j % 4 == 0) cout << char(209);
	   //else cout << char(205);
		switch (j)
		{
		case 3:
		{
			cout << char(209);
			break;
		}
		case 12:
		{
			cout << char(209);
			break;
		}
		case 27:
		{
			cout << char(209);
			break;
		}
		case 38:
		{
			cout << char(209);
			break;
		}
		case 49:
		{
			cout << char(209);
			break;
		}
		case 60:
		{
			cout << char(209);
			break;
		}
		case 71:
		{
			cout << char(209);
			break;
		}
		case 82:
		{cout << char(209);
		break;
		}
		case 93:
		{
			cout << char(209);
			break;
		}
		case 98:
		{
			cout << char(209);
			break;
		}
		default:
		{
			cout << char(205);
		}
		}
	}
	cout << char(187);
	// mid board
	cout << endl;
	GoTo(x, y + 2);
	// final mark

	// 
	for (int i = 2; i <= 2 * height - 1 + 2; ++i) {
		if (i == 1) {
			cout << char(186);
			for (int j = 2; j <= 4 * width - 1; ++j) {
				//if (j % 4 == 0) cout << char(179);// ve gach xuong
				//else cout << " ";
				switch (j)
				{
				case 3:
				{
					cout << char(179);
					break;
				}
				case 12:
				{
					cout << char(179);
					break;
				}
				case 27:
				{
					cout << char(179);
					break;
				}
				case 38:
				{
					cout << char(179);
					break;
				}
				case 49:
				{
					cout << char(179);
					break;
				}
				case 60:
				{
					cout << char(179);
					break;
				}
				case 71:
				{
					cout << char(179);
					break;
				}
				case 82:
				{cout << char(179);
				break;
				}
				case 93:
				{
					cout << char(179);
					break;
				}
				case 98:
				{
					cout << char(179);
					break;
				}
				default:
				{
					cout << " ";
				}
				}
			}
			cout << char(186);
			cout << endl;
			GoTo(x, ++y);
		}
		else {
			if (i % 2 == 0) {
				cout << char(199);
				for (int j = 1; j <= 4 * width - 1; ++j) {
					// if (j % 4 == 0) cout << char(197);
					 //else cout << char(196);
					switch (j)
					{
					case 3:
					{
						cout << char(197);
						break;
					}
					case 12:
					{
						cout << char(197);
						break;
					}
					case 27:
					{
						cout << char(197);
						break;
					}
					case 38:
					{
						cout << char(197);
						break;
					}
					case 49:
					{
						cout << char(197);
						break;
					}
					case 60:
					{
						cout << char(197);
						break;
					}
					case 71:
					{
						cout << char(197);
						break;
					}
					case 82:
					{cout << char(197);
					break;
					}
					case 93:
					{
						cout << char(197);
						break;
					}
					case 98:
					{
						cout << char(197);
						break;
					}
					default:
					{
						cout << char(196);

					}
					}
				}
				cout << char(182);
				cout << endl;
				GoTo(x, ++y);
			}
			else {
				cout << char(186);
				for (int j = 1; j <= 4 * width - 1; ++j) {
					//if (j % 4 == 0) cout << char(179);// ve gach xuong
					//else cout << " ";
					switch (j)
					{
					case 3:
					{
						cout << char(179);
						break;
					}
					case 12:
					{
						cout << char(179);
						break;
					}
					case 27:
					{
						cout << char(179);
						break;
					}
					case 38:
					{
						cout << char(179);
						break;
					}
					case 49:
					{
						cout << char(179);
						break;
					}
					case 60:
					{
						cout << char(179);
						break;
					}
					case 71:
					{
						cout << char(179);
						break;
					}
					case 82:
					{cout << char(179);
					break;
					}
					case 93:
					{
						cout << char(179);
						break;
					}
					case 98:
					{
						cout << char(179);
						break;
					}
					default:
					{
						cout << " ";
					}
					}
				}
				cout << char(186);
				cout << endl;
				GoTo(x, ++y);
			}
		}

	}
	// bot board
	cout << char(200);
	for (int j = 1; j <= 4 * width - 1; ++j) {
		//if (j % 4 == 0) cout << char(207);
		//else cout << char(205);
		switch (j)
		{
		case 3:
		{
			cout << char(207);
			break;
		}
		case 12:
		{
			cout << char(207);
			break;
		}
		case 27:
		{
			cout << char(207);
			break;
		}
		case 38:
		{
			cout << char(207);
			break;
		}
		case 49:
		{
			cout << char(207);
			break;
		}
		case 60:
		{
			cout << char(207);
			break;
		}
		case 71:
		{
			cout << char(207);
			break;
		}
		case 82:
		{cout << char(207);
		break;
		}
		case 93:
		{
			cout << char(207);
			break;
		}
		case 98:
		{
			cout << char(207);
			break;
		}
		default:
		{
			cout << char(205);

		}
		}
	}
	cout << char(188);
}