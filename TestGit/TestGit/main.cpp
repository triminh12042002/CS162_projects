#include <iostream>
#include <string>
#include <fstream>
#include "function.h"
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
	Student* pHeadStudent;	// first element in the list of student of this class
	Class* pNextClass = nullptr;
};
void inputStudentData(Student*& pHeadStudent, char path[]) {
	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open())
	{
		cout << "Khong mo duoc file!";
		return;
	}
	Student* pTemp = nullptr;
	Student* pCur = pHeadStudent;

	while (!ifs.eof()) {
		pTemp = new Student;
		getline(ifs, pTemp->no, ',');
		getline(ifs, pTemp->id, ',');
		getline(ifs, pTemp->firstName, ',');
		getline(ifs, pTemp->lastName, ',');
		getline(ifs, pTemp->gender, ',');
		getline(ifs, pTemp->dateOfBirth, ',');
		getline(ifs, pTemp->socialId, '\n');
		if (pCur != nullptr) {
			pCur->pNextStudent = pTemp;
			pCur = pTemp;
		}
		else {
			pHeadStudent = pCur = pTemp;
		}

	}
}
int main() {
	Student* pHeadStudent = nullptr;
	char inputPath[] = "input.csv";
	inputStudentData(pHeadStudent, inputPath);
	Student* pTemp = pHeadStudent;
	while (pTemp != nullptr) {
		cout << pTemp->firstName << endl;
		pTemp = pTemp->pNextStudent;
	}
	return 0;
}