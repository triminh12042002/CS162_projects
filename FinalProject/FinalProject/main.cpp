
#include "Header.h"
using namespace std;

SchoolYear* pHeadSchoolYear = nullptr;
SchoolYear* pTempSchoolYear = nullptr;
int schoolYearSize = 0;
Class* pTempClass = nullptr;
Semester* pTempSemester = nullptr;
Course* pTempCourse = nullptr;
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
		cout << "\nfirst time open file";
		fin.close();
		ofstream fout;
		fout.open(path);
		fout.close();
		fin.open(path);
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
		cout << "\nfirst time open file";
		fin.close();
		ofstream fout;
		fout.open(path);
		fout.close();
		fin.open(path);
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
void loadListOfSemester(Semester*& pHeadSemester, int& sizeOfListSemester, char* path) {

	Semester* pT = nullptr;
	while (pHeadSemester != nullptr) {
		pT = pHeadSemester;
		pHeadSemester = pHeadSemester->pNext;
		delete pT;
	}
	pHeadSemester = nullptr;
	sizeOfListSemester = 0;
	ifstream fin;
	fin.open(path);
	if (fin.is_open() == false) {
		cout << "\nfirst time open file";
		fin.close();
		ofstream fout;
		fout.open(path);
		fout.close();
		fin.open(path);
	}
	Semester* pTemp = pHeadSemester;
	string temp;
	while (!fin.eof()) {
		getline(fin, temp, ',');
		if (temp == "") break;
		if (pTemp == nullptr) {
			pHeadSemester = pTemp = new Semester;
			pTemp->pNext = nullptr;
		}
		else {
			pTemp->pNext = new Semester;
			pTemp = pTemp->pNext;
			pTemp->pNext = nullptr;
		}
		pTemp->pNext = nullptr;
		pTemp->schoolYear = temp;
		getline(fin, temp, ',');
		pTemp->semesterName = temp;
		getline(fin, temp, ',');
		pTemp->startDate = temp;
		getline(fin, temp, ',');
		pTemp->endDate = temp;
		getline(fin, temp, ',');
		pTemp->regisStartDate = temp;
		getline(fin, temp, '\n');
		pTemp->regisEndDate = temp;
		sizeOfListSemester++;
	}
	fin.close();
}
void loadListOfStudent(Student*& pHeadStudent, int& sizeOfListStudent, char* path) {

	Student* pT = nullptr;
	while (pHeadStudent != nullptr) {
		pT = pHeadStudent;
		pHeadStudent = pHeadStudent->pNext;
		delete pT;
	}
	pHeadStudent = nullptr;
	sizeOfListStudent = 0;
	ifstream fin;
	fin.open(path);
	if (fin.is_open() == false) {
		fin.close();
		ofstream fout;
		fout.open(path);
		fout.close();
		fin.open(path);
	}
	Student* pTemp = pHeadStudent;
	string temp;
	while (!fin.eof()) {
		getline(fin, temp, ',');
		if (temp == "") break;
		if (pTemp == nullptr) {
			pHeadStudent = pTemp = new Student;
			pTemp->pNext = nullptr;
		}
		else {
			pTemp->pNext = new Student;
			pTemp = pTemp->pNext;
			pTemp->pNext = nullptr;
		}
		pTemp->pNext = nullptr;
		pTemp->no = temp;
		getline(fin, pTemp->id, ',');
		getline(fin, pTemp->firstName, ',');
		getline(fin, pTemp->lastName, ',');
		getline(fin, pTemp->gender, ',');
		getline(fin, pTemp->dateOfBirth, ',');
		getline(fin, pTemp->socialId, '\n');
		sizeOfListStudent++;
	}
	fin.close();
}
void loadListOfCourse(Course*& pHeadCourse, int& sizeOfListCourse, char* path) {

	Course* pT = nullptr;
	while (pHeadCourse != nullptr) {
		pT = pHeadCourse;
		pHeadCourse = pHeadCourse->pNext;
		delete pT;
	}
	pHeadCourse = nullptr;
	sizeOfListCourse = 0;
	ifstream fin;
	fin.open(path);
	if (fin.is_open() == false) {
		fin.close();
		ofstream fout;
		fout.open(path);
		fout.close();
		fin.open(path);
	}
	Course* pTemp = pHeadCourse;
	string temp;
	while (!fin.eof()) {
		getline(fin, temp, ',');
		if (temp == "") break;
		if (pTemp == nullptr) {
			pHeadCourse = pTemp = new Course;
			pTemp->pNext = nullptr;
		}
		else {
			pTemp->pNext = new Course;
			pTemp = pTemp->pNext;
			pTemp->pNext = nullptr;
		}
		pTemp->pNext = nullptr;
		pTemp->courseName = temp;
		getline(fin, pTemp->startDate,',');
		getline(fin, pTemp->endDate, ',');
		getline(fin, pTemp->id, ',');
		getline(fin, pTemp->teacherName, ',');
		getline(fin, pTemp->numOfCredits, ',');
		getline(fin, pTemp->maxNumOfStudents, ',');
		getline(fin, pTemp->day1, ',');
		getline(fin, pTemp->hour1, ',');
		getline(fin, pTemp->day2, ',');
		getline(fin, pTemp->hour2, '\n');
		sizeOfListCourse++;
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
			isContinue = true;
			if (counter == 0) {
				for (int i = 0; i < 20; ++i) {
					Set[i] = 7;
				}
				Set[0] = 2;
				counter = 1;
			}
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
				SetColor(0, 7);
				if (counter == 1) {
					cout << "\nEnter Staff";
					for (int i = 0;;) {
						if (isContinue == false) break;
						if (counter == 0) {
							for (int i = 0; i < 20; ++i) {
								Set[i] = 7;
							}
							Set[0] = 2;
							counter = 1;
						}
						GoTo(10, 5);
						SetColor(0, Set[0]);
						cout << "Login";

						GoTo(10, 7);
						SetColor(0, Set[1]);
						cout << "Sign up";

						GoTo(10, 9);
						SetColor(0, Set[2]);
						cout << "Return";
						key = _getch();
						if (key == 72 && counter >= 2 && counter <= 3) {
							counter--;
						}
						if (key == 80 && counter >= 1 && counter <= 2) {
							counter++;
						}
						if (key == '\r') {
							SetColor(0, 7);
							if (counter == 1) {			// access in login option
								cout << "\nenter login";
								account* pLogin = nullptr;
								string loginPath = "staffLoginData.csv";
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
										if (isContinue == false) break;
										if (counter == 0) {
											for (int i = 0; i < 20; ++i) {
												Set[i] = 7;
											}
											Set[0] = 2;
											counter = 1;
										}
										pTempSchoolYear = pHeadSchoolYear;
										GoTo(10, 5);
										SetColor(0, 7);
										cout << "List of school years\n";
										for (int j = 0; pTempSchoolYear != nullptr && j < schoolYearSize; ++j) {
											GoTo(10, 7 + 2 * j);
											SetColor(0, Set[j]);
											cout << pTempSchoolYear->schoolYearName;
											pTempSchoolYear = pTempSchoolYear->pNext;
										}
										GoTo(10, 7 + 2 * schoolYearSize);
										SetColor(0, Set[schoolYearSize]);
										cout << "Create School Year\n";

										GoTo(10, 7 + 2 * (schoolYearSize + 1));
										SetColor(0, Set[schoolYearSize + 1]);
										cout << "Return\n";

										GoTo(10, 7 + 2 * (schoolYearSize + 2));
										SetColor(0, Set[schoolYearSize + 2]);
										cout << "Back to first menu\n";

										key = _getch();
										if (key == 72 && counter >= 2 && counter <= schoolYearSize + 3) {
											counter--;
										}
										if (key == 80 && counter >= 1 && counter <= schoolYearSize + 2) {
											counter++;
										}
										if (key == '\r') {
											pTempSchoolYear = pHeadSchoolYear;
											for (int j = 0; j < schoolYearSize && pTempSchoolYear != nullptr; ++j) {
												if (isContinue == false) break;
												if (counter == j + 1) {
													cout << "\n enter " << pTempSchoolYear->schoolYearName;
													key = _getch();
													system("cls");
													for (int i = 0; i < 20; ++i) {
														Set[i] = 7;
													}
													Set[0] = 2;
													counter = 1;

													for (int i = 0;;) {
														if (isContinue == false) break;
														if (counter == 0) {
															for (int i = 0; i < 20; ++i) {
																Set[i] = 7;
															}
															Set[0] = 2;
															counter = 1;
														}
														GoTo(10, 5);
														SetColor(0, Set[0]);
														cout << "Class";
														
														GoTo(10, 5 + 2);
														SetColor(0, Set[1]);
														cout << "Semester";

														GoTo(10, 5 + 4);
														SetColor(0, Set[2]);
														cout << "Return";

														key = _getch();
														if (key == 72 && counter >= 2 && counter <= 3) {
															counter--;
														}
														if (key == 80 && counter >= 1 && counter <= 2) {
															counter++;
														}
														if (key == '\r') {
															if (counter == 1) {			// enter class
																// load list of class in this schoolYear
																Class* pHeadClass = pTempSchoolYear->pHeadClass;
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
																loadListOfClass(pHeadClass, sizeOfListClass, pathListOfClassChar);	// load list of class int this school year
																system("cls");
																for (int i = 0; i < 20; ++i) {
																	Set[i] = 7;
																}
																Set[0] = 2;
																counter = 1;

																for (int i = 0;;) {
																	pTempClass = pHeadClass;
																	if (isContinue == false) break;
																	if (counter == 0) {
																		for (int i = 0; i < 20; ++i) {
																			Set[i] = 7;
																		}
																		Set[0] = 2;
																		counter = 1;
																	}
																	GoTo(0, 0);
																	SetColor(0, 7);
																	cout << "List of Classes";
																	for (int j = 0; pTempClass != nullptr && j < sizeOfListClass; ++j) {
																		GoTo(10, 5 + 2 * j);
																		SetColor(0, Set[j]);
																		cout << pTempClass->className;
																		pTempClass = pTempClass->pNext;
																	}
																	GoTo(10, 5 + 2 * sizeOfListClass);
																	SetColor(0, Set[sizeOfListClass]);
																	cout << "Create CLass";

																	GoTo(10, 5 + 2 * (sizeOfListClass + 1));
																	SetColor(0, Set[sizeOfListClass + 1]);
																	cout << "Return";

																	GoTo(10, 5 + 2 * (sizeOfListClass + 2));
																	SetColor(0, Set[sizeOfListClass + 2]);
																	cout << "Back to first menu";

																	key = _getch();
																	if (key == 72 && counter >= 2 && counter <= sizeOfListClass + 3) {
																		counter--;
																	}
																	if (key == 80 && counter >= 1 && counter <= sizeOfListClass + 2) {
																		counter++;
																	}
																	if (key == '\r') {

																		pTempClass = pHeadClass;
																		for (int j = 0; pTempClass != nullptr && j < sizeOfListClass; ++j) {
																			if (isContinue == false) break;
																			if (counter == j + 1) {
																				cout << "\n enter " << pTempClass->className;
																				// load list of student in this class
																				Student* pHeadStudent = pTempClass->pHeadStudent;
																				string pathListOfStudent = "Student" + pTempClass->className + pTempSchoolYear->schoolYearName + ".csv";
																				int sizeOfListStudent = 0;
																				int size = pathListOfStudent.size();
																				// declaring character array
																				char* pathListOfStudentChar = new char[size + 1];
																				// string to char array
																				for (int i = 0; i < size; ++i) {
																					pathListOfStudentChar[i] = pathListOfStudent[i];
																				}
																				pathListOfStudentChar[size] = '\0';
																				loadListOfStudent(pHeadStudent, sizeOfListStudent, pathListOfStudentChar);	// load list of class int this school year
																				system("cls");
																				for (int i = 0; i < 20; ++i) {
																					Set[i] = 7;
																				}
																				Set[0] = 2;
																				counter = 1;
																				for (int i = 0;;) {
																					GoTo(10, 5 + 2 );
																					SetColor(0, Set[0]);
																					cout << "Add 1 student";

																					GoTo(10, 5 + 4);
																					SetColor(0, Set[1]);
																					cout << "Add all student";

																					GoTo(10, 5 + 6);
																					SetColor(0, Set[2]);
																					cout << "Return";

																					GoTo(10, 5 + 8);
																					SetColor(0, Set[3]);
																					cout << "Back to first menu";

																					key = _getch();
																					if (key == 72 && counter >= 2 && counter <= 4) {
																						counter--;
																					}
																					if (key == 80 && counter >= 1 && counter <= 3) {
																						counter++;
																					}
																					if (key == '\r') {
																						if (counter == 1) {	// add 1 student
																							cout << "\nEnter Add 1 student";
																							add1StudentToClass(pHeadStudent, sizeOfListStudent, pathListOfStudentChar);
																							OutputCSVFIle(pHeadStudent, pathListOfStudentChar);
																							system("cls");
																						} if (counter == 2) {
																							cout << "\nEnter path of csv file that store all student data";
																							char pathStudentData[50];
																							cin >> pathStudentData;
																							loadListOfStudent(pHeadStudent, sizeOfListStudent, pathStudentData);
																							OutputCSVFIle(pHeadStudent, pathListOfStudentChar);
																							system("cls");
																						} if (counter == 3) {	// return
																							counter = 0;
																							system("cls");
																							break;
																						} if (counter == 4) {	// back to first menu
																							counter = 0;
																							isContinue = 0;
																							system("cls");
																							break;
																						}
																						
																					}
																					for (int i = 0; i < 20; ++i) {
																						if (counter == i + 1) Set[i] = 2;
																						else Set[i] = 7;
																					}
																				}
																			}
																			else {
																				pTempClass = pTempClass->pNext;
																			}
																		}
																		if (counter == sizeOfListClass + 1) {	//  enter create class
																			SetColor(0, 7);
																			createClass(pHeadClass, sizeOfListClass, pathListOfClassChar);
																			system("cls");
																		}
																		if (counter == sizeOfListClass + 2) {	// return
																			counter = 0;
																			system("cls");
																			break;
																		}
																		if (counter == sizeOfListClass + 1) {	// back to first menu
																			counter = 0;
																			isContinue = 0;
																			system("cls");
																			break;
																		}
																	}
																	for (int i = 0; i < 20; ++i) {
																		if (counter == i + 1) Set[i] = 2;
																		else Set[i] = 7;
																	}
																}
															} 
															if (counter == 2) {		// enter Semester
																
																// load list of semester in this schoolYear
																Semester* pHeadSemester = pTempSchoolYear->pHeadSemester;
																string pathListOfSemester = "Semester" + pTempSchoolYear->schoolYearName + ".csv";
																int sizeOfListSemester = 0;
																int size = pathListOfSemester.size();
																// declaring character array
																char* pathListOfSemesterChar = new char[size + 1];
																// string to char array
																for (int i = 0; i < size; ++i) {
																	pathListOfSemesterChar[i] = pathListOfSemester[i];
																}
																pathListOfSemesterChar[size] = '\0';
																loadListOfSemester(pHeadSemester, sizeOfListSemester, pathListOfSemesterChar);	// load list of semester in  this school year
																system("cls");
																for (int i = 0; i < 20; ++i) {
																	Set[i] = 7;
																}
																Set[0] = 2;
																counter = 1;
																
																for (int i = 0;;) {
																	pTempSemester = pHeadSemester;
																	if (isContinue == false) break;
																	if (counter == 0) {
																		for (int i = 0; i < 20; ++i) {
																			Set[i] = 7;
																		}
																		Set[0] = 2;
																		counter = 1;
																	}
																	GoTo(0, 0);
																	SetColor(0, 7);
																	cout << "List of Semester" << sizeOfListSemester;
																	for (int j = 0; pTempSemester != nullptr && j < sizeOfListSemester; ++j) {
																		GoTo(10, 5 + 2 * j);
																		SetColor(0, Set[j]);
																		cout << "Semester " << pTempSemester->semesterName;
																		pTempSemester = pTempSemester->pNext;
																	}
																	GoTo(10, 5 + 2 * sizeOfListSemester);
																	SetColor(0, Set[sizeOfListSemester]);
																	cout << "Create Semester";

																	GoTo(10, 5 + 2 * (sizeOfListSemester + 1));
																	SetColor(0, Set[sizeOfListSemester + 1]);
																	cout << "Return";

																	GoTo(10, 5 + 2 * (sizeOfListSemester + 2));
																	SetColor(0, Set[sizeOfListSemester + 2]);
																	cout << "Back to first menu";

																	key = _getch();
																	if (key == 72 && counter >= 2 && counter <= sizeOfListSemester + 3) {
																		counter--;
																	}
																	if (key == 80 && counter >= 1 && counter <= sizeOfListSemester + 2) {
																		counter++;
																	}
																	if (key == '\r') {

																		pTempSemester = pHeadSemester;
																		for (int j = 0; pTempSemester != nullptr && j < sizeOfListSemester; ++j) {
																			if (counter == j + 1) {
																				cout << "\n enter " << pTempSemester->semesterName;

																				// load list of course in this semester
																				Course* pHeadCourse = pTempSemester->pHeadCourse;
																				string pathListOfCourse = "Course" + pTempSemester->semesterName + pTempSchoolYear->schoolYearName + ".csv";
																				int sizeOfListCourse = 0;
																				int size = pathListOfCourse.size();
																				// declaring character array
																				char* pathListOfCourseChar = new char[size + 1];
																				// string to char array
																				for (int i = 0; i < size; ++i) {
																					pathListOfCourseChar[i] = pathListOfCourse[i];
																				}
																				pathListOfCourseChar[size] = '\0';
																				loadListOfCourse(pHeadCourse, sizeOfListCourse, pathListOfCourseChar);	// load list of semester in  this school year
																				system("cls");
																				for (int i = 0; i < 20; ++i) {
																					Set[i] = 7;
																				}
																				Set[sizeOfListCourse] = 2;
																				counter = sizeOfListCourse + 1;

																				for (int i = 0;;) {
																					pTempCourse = pHeadCourse;
																					if (isContinue == false) break;
																					if (counter == 0) {
																						for (int i = 0; i < 20; ++i) {
																							Set[i] = 7;
																						}
																						Set[sizeOfListCourse] = 2;
																						counter = sizeOfListCourse + 1;
																					}
																					GoTo(0, 0);
																					SetColor(0, 7);
																					cout << "Number of course: " << sizeOfListCourse;
																					for (int j = 0; pTempCourse != nullptr && j < sizeOfListCourse; ++j) {
																						GoTo(10, 5 + 2 * j);
																						SetColor(0, Set[j]);
																						cout << pTempCourse->courseName;
																						pTempCourse = pTempCourse->pNext;
																					}
																					GoTo(10, 5 + 2 * sizeOfListCourse);
																					SetColor(0, Set[sizeOfListCourse]);
																					cout << "Add Course";

																					GoTo(10, 5 + 2 * (sizeOfListCourse + 1));
																					SetColor(0, Set[sizeOfListCourse + 1]);
																					cout << "Return";

																					GoTo(10, 5 + 2 * (sizeOfListCourse + 2));
																					SetColor(0, Set[sizeOfListCourse + 2]);
																					cout << "Back to first menu";

																					key = _getch();
																					if (key == 72 && counter >= sizeOfListCourse + 2 && counter <= sizeOfListCourse + 3) {
																						counter--;
																					}
																					if (key == 80 && counter >= sizeOfListCourse + 1 && counter <= sizeOfListCourse + 2) {
																						counter++;
																					}
																					if (key == '\r') {
																						if (counter == sizeOfListCourse + 1) {  // add course
																							CreateCourseRegistration(pHeadCourse,sizeOfListCourse, pathListOfCourseChar);
																							for (int i = 0; i < 20; ++i) {
																								Set[i] = 7;
																							}
																							Set[sizeOfListCourse] = 2;
																							counter = sizeOfListCourse + 1;
																							system("cls");
																						}
																						if (counter == sizeOfListCourse + 2) {	// return
																							counter = 0;
																							system("cls");
																							break;
																						}
																						if (counter == sizeOfListCourse + 3) {	// first menu
																							counter = 0;
																							isContinue = 0;
																							system("cls");
																							break;
																						}
																					}
																					for (int i = 0; i < 20; ++i) {
																						if (counter == i + 1) Set[i] = 2;
																						else Set[i] = 7;
																					}
																				}
	
																			}
																			else {
																				pTempSemester = pTempSemester->pNext;
																			}
																		}
																		if (counter == sizeOfListSemester + 1) {	// create semester
																			SetColor(0, 7);
																			cout << "\n enter create Semester\n";
																			CreateSemesterOfYear(pTempSchoolYear, pHeadSemester , sizeOfListSemester, pathListOfSemesterChar);
																			system("cls");
																		}
																		if (counter == sizeOfListSemester + 2) {	// return
																			counter = 0;
																			system("cls");
																			break;
																		}
																		if (counter == sizeOfListSemester + 3) {	// back to first menu
																			counter = 0;
																			isContinue = 0;
																			system("cls");
																			break;
																		}

																	}
																	for (int i = 0; i < 20; ++i) {
																		if (counter == i + 1) Set[i] = 2;
																		else Set[i] = 7;
																	}

																}
																	
																
															} 
															if (counter == 3) {
																counter = 0;
																system("cls");
																break;	// return class, semester in school year
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
												system("cls");
											}
											if (counter == schoolYearSize + 2) {	// return
												counter = 0;
												system("cls");
												break;
											}
											if (counter == schoolYearSize + 3) {	// return first menu
												counter = 0;
												isContinue = 0;
												system("cls");
												break;
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
								cout << "Enter sign up";
								signUp();
								cout << "\nSign up successfully.";
								cout << "\nPress any key to return to the menu\n";
								system("cls");

							}
							if (counter == 3) {
								counter = 0;
								system("cls");
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
				if (counter == 2) {
					cout << "\nEnter Student";
				}
				if (counter == 3) {
					cout << "\nExit";
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
