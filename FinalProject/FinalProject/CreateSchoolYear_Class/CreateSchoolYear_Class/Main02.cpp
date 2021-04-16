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
	Year* pNextYear;
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
}