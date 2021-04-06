#include <iostream>
#include <string>
#include <fstream>
#include "function.h"
using namespace std;
struct account{
	//username 
	string us;
	//password
	string pw;
	account*next;
}
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
void OutputCSVFIle(Student* pHeadStudent, char path[]) {
	if (pHeadStudent == nullptr) return;
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
void signUp(){
	string us,pw;
	
	cout << "Enter username : "; cin >> us;
	cout << "Enter password : "; cin >> pw;
	
	ofstream write;
	write.open("file.txt",ios::app);
	write << us << pw; 
	write.close();
}
bool login(account* login, string username, string password)
{
	account* pCur = login;
	ifstream read;
	read.open("file.txt");
	while (pCur != nullptr)
	{
		getline(read, pCur->us);
		getline(read, pCur->pw);
		pCur = pCur->next;
	}
	while (login != nullptr)
	{
		if (login->us = username && login->pw = password)
			return true;
		else login = login->next;
	}
	if (login != nullptr) return false;
	read.close();
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
