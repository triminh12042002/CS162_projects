#include <string>
#include <fstream>
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
	Student* pNextStudent = nullptr;
};

struct Class {
	string className;
	Student* pHeadStudent = nullptr;	// first student in the list of students of this class
	Student* pTailStudent = nullptr;// last student 
	Class* pNext = nullptr;
};

struct Year {
	int Start;
	int End;
};

void CreateClass(Student* pHeadStudent) {
	Class* pHeadClass = new Class;
	Class* pCurClass = pHeadClass;
	Student* pCurStudent = pHeadClass->pHeadStudent;
	while (pCurClass != nullptr) {
		while (pCurStudent != pCurClass->pTailStudent) {
			//void inputStudentData(Student*& pHeadStudent, char path[]);
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
			pCurClass = pCurClass->pNext;
		}
	}
	return;
}

void CreateYear() {
	Year SchoolYear;
	cout << "Input the beginning year: ";
	cin >> SchoolYear.Start;
	SchoolYear.End = SchoolYear.Start + 1;
	cout << "This is the " << SchoolYear.Start << "-" << SchoolYear.End << " School Year.";


}