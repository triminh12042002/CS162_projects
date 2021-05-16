
#include "Header.h"
using namespace std;

SchoolYear* pHeadSchoolYear = nullptr;
SchoolYear* pTempSchoolYear = nullptr;
int schoolYearSize = 0;
Class* pHeadClass = nullptr;
Class* pTempClass = nullptr;
Semester* pHeadSemester = nullptr;
Course* pHeadCourse = nullptr;
Student* pHeadStudent = nullptr;
Semester* pTempSemester = nullptr;
Course* pTempCourse = nullptr;
Student* pTempStudent = nullptr;
bool isContinue = true;

int main(){
	const string defaultSchoolYear = "2020-2021";
	const string defaultSemester = "2";
	const string defaultYear = "2021";
	const string defaultMonth = "5";
	const string defaultDay = "16";
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
							string staffLoginPath = "staffLoginData.csv";
							SetColor(0, 7);
							if (counter == 1) {			// access in login option
								cout << "\nenter login";
								account* pLogin = nullptr;
								string user;
								if (login(pLogin, staffLoginPath,user) == true) {
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
																	cout << "Number of Semester" << sizeOfListSemester;
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
																		system("cls");
																		pTempSemester = pHeadSemester;
																		for (int j = 0; pTempSemester != nullptr && j < sizeOfListSemester; ++j) {
																			if (counter == j + 1) {
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
																				loadListOfCourse(pHeadCourse, sizeOfListCourse, pathListOfCourseChar);	// load list of course in  this school year
																				pTempSemester->pHeadCourse = pHeadCourse;
																			//	system("cls");
																				for (int i = 0; i < 20; ++i) {
																					Set[i] = 7;
																				}
																				Set[0] = 2;
																				counter =  1;

																				for (int i = 0;;) {
																					pTempCourse = pHeadCourse;
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
																					cout << "Number of course: " << sizeOfListCourse;
																					
																					GoTo(15, 3);
																					SetColor(0, 6);
																					cout << "the beginning of a semester";

																					GoTo(10, 5 );
																					SetColor(0, Set[0]);
																					cout << "View Courses";

																					GoTo(10, 5 + 2 * 1);
																					SetColor(0, Set[1]);
																					cout << "Add Course";

																					GoTo(10, 5 + 2 * 2);
																					SetColor(0, Set[2]);
																					cout << "Update Course Information";

																					GoTo(10, 5 + 2 * 3);
																					SetColor(0, Set[3]);
																					cout << "Delete Course";

																					GoTo(15, 5 + 2 * 4);
																					SetColor(0, 6);
																					cout << "The end of semester";

																					GoTo(10, 5 + 2 * 5);
																					SetColor(0, Set[4]);
																					cout << "Export list of student";

																					GoTo(10, 5 + 2 * 6);
																					SetColor(0, Set[5]);
																					cout << "Import list of scoreboard of course";

																					GoTo(10, 5 + 2 * 7);
																					SetColor(0, Set[6]);
																					cout << "View scoreboard of course";

																					GoTo(10, 5 + 2 * 8);
																					SetColor(0, Set[7]);
																					cout << "Update student result";

																					GoTo(10, 5 + 2 * 9);
																					SetColor(0, Set[8]);
																					cout << "View scoreboard of course"; 

																					GoTo(10, 5 + 2 * 10);
																					SetColor(0, Set[9]);
																					cout << "Return";

																					GoTo(10, 5 + 2 * 11);
																					SetColor(0, Set[10]);
																					cout << "Back to first menu";

																					key = _getch();
																					if (key == 72 && counter >= 2 && counter <=  11) {
																						counter--;
																					}
																					if (key == 80 && counter >= 1 && counter <= 10) {
																						counter++;
																					}
																					if (key == '\r') {
																						if (counter == 1) {	// view courses
																							system("cls");
																							pTempCourse = pHeadCourse;
																							cout << "number of course:" << sizeOfListCourse << endl;
																							int j = 0;
																							while(pTempCourse != nullptr) {
																								GoTo(10, 5  + j*2);
																								cout << pTempCourse->courseName;
																								pTempCourse = pTempCourse->pNext;
																								j++;
																							}
																							cout << "\n\n Press any key to return";
																							key = _getch();
																							system("cls");
																						}
																						if (counter ==  2) {  // add course
																							CreateCourseRegistration(pHeadCourse,sizeOfListCourse, pathListOfCourseChar);
																							for (int i = 0; i < 20; ++i) {
																								Set[i] = 7;
																							}
																							Set[sizeOfListCourse] = 2;
																							counter =  1;
																							system("cls");
																						}
																						if (counter == 3) {	//update course info
																							system("cls");
																							cout << "enter update course info";
																							// load list of course in semester
																							UpdateCourseInformation(pHeadCourse, pathListOfCourseChar);
																							system("cls");

																						}
																						if (counter == 4) {	//delete course
																							system("cls");

																							cout << "enter delete course";
																							deleteCourse(pHeadCourse, pathListOfCourseChar);
																							system("cls");

																						}
																						if (counter == 5) {	//export list of student
																							cout << "enter export";

																						}
																						if (counter == 6) {	//import score board
																							cout << "enter import score board";
																						}
																						if (counter == 7) {	// view scoreboard of score
																							cout << "enter view scoreboard of score";
																						}
																						if (counter == 8) {	//update student result
																							cout << "enter update student result";
																						}
																						if (counter == 9) {	//view scoreboard of class
																							Course* pCur = nullptr;
																							string courseName;
																							pCur = pHeadCourse;
																							cout << "Which Course do you want to Update? Please Input the Course's name: ";
																							getline(cin, courseName);
																							while (pCur != nullptr && pCur->courseName != courseName)
																							{
																								pCur = pCur->pNext;
																							}
																							//Look for the Course 
																							if (pCur == nullptr)
																							{
																								cout << "This Course does not exist in this semester.";
																								
																							}
																							if (pCur->courseName == courseName) {
																								// load list of course in this semester
																								string pathScoreCourse = "ScoreBoard" + pCur->courseName + pTempSemester->semesterName + pTempSchoolYear->schoolYearName + ".csv";
																								int sizeOfScoreCourse = 0;
																								int size = pathScoreCourse.size();
																								// declaring character array
																								char* pathScoreCourseChar = new char[size + 1];
																								// string to char array
																								for (int i = 0; i < size; ++i) {
																									pathScoreCourseChar[i] = pathScoreCourse[i];
																								}
																								pathScoreCourseChar[size] = '\0';

																								cout << "enter view scoreboard of class";
																								//ViewScoreBoard(pathScoreCourseChar);
																							}
																							
																						}
																						if (counter == 10) {	// return
																							counter = 0;
																							system("cls");
																							break;
																						}
																						if (counter ==  11) {	// first menu
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
								signUp(staffLoginPath);
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
							string studentLoginPath = "studentLoginData.csv";
							if (counter == 1) {			// access in login option
								cout << "\nenter login";
								account* pLogin = nullptr;
								string user;
								if (login(pLogin, studentLoginPath, user) == true) {
									cout << "\nLogin successfully.";
									system("cls");
									for (int i = 0;;) {
										if (isContinue == false) break;
										if (counter == 0) {
											for (int i = 0; i < 20; ++i) {
												Set[i] = 7;
											}
											Set[0] = 2;
											counter = 1;
										}

										GoTo(10, 3);
										SetColor(0, 4);
										cout << "a course registration session is active";


										GoTo(10, 5);
										SetColor(0, Set[0]);
										cout << "Enroll";

										GoTo(10, 7);
										SetColor(0, Set[1]);
										cout << "View enrolled courses";

										GoTo(10, 9);
										SetColor(0, Set[2]);
										cout << "Remove enrolled course";

										GoTo(10, 11);
										SetColor(0, 4);
										cout << "a course registration session is close";

										GoTo(10, 13);
										SetColor(0, Set[3]);
										cout << "View list of your course";

										GoTo(10, 15);
										SetColor(0, Set[4]);
										cout << "View list of Class";

										GoTo(10, 17);
										SetColor(0, Set[5]);
										cout << "View list of student in class";

										GoTo(10, 19);
										SetColor(0, Set[6]);
										cout << "View list of course";

										GoTo(10, 21);
										SetColor(0, Set[7]);
										cout << "View list of student in course";

										GoTo(10, 23);
										SetColor(0, Set[8]);
										cout << "Return";
										key = _getch();
										if (key == 72 && counter >= 2 && counter <= 9) {
											counter--;
										}
										if (key == 80 && counter >= 1 && counter <= 8) {
											counter++;
										}
										if (key == '\r') {
											SetColor(0, 7);
											// default is the present school year 2020-2021
											Class* pHeadClass = nullptr;
											string pathListOfClass = "Class" + defaultSchoolYear + ".csv";
											int sizeOfListClass = 0;
											int size;
											size = pathListOfClass.size();
											char* pathListOfClassChar = new char[size + 1];
											for (int i = 0; i < size; ++i) {
												pathListOfClassChar[i] = pathListOfClass[i];
											}
											pathListOfClassChar[size] = '\0';
											loadListOfClass(pHeadClass, sizeOfListClass, pathListOfClassChar);	// load list Class
											pTempClass = pHeadClass;
											Student* pHeadStudent = nullptr;
											int sizeOfListStudent = 0;

											string pathListOfStudent;

											char* pathListOfStudentChar;

											while (pTempClass != nullptr) {
												pathListOfStudent = "Student" + pTempClass->className + "2020-2021.csv";
												sizeOfListStudent = 0;
												size = pathListOfStudent.size();
												pathListOfStudentChar = new char[size + 1];
												for (int i = 0; i < size; ++i) {
													pathListOfStudentChar[i] = pathListOfStudent[i];
												}
												pathListOfStudentChar[size] = '\0';
												//cout << endl << pathListOfStudentChar;
												loadListOfStudent(pTempClass->pHeadStudent, sizeOfListStudent, pathListOfStudentChar);
												pHeadStudent = pTempClass->pHeadStudent;
												pTempStudent = pHeadStudent;
												while (pTempStudent != nullptr) {
													cout << pTempStudent->id;
													if (pTempStudent->id == user) {
														cout << "\nfind";
														break;	// find student
													}
													pTempStudent = pTempStudent->pNext;
												}
												if (pTempStudent != nullptr) break;	// success find the student in class
												pTempClass = pTempClass->pNext;
											}
											if (pTempStudent == nullptr) {
												cout << "cannot find your class";

												break;
											}
											Student* pStudent = pTempStudent;
											Course* pHeadEnrolledCourse = nullptr;	// load enrolled course by this student to pHeadEnrolledCourse
											Course* pTempEnrolledCourse = pHeadEnrolledCourse;
											string pathListOfCourse = "Course" + defaultSemester + defaultSchoolYear + ".csv";
											size = pathListOfCourse.size();
											char* pathListOfCourseChar = new char[size + 1];
											for (int i = 0; i < size; ++i) {
												pathListOfCourseChar[i] = pathListOfCourse[i];
											}
											pathListOfCourseChar[size] = '\0';
											Course* pHeadCourse = nullptr; // pHeadCourse for list course in this default semester
											//cout << endl << pathListOfCourseChar;
											loadListOfCourse(pHeadCourse, sizeOfListClass, pathListOfCourseChar);
											pTempCourse = pHeadCourse;
											int sizeOfListEnrolledCourse = 0;

											string pathListOfStudentInCourse;
											char* pathListOfStudentInCourseChar;

											while (pTempCourse != nullptr) {
												pathListOfStudentInCourse = "Student" + pTempCourse->courseName + defaultSemester + defaultSchoolYear + ".csv";
												sizeOfListStudent = 0;
												size = pathListOfStudentInCourse.size();
												pathListOfStudentInCourseChar = new char[size + 1];
												for (int i = 0; i < size; ++i) {
													pathListOfStudentInCourseChar[i] = pathListOfStudentInCourse[i];
												}
												pathListOfStudentInCourseChar[size] = '\0';
												//cout << endl << pathListOfStudentInCourseChar;
												Student* pHeadStudentInCourse = nullptr;
												loadListOfStudent(pHeadStudentInCourse, sizeOfListStudent, pathListOfStudentInCourseChar);	// load list of student in course
												if (pHeadStudentInCourse == nullptr) {
													//cout << "\nno student in this course";
												}
												else {
													//cout << endl << pHeadStudentInCourse->firstName << endl;
												}
												pTempStudent = pHeadStudentInCourse;
												while (pTempStudent != nullptr) {	
													//cout << "  id: " << pTempStudent->id << "    user: " << user << endl;	// print all student in 1 course
													if (pTempStudent->id == user) {
														//cout << "\nfind 1 course\n";
														break; // find student
													}
													pTempStudent = pTempStudent->pNext;
												}
												if (pTempStudent != nullptr) {	// success find the student, add this course to pHeadEnrolledCourse
													Course* newCourse = new Course;
													*newCourse = *pTempCourse;
													newCourse->pNext = nullptr;
													if (pHeadEnrolledCourse == nullptr) {
														pHeadEnrolledCourse = pTempEnrolledCourse = newCourse;
													}
													else {
														pTempEnrolledCourse->pNext = newCourse;
														pTempEnrolledCourse = pTempEnrolledCourse->pNext;
													}
												}
												pTempCourse = pTempCourse->pNext;
											}
											pStudent->pHeadCourse = pHeadEnrolledCourse;
											

											if (counter == 1) {	// enroll course
												//cout << endl << user << endl;
												string pTempCourseName = "";
												if (enrollCourse(pHeadCourse, pStudent, pTempCourseName) == false || pStudent->pHeadCourse == nullptr) {
													cout << "\ncannot";
													key = _getch();
													system("cls");
												}
												else {
													pathListOfStudentInCourse = "Student" + pTempCourseName + defaultSemester + defaultSchoolYear + ".csv";
													size = pathListOfStudentInCourse.size();
													pathListOfStudentInCourseChar = new char[size + 1];
													for (int i = 0; i < size; ++i) {
														pathListOfStudentInCourseChar[i] = pathListOfStudentInCourse[i];
													}
													pathListOfStudentInCourseChar[size] = '\0';
													cout << endl << pathListOfStudentInCourseChar;
													ofstream fout;
													fout.open(pathListOfStudentInCourseChar, ios::app);	// add that student to file list of student in course 
													if (!fout.is_open()) {
														cout << "\ncannot open file";
														break;
													}
													fout << pStudent->no << ',';
													fout << pStudent->id << ',';
													fout << pStudent->firstName << ',';
													fout << pStudent->lastName << ',';
													fout << pStudent->gender << ',';
													fout << pStudent->dateOfBirth << ',';
													fout << pStudent->socialId << '\n';
													fout.close();
													cout << "\n write success";
													key = _getch();
													system("cls");
												}
												
											}
											if (counter == 2) {	// view enrolled course
												if (pHeadEnrolledCourse == nullptr) {
													cout << "\nNot enroll any course";
												}
												else {
													Course* pTemp = pHeadEnrolledCourse;
													viewListOfCourses(pTemp);
												}

											}
											if (counter == 3) {	// remove course
												RemoveTheEnrolledCourse(pStudent->pHeadCourse, defaultSemester, defaultSchoolYear, user);
											}
											if (counter == 4) {	// view list of his/her course
												if (pHeadEnrolledCourse == nullptr) {
													cout << "\nNot enroll any course";
												}
												else {
													Course* pTemp = pHeadEnrolledCourse;
													viewListOfCourses(pTemp);
												}
											}
											if (counter == 5) {	// view list of classes
												viewListOfClasses(pHeadClass);
												key = _getch();
												cout << "\n\nPress any key to return";
											}
											if (counter == 6) {	// view list of student in class
												pTempClass = pHeadClass;
												cout << "\nenter the class name";
												string className;
												getline(cin, className);
												while (pTempClass != nullptr && pTempClass->className != className) {
													pTempClass = pTempClass->pNext;
												}
												if (pTempClass != nullptr) {
													pathListOfStudent = "Student" + pTempClass->className + defaultSchoolYear + ".csv";
													sizeOfListStudent = 0;
													size = pathListOfStudent.size();
													pathListOfStudentChar = new char[size + 1];
													for (int i = 0; i < size; ++i) {
														pathListOfStudentChar[i] = pathListOfStudent[i];
													}
													pathListOfStudentChar[size] = '\0';
													cout << endl << pathListOfStudentChar;
													loadListOfStudent(pTempClass->pHeadStudent, sizeOfListStudent, pathListOfStudentChar);
													// view 
													ListofStudentInClass(sizeOfListStudent, pTempClass->pHeadStudent);
													cout << "\n view success";
												}
												else {
													cout << "\n\nCannot find the class name that you enter.\n Please enter exactly.";
												}
												cout << "\n\npress any key to return";
												key = _getch();

												system("cls");
											}
											if (counter == 7) {	// view list of courses
												viewListOfCourses(pHeadCourse);
												cout << "\n\npress any key to return";
												key = _getch();

												system("cls");
											}
											if (counter == 8) {	// view list of student in course
												pTempCourse = pHeadCourse;
												cout << "\nenter the course name";
												string courseName;
												getline(cin, courseName);
												while (pTempCourse != nullptr && pTempCourse->courseName != courseName) {
													pTempCourse = pTempCourse->pNext;
												}
												if (pTempCourse != nullptr) {
													pathListOfStudentInCourse = "Student" + pTempCourse->courseName + defaultSemester + defaultSchoolYear + ".csv";
													sizeOfListStudent = 0;
													size = pathListOfStudentInCourse.size();
													pathListOfStudentInCourseChar = new char[size + 1];
													for (int i = 0; i < size; ++i) {
														pathListOfStudentInCourseChar[i] = pathListOfStudentInCourse[i];
													}
													pathListOfStudentInCourseChar[size] = '\0';
													cout << endl << pathListOfStudentInCourseChar;
													Student* pHeadStudentInCourse = nullptr;
													loadListOfStudent(pHeadStudentInCourse, sizeOfListStudent, pathListOfStudentInCourseChar);
													// view
													ListofStudentInClass(sizeOfListStudent, pHeadStudentInCourse);
													cout << "\n view success";
												}
												else {
													cout << "\n\nCannot find the course name that you enter.\n Please enter exactly.";
												}
												
												cout << "\n\npress any key to return";
												key = _getch();

												system("cls");
											}
											if (counter == 9) {	// return
												counter = 0;
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
								signUp(studentLoginPath);
								cout << "\nSign up successfully.";
								cout << "\nPress any key to return to the menu\n";
								system("cls");

							}
							if (counter == 3) {	// return
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
