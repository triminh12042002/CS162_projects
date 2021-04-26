
#include "Header.h"
using namespace std;


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
	int Set[] = {2,7,7,7,7,7,7,7,7};
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

						GoTo(10, 5);
						SetColor(0, Set[0]);
						cout << "Create a school year";

						GoTo(10, 9);
						SetColor(0, Set[1]);
						cout << "Create Class";

						GoTo(10, 11);
						SetColor(0, Set[2]);
						cout << "Add 1 student to class";

						GoTo(10, 13);
						SetColor(0, Set[2]);
						cout << "Add all students to class";

						GoTo(10, 15);
						SetColor(0, Set[3]);
						cout << "Create Semester";

						GoTo(10, 17);
						SetColor(0, Set[4]);
						cout << "Create Course";

						key = _getch();
						if (key == 72 && counter >= 2 && counter <= 3) {
							counter--;
						}
						if (key == 80 && counter >= 1 && counter <= 2) {
							counter++;
						}
						if (key == '\r') {
							if (counter == 1) {
								cout << "enter login";
								account* pLogin = nullptr;
								string loginPath = "loginData.txt";
								if (login(pLogin, loginPath) == true) {
									cout << "\nLogin successfully.";
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
