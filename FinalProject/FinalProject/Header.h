#pragma once
#include <iostream>
#include <string>
#include <string>
#include <fstream>
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
	Course* pHeadCourse = nullptr;
	Semester* pNext = nullptr;
};
struct SchoolYear {
	string schoolYearName;
	Class* pHeadClass = nullptr;
	Semester* pHeadSemester = nullptr;
	SchoolYear* pNext = nullptr;
};


void inputStudentData(Student*& pHeadStudent, Student*& pTailStudent, char path[]);
void OutputCSVFIle(Student* pHeadStudent, char path[]);
void signUp();
bool login(account*& pLogin, string loginPath);
void createSchoolYear(SchoolYear*& pHeadSchoolYear);
void addAllStudentsToClass(Class*& pClass);
void create1Student(Student*& pStudent);
void add1StudentToClass(Class*& pClass);
void deleteCourse(Semester*& pHead);
void addCourseToSemester(Semester*& pHead);
void SemesterOfYear(Semester*& pSemester, Course*& pHeadCourse, char* path);
void CreateCourseRegistration(Course*& pHeadCourse, Semester* pSemester, string path);

void UpDateData(string ThingUpdated, string& ChangeInformation);
void viewListOfStudents(Class* pHead);
void viewListOfCourses(Semester* pHead);
void viewListOfClasses(Class* pHead);
void enrollCourse(Semester* pSemester, Student* pStudent);
