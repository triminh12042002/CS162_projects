#include <iostream>

using namespace std;

struct Student {
	string no;
	string id;
	string firstName;
	string lastName;
	string gender;
	string dateOfBirth;
	string socialId;
	Course* pHeadCourse = nullptr;
	Student* pNext = nullptr;
};
struct Course{
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

void ViewCourse(Student* pHead) {
	Course* pCur = pHead->pHeadCourse;
	while (pCur != nullptr) {
		cout << "LIST OF ENROLLED COURSES: " << endl;
		cout << pCur->courseName << endl;
		pCur = pCur->pNext;
	}
}