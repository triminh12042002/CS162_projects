#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <sstream>
using namespace std;
struct account {
	string us;		//username 
	string pw;		//password
	account* next = nullptr;
};
struct Course;
struct Student {
	string no;
	string id;
	string firstName;
	string lastName;
	string gender;
	string dateOfBirth;
	string socialId;
	Course *pHeadCourse = nullptr;
	Student* pNext = nullptr;
};
struct Class {
	string className;
	Student* pHeadStudent = nullptr;	// first student in the list of students of this class
	Student* pTailStudent = nullptr;	// last student 
	Class* pNext = nullptr;
};
struct Course {
	
	string startDate;
	string endDate;
	string courseName;
	string id;
	string teacherName;
	string numOfCredits;
	string maxNumOfStudents;
	string day1;		// 1 Course include 2 session 
	string hour1;		// 1 session include day and hour
	string day2;		// Ex: day1 = MON, hour1 = 7:30
	string hour2;
	Student* pHeadStudentEnroll = nullptr;	// Course have a list of student who enroll this course
	Student* pTailStudentEnroll = nullptr;	// use pTail for adding Student to the course easier
	Course* pNext = nullptr;
};
struct Semester {
	
	string semesterName;
	string schoolYear;
	string startDate;
	string endDate;
	string regisStartDate;
	string regisEndDate;
	Course* pHeadCourse = nullptr;
	Semester* pNext = nullptr;
};
struct SchoolYear {
	string schoolYearName;
	Class* pHeadClass = nullptr;
	Semester* pHeadSemester = nullptr;
	SchoolYear* pNext = nullptr;
};
struct  ScoreBoardOfCourse {
	string no, id, fullname, totalMark, finalMark, midtermMark, otherMark;
};
struct  ScoreBoardOfClasss {
	string no, id, fullname, subject1, subject2, subject3, subject4, subject5, subject6, gpa;

};
void SetColor(int backgound_color, int text_color);
void GoTo(SHORT posX, SHORT posY);

void loadListofSchoolYear(SchoolYear*& pHeadSchoolYear, int& schoolYearSize, char path[]);
void loadListOfClass(Class*& pHeadClass, int& sizeOfListClass, char* path);
void loadListOfSemester(Semester*& pHeadSemester, int& sizeOfListSemester, char* path);
void loadListOfStudent(Student*& pHeadStudent, int& sizeOfListStudent, char* path);
void loadListOfCourse(Course*& pHeadCourse, int& sizeOfListCourse, char* path);


//void inputStudentData(Student*& pHeadStudent, Student*& pTailStudent, char path[]);
void OutputCSVFIle(Student* pHeadStudent, char path[]);
void signUp(string path);
bool login(account*& pLogin, string loginPath, string &user);
void createSchoolYear(SchoolYear*& pHeadSchoolYear, int& schoolYearSize, char* path);
void createClass(Class*& pHeadClass, int& sizeOfClass, char* path);
void CreateYear(SchoolYear*& pHeadYear);
void CreateClass(Student* pHeadStudent, int& sizeOfClass, char* path);
//void addAllStudentsToClass(Class*& pClass);
void create1Student(Student*& pStudent);
void add1StudentToClass(Student*& pHeadStudent, int &sizeOfListStudent, char* path);
void deleteCourse(Course*& pHead, char*);
void addCourseToSemester(Course*& pCourse);
void CreateCourseRegistration(Course*& pHeadCourse, int& size, char* pathListOfCourseChar);
void CreateSemesterOfYear(SchoolYear* pTempSchoolYear, Semester*& pSemester, int& sizeOfSemester, char* path);
void UpdateCourseInformation(Course*& pHeadCourse, char* path);
void viewListOfStudents(Class* pHead);
void viewListOfCourses(Course* pHead);
void viewListOfClasses(Class* pHead);
void ViewCourse(Student* pHead);
bool enrollCourse(Course* pCourse, Student* pStudent, string &pTempCourseName);
void RemoveTheEnrolledCourse(Course* pEnrolledCourse, string defaultSemester, string defaultSchoolYear, string IdSearched);
void ViewListOfStudentInCourse(Course* pCourse);
//void ViewScoreBoard(int& numberOfStudent);
void DrawListofStudentInClass(int width, int height, int x, int y);
void ListofStudentInClass(int NumberOfStudent, Student* pHead);
void ScoreBoardOfClass(int NumberOfStudent);
void DrawScorceBoardOfClass(int width, int height, int x, int y);
string createDate();
void DrawCourseScore(int width, int height, int x, int y);
void ViewScoreBoard(char* path, int sizeOfScoreBoardOfCourse);
//int CountStudent(char* path);
//void ViewScoreBoard(char* path);
void UpdateScoreInCourse(char* path, int NumbersOfStudent, string FullNameSearched);
int ExportScore(char* path);
void ScoreBoardOfClassSemesterIII(int NumberOfStudent, char* path);
void ScoreBoardOfClassSemesterII(int NumberOfStudent, char* path);
void ScoreBoardOfClassSemesterI(int NumberOfStudent, char* path);
void DrawScoreOfStudentInClass(int width, int height, int x, int y);

