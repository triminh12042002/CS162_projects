
#include "Header.h"
using namespace std;

SchoolYear* pHeadSchoolYear = nullptr;
SchoolYear* pTempSchoolYear = nullptr;
int schoolYearSize = 0;
Class* pTempClass = nullptr;
bool isContinue = true;
void loadListofSchoolYear(SchoolYear* &pHeadSchoolYear, int &schoolYearSize, char path[]) {
	SchoolYear* pT = nullptr;
	while (pHeadSchoolYear != nullptr) {
		pT = pHeadSchoolYear;
		pHeadSchoolYear = pHeadSchoolYear->pNext;
		delete pT;
	}
	pHeadSchoolYear = nullptr;
	schoolYearSize = 0;
	ifstream fin;
	fin.open(path);
	if (fin.is_open() == false) {
		cout << "\ncannot open file";
		ofstream fout;
		fout.open(path);
		fout.close();
		fin.open(path);
		return;
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
	fin.close();
}
void loadListOfClass(Class* &pHeadClass, int& sizeOfListClass, char* path) {
	
	Class* pT = nullptr;
	while (pHeadClass != nullptr) {
		pT = pHeadClass;
		pHeadClass = pHeadClass->pNext;
		delete pT;
	}
	pHeadClass = nullptr;
	sizeOfListClass = 0;
	ifstream fin;
	fin.open(path);
	if (fin.is_open() == false) {
		cout << "\ncannot open file";
		ofstream fout;
		fout.open(path);
		fout.close();
		fin.open(path);
		return;
	}
	Class* pTemp = pHeadClass;
	string temp;
	while (!fin.eof()) {
		if (pTemp == nullptr) {
			getline(fin, temp, '\n');
			if (temp == "") break;
			pHeadClass = pTemp = new Class;
			pTemp->pNext = nullptr;
			pTemp->className = temp;
			sizeOfListClass++;

		}
		else {
			getline(fin, temp, '\n');
			if (temp == "") break;
			pTemp->pNext = new Class;
			pTemp = pTemp->pNext;
			pTemp->className = temp;
			pTemp->pNext = nullptr;
			sizeOfListClass++;
		}
	}
	fin.close();
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


	
	int Set[20];
	for (int i = 0; i < 20; ++i) {
		Set[i] = 7;
	}
	Set[0] = 2;
	int counter = 1;
	char key;



	if (true) {
		//system("cls");
		for (int i = 0;;) {

			GoTo(10, 5);
			SetColor(0, Set[0]);
			cout << "Staff";

			GoTo(10, 7);
			SetColor(0, Set[1]);
			cout << "Student";

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
				if (counter == 1) {
					cout << "\nEnter Staff";
					for (int i = 0;;) {
						if (isContinue == false) {
							cout << "\nExit\n";
							break;
						}
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
								string loginPath = "staffLoginData.txt";
								if (login(pLogin, loginPath) == true) {
									char pathCreateSchoolYear[] = "SchoolYear.csv";
									loadListofSchoolYear(pHeadSchoolYear, schoolYearSize, pathCreateSchoolYear);	// load list school year
									cout << "\nLogin successfully.";
									cout << "\nPress any key to continue.";
									key = _getch();
									system("cls");
									for (int i = 0; i < 20; ++i) {
										Set[i] = 7;
									}
									Set[0] = 2;
									counter = 1;
									
									for (int i = 0;;) {
										pTempSchoolYear = pHeadSchoolYear;
										GoTo(0, 0);
										SetColor(0, 7);
										cout << "List of school years\n";
										for (int j = 0; pTempSchoolYear != nullptr && j < schoolYearSize; ++j) {
											GoTo(10, 5 + 2 * j);
											SetColor(0, Set[j]);
											cout << pTempSchoolYear->schoolYearName;
											pTempSchoolYear = pTempSchoolYear->pNext;
										}
										GoTo(10, 5 + 2 * schoolYearSize);
										SetColor(0, Set[schoolYearSize]);
										cout << "Create School Year\n";

										key = _getch();
										if (key == 72 && counter >= 2 && counter <= schoolYearSize + 1) {
											counter--;
										}
										if (key == 80 && counter >= 1 && counter <= schoolYearSize) {
											counter++;
										}
										if (key == '\r') {
											pTempSchoolYear = pHeadSchoolYear;
											for (int j = 0; pTempSchoolYear != nullptr && j < schoolYearSize; ++j) {
												if (counter == j + 1) {
													cout << "\n enter " << pTempSchoolYear->schoolYearName;
													// load list of class in this schoolYear
													Class* pHeadClass = pTempSchoolYear->pHeadClass;
													string pathListOfClass = "Class" + pTempSchoolYear->schoolYearName + ".csv";
													int sizeOfListClass = 0;
													int size = pathListOfClass.size();
													// declaring character array
													char* pathListOfClassChar = new char[size+1];
													// string to char array
													for (int i = 0; i < size; ++i) {
														pathListOfClassChar[i] = pathListOfClass[i];
													}
													pathListOfClassChar[size] = '\0';
													loadListOfClass(pHeadClass, sizeOfListClass, pathListOfClassChar);	// load list of class int this school year
													cout << "\nnew size list" << sizeOfListClass;
													cout << "\nEnter School Year successfully.";
													cout << "\nPress any key to continue.";
													key = _getch();
													system("cls");
													for (int i = 0; i < 20; ++i) {
														Set[i] = 7;
													}
													Set[0] = 2;
													counter = 1;

													for (int i = 0;;) {
														pTempClass = pHeadClass;
														GoTo(0, 0);
														SetColor(0, 7);
														cout << "List of school years\n";
														for (int j = 0; pTempClass != nullptr && j < sizeOfListClass; ++j) {
															GoTo(10, 5 + 2 * j);
															SetColor(0, Set[j]);
															cout << pTempClass->className;
															pTempClass = pTempClass->pNext;
														}
														GoTo(10, 5 + 2 * sizeOfListClass);
														SetColor(0, Set[sizeOfListClass]);
														cout << "Create CLass";

														key = _getch();
														if (key == 72 && counter >= 2 && counter <= sizeOfListClass + 1) {
															counter--;
														}
														if (key == 80 && counter >= 1 && counter <= sizeOfListClass) {
															counter++;
														}
														if (key == '\r') {
															
															pTempClass = pHeadClass;
															for (int j = 0; pTempClass != nullptr && j < sizeOfListClass; ++j) {
																if (counter == j + 1) {
																	cout << "\n enter " << pTempClass->className;
																	// load list of class in this schoolYear
																	/*Class* pHeadClass = pTempSchoolYear->pHeadClass;
																	string pathListOfClass = "Class" + pTempSchoolYear->schoolYearName + ".csv";
																	int sizeOfListClass = 0;
																	int size = pathListOfClass.size();
																	// declaring character array
																	char* pathListOfClassChar = new char[size + 1];
																	// string to char array
																	for (int i = 0; i < size; ++i) {
																		pathListOfClassChar[i] = pathListOfClass[i];
																	}
																	pathListOfClassChar[size] = '\0';
																	loadListOfClass(pHeadClass, sizeOfListClass, pathListOfClassChar);
																	*/

																}
																else {
																	pTempClass = pTempClass->pNext;
																}
															}
															if (counter == sizeOfListClass + 1) {
																cout << "\n enter create class\n";
																/*createSchoolYear(pHeadSchoolYear, schoolYearSize, pathCreateSchoolYear);
																loadListofSchoolYear(pHeadSchoolYear, schoolYearSize, pathCreateSchoolYear);
																system("cls");
																*/
															}
															
														}
														for (int i = 0; i < 20; ++i) {
															if (counter == i + 1) Set[i] = 2;
															else Set[i] = 7;
														}

													}

												}
												else {
													pTempSchoolYear = pTempSchoolYear->pNext;
												}
											}
											if (counter == schoolYearSize + 1) {
												cout << "\n enter create schoolyear\n";
												createSchoolYear(pHeadSchoolYear, schoolYearSize, pathCreateSchoolYear);
												loadListofSchoolYear(pHeadSchoolYear, schoolYearSize, pathCreateSchoolYear);
												system("cls");
											}
										}
										for (int i = 0; i < 20; ++i) {
											if (counter == i + 1) Set[i] = 2;
											else Set[i] = 7;
										}

									}
								}
								else {
									cout << "\nYou username or your password is incorrected";
									cout << "\nPress any key to return to previous menu";
									key = _getch();
									system("cls");
								}

							}
							if (counter == 2) {
								cout << "enter sign up";
								signUp();
								cout << "\nSign up successfully.";
								cout << "\nPress any key to return to the menu\n";
								system("cls");

							}
							if (counter == 3) {
								cout << "enter exit";
								isContinue = false;
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
				if (counter == 2) {
					cout << "\nEnter Student";
				}
				if (counter == 3) {
					cout << "\nexit";
					break;
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


	
	return 0;
}
