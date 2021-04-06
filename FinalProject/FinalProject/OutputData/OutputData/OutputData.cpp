#include <iostream>
#include <fstream>
#include <string>

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

void OutputCSVFIle(Student* pHeadStudent, char path[]) {
	ofstream ofs;
	ofs.open(path);
	if (!ofs.is_open()) {
		cout << "Khong mo duoc file.";
		return;
	}
	Student* pCur = pHeadStudent;

	while (!ofs.eof()) {
		ofs << pCur->no << ",";
		ofs << pCur->id << ",";
		ofs << pCur->firstName << ",";
		ofs << pCur->lastName << ",";
		ofs << pCur->gender << ",";
		ofs << pCur->dateOfBirth << ",";
		ofs << pCur->socialId << ",";
		if (pCur != nullptr) {
			pCur = pCur->pNextStudent;
		}
	}
}