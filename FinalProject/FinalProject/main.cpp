#include <iostream>
#include <string>
#include <fstream>
#include "function.h"
#include "Header.h"
using namespace std;

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

	while (pCur != nullptr) {
		ofs << pCur->no << ",";
		ofs << pCur->id << ",";
		ofs << pCur->firstName << ",";
		ofs << pCur->lastName << ",";
		ofs << pCur->gender << ",";
		ofs << pCur->dateOfBirth << ",";
		ofs << pCur->socialId << "\n";
		pCur = pCur->pNextStudent;
	}
}
void signUp(){
	string us,pw;
	
	cout << "Enter username : "; cin >> us;
	cout << "Enter password : "; cin >> pw;
	
	ofstream write;
	write.open("loginData.txt",ios::app);
	write << us << ',' << pw << '\n'; 
	write.close();
}
bool login(account* &pLogin, string loginPath)
{
	
	string username, password;
	cout << "Enter username : "; 
	getline(cin, username);
	cout << "Enter password : "; 
	getline(cin, password);
	
	account* pCur = nullptr;
	
	ifstream read;
	read.open(loginPath);
	while (!read.eof())
	{
		if (pCur == nullptr) {
			pLogin = pCur = new account;
			pCur->next == nullptr;
		}
		else {
			pCur->next = new account;
			pCur = pCur->next;
		}
		
		getline(read, pCur->us, ',');
		getline(read, pCur->pw, '\n');

	}
	pCur = pLogin;
	while (pCur != nullptr)
	{
		if (pCur->us == username && pCur->pw == password)
			return true;
		else pCur = pCur->next;
	}
	return false;
	read.close();
}
int main() {
	/*Student* pHeadStudent = nullptr;
	char inputPath[] = "input.csv";
	inputStudentData(pHeadStudent, inputPath);
	Student* pTemp = pHeadStudent;
	while (pTemp != nullptr) {
		cout << pTemp->firstName << endl;
		pTemp = pTemp->pNextStudent;
	}
	char outputPath[] = "output.csv";
	OutputCSVFIle(pHeadStudent, outputPath);*/
	/*signUp();
	string temp;
	getline(cin, temp);
	*/
	/*account* pLogin = nullptr;
	string loginPath = "loginData.txt";
	cout << login(pLogin, loginPath);
	*/
	return 0;
}
