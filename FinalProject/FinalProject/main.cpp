
#include "Header.h"
using namespace std;

SchoolYear* pHeadSchoolYear = nullptr;
SchoolYear* pTempSchoolYear = nullptr;
int schoolYearSize = 0;
void loadListofSchoolYear(SchoolYear* &pHeadSchoolYear, int &schoolYearSize, char path[]) {
	ifstream fin;
	fin.open(path);
	if (fin.is_open() == false) {
		cout << "cannot open file\n";
	}
	SchoolYear* pTemp = pHeadSchoolYear;
	string temp;
	while (!fin.eof()) {
		if (pTemp == nullptr) {
			getline(fin, temp,'\n');
			if (temp == "") break;
			pHeadSchoolYear = pTemp = new SchoolYear;		
			pTemp->pNext = nullptr;
			pTemp->schoolYearName = temp;
			schoolYearSize++;

		}
		else {
			getline(fin, temp,'\n');
			if (temp == "") break;
			pTemp->pNext = new SchoolYear;
			pTemp = pTemp->pNext;			
			pTemp->schoolYearName = temp;
			pTemp->pNext = nullptr;
			schoolYearSize++;
		}
	}
}
int main(){

	// input student from csv file to a list
	// output student data to a csv file

	/*Student* pHeadStudent = nullptr;
	Student* pTailStudent = nullptr;
	char inputPath[] = "input.csv";
	inputStudentData(pHeadStudent, pTailStudent, inputPath);
	Student* pTemp = pHeadStudent;
	while (pTemp != nullptr) {
		cout << pTemp->firstName << endl;
		pTemp = pTemp->pNext;
	}
	cout << endl;
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

	/*
	// create 1 class
	Class* pClass = new Class;	
	// input student data from csv file to class list of student
	addAllStudentsToClass(pClass);
	// add 1 more student to this class
	add1StudentToClass(pClass);
	cout << "tail: " << pClass->pTailStudent->no;
	*/
	/*Course* pHeadCourse = nullptr;
	char path[] = "Toan";
	UpdateCourseInformation(pHeadCourse, path);*/
	char schoolYearPath[] = "SchoolYear.csv";
	loadListofSchoolYear(pHeadSchoolYear, schoolYearSize, schoolYearPath);
	int Set[20];
	for (int i = 0; i < 20; ++i) {
		Set[i] = 7;
	}
	Set[0] = 2;
	int counter = 1;
	char key;

	for (int i = 0;;) {	
		
		GoTo(10, 5);
		SetColor(0, Set[0]);
		cout << "Login";

		GoTo(10, 7);
		SetColor(0, Set[1]);
		cout << "Sign up";

		GoTo(10, 9);
		SetColor(0, Set[2]);
		cout << "Exit";
		key = _getch();
		if (key == 72 && counter >= 2 && counter <= 3) {
			counter--;
		}
		if (key == 80 && counter >= 1 && counter <= 2) {
			counter++;
		}
		if (key == '\r') {
			if (counter == 1) {			// access in login option
				cout << "enter login";
				account* pLogin = nullptr;
				string loginPath = "loginData.txt";
				if (login(pLogin, loginPath) == true) {
					cout << "\nLogin successfully.";
					cout << "Press any key to continue.";
					key = _getch();
					system("cls");
					for (int i = 0;;) {
						pTempSchoolYear = pHeadSchoolYear;
						cout << "List of school years\n";
						for (int j = 0; pTempSchoolYear != nullptr && j < schoolYearSize; ++j) {
							GoTo(10, 5 + 2*j);
							SetColor(0, Set[j]);
							cout << pTempSchoolYear->schoolYearName;
							pTempSchoolYear = pTempSchoolYear->pNext;
						}
						key = _getch();
						if (key == 72 && counter >= 2 && counter <= schoolYearSize) {
							counter--;
						}
						if (key == 80 && counter >= 1 && counter <= schoolYearSize-1) {
							counter++;
						}
						if (key == '\r') {
							for (int j = 0; pTempSchoolYear != nullptr && j < schoolYearSize; ++j) {
								if (counter == j + 1) cout << " enter " << pTempSchoolYear->schoolYearName;
							}				
						}
						for (int i = 0; i < 20; ++i) {
							if (counter == i + 1) Set[i] = 2;
							else Set[i] = 7;							
						}
						
					}
				}
				else {
					cout << "You username or your password is incorrected.\n";
					cout << "Press any key to return to previous menu.";
					key = _getch();
				}
				
			} 
			if (counter == 2) {
				cout << "enter sign up";
				signUp();
				cout << "Sign up successfully.";
				
			} 
			if (counter == 3) {
				cout << "enter exit";
			}
		}
		Set[0] = Set[1] = Set[2] = 7;
		if (counter == 1) {
			Set[0] = 2;
		}
		if (counter == 2) {
			Set[1] = 2;
		}
		if (counter == 3) {
			Set[2] = 2;
		}
	}

	return 0;
}
