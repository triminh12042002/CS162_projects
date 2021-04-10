#pragma once
#include <string>
#include <fstream>
using namespace std;
struct account {
	string us;		//username 
	string pw;		//password
	account* next = nullptr;
};
struct Student {
	string no;
	string id;
	string firstName;
	string lastName;
	string gender;
	string dateOfBirth;
	string socialId;
	Student* pNextStudent = nullptr;
};
struct Class {
	string className;
	Student* pHeadStudent = nullptr;	// first student in the list of students of this class
	Student* pTailStudent = nullptr;				// last student 
	Class* pNextClass = nullptr;
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
	Course* pNextCourse = nullptr;
};
struct Semester {
	string semesterName;
	string schoolYear;
	string startDate;
	string endDate;
	Course* pHeadCourse = nullptr;
	Semester* pNextSemester = nullptr;
};
struct SchoolYear {
	string schoolYearName;
	Semester* pHeadSemester = nullptr;
	SchoolYear* pNextSchoolYear = nullptr;
};

