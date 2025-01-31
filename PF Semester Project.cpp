#include<iostream>  // This is standard input/out library which allows us to use imput & output operations.
#include<conio.h>   // It is used for console input/output, which allows us to read characters & control the console display.
#include<iomanip>   // It is used for input/output manipulators which allows us to use setw().
#include<string>    // for sting values
#include<fstream>   // header file for file handling.

using namespace std;
int i = 0;
void personal(int i);
void academic(int i);
void cgpaCalculator(int i);

struct student   /* We used this struct data type allows us to group multiple variables of different data types together. This structure will contain
					the information about student's id, marks, name, grade and percentage.   */
{
	int id;
	long int contact;
	string name, nameF, grade1[7], grade2[6], address, dpmt, sub1[7], sub2[6];
	double per, cgpa, sem1gpa, sem2gpa;
}
s[25];  // We used this array beacuse we want to store the data of maximum 25 students.
void insert()  // This is a funation named insert() which returns no value.
{
	system("cls");   // This function is used to clear the screen before displaying the Insert Record prompt.
	cout << "\n\n\t\t\t** Insert Record **";
	personal(i);
	academic(i);
	cgpaCalculator(i);
	i++;
	cout << "\n\n * Insert Record successfully *";
}
void personal(int i)
{

	system("cls");   // This function is used to clear the screen before displaying the Insert Record prompt.
	cout << "\n\n\t\t\t** Insert Personal Record **";

	cout << "\nEnter Student Id: ";
	cin >> s[i].id;   // This line will get input from the user and will assign to the id.
	
	cout << "Enter Student Name: ";
	cin.ignore();     			// cin.ignore() is used to clear or ignore remaning charactors in the input buffer
	getline(cin,s[i].name);
	cout << "Enter Father Name: ";
	cin.ignore();
	getline(cin,s[i].nameF);
	cout << "Enter Contact Number: ";
	cin>> s[i].contact;
	
	cout << "Enter Student Address: ";
	cin.ignore();
	getline(cin,s[i].address);
	
	ofstream file;
	file.open("studentRecord.txt",ios::app);
	if(!file)
		cout<<"Error writing on file"<<endl;
	file<<"Id:"<<","<<s[i].id<<endl;
	file<<"Name:"<<","<<s[i].name<<endl;
	file<<"Father Name: "<<","<<s[i].nameF<<endl;
	file<<"Contact Number: "<<","<<s[i].contact<<endl;
	file<<"Address"<<","<<s[i].address<<endl;
	file.close();
	
}
void academic(int i)
{
	system("cls");   // This function is used to clear the screen before displaying the Insert Record prompt.
	cout << "\n\n\t\t\t** Insert Academic Record **"<<endl;

	cout << "Enter Department: ";
	getline(cin,s[i].dpmt);   // This line will get input from the user and will assign to the id.
	cout << "\n\n\t\t** Enter Semester 1 Details **\n\n\t\t" << endl;
	ofstream file;
	file.open("semesterDetails.txt",ios::app);
	if(!file)
		cout<<"Error writing on file"<<endl;
	file<<"\tSemester 1"<<endl;
	for (int j = 0; j < 7; j++) {
		cout << "Enter the Name of Subject " << j + 1 << " : ";
		if (j>0)
			cin.ignore();
		getline(cin,s[i].sub1[j]);
		cout << "Enter the Grade of " << s[i].sub1[j] << " : ";
		cin >> s[i].grade1[j];
		
	
			
		file<<"Name of Subject:"<<","<<s[i].sub1[j]<<endl;
		file<<"Grade:"<<" "<<s[i].grade1[j]<<endl;
	}
		
		cout<<"\n\tSemester 2"<<endl;
		file<<"\n\tSemester 2"<<endl;
	for (int j = 0; j < 6; j++) {
		cout << "Enter the Name of Subject " << j + 1 << " : ";
		cin.ignore();
		getline(cin,s[i].sub2[j]);
		cout << "Enter the Grade of " << s[i].sub2[j] << " : ";
		cin>>s[i].grade2[j];
		file<<"Name of Subject:"<<","<<s[i].sub1[j]<<endl;
		file<<"Grade:"<<" "<<s[i].grade1[j]<<endl;
			
	}
	
	file.close();	
}

void cgpaCalculator(int i) 
{
	// Calculate CGPA for Semester 1
	double totalGradePoints1 = 0.0;
	double totalCredits1 = 21;
	double cred = 3;
	for (int j = 0; j < 7; j++)
	{
		if (s[i].grade1[j] == "A+" || s[i].grade1[j] == "A")
			totalGradePoints1 += 4.0 * cred;
		else if (s[i].grade1[j] == "A-")
			totalGradePoints1 += 3.67 * cred;
		else if (s[i].grade1[j] == "B+")
			totalGradePoints1 += 3.33 * cred;
		else if (s[i].grade1[j] == "B")
			totalGradePoints1 += 3.0 * cred;
		else if (s[i].grade1[j] == "B-")
			totalGradePoints1 += 2.67 * cred;
		else if (s[i].grade1[j] == "C+")
			totalGradePoints1 += 2.33 * cred;
		else if (s[i].grade1[j] == "C")
			totalGradePoints1 += 2.0 * cred;
		else if (s[i].grade1[j] == "C-")
			totalGradePoints1 += 1.67 * cred;
		else if (s[i].grade1[j] == "D+")
			totalGradePoints1 += 1.33 * cred;
		else if (s[i].grade1[j] == "D")
			totalGradePoints1 += 1.0 * cred;
		else if (s[i].grade1[j] == "F")
			totalGradePoints1 += 0.0 * cred;
		else
			totalGradePoints1 += 0.0 * cred;
	}
	
	

	// Calculate CGPA for Semester 2
	double totalGradePoints2 = 0.0;
	double totalCredits2 = 18;
	for (int j = 0; j < 6; j++)
	{
		if (s[i].grade2[j] == "A+" || s[i].grade2[j] == "A")
			totalGradePoints2 += 4.0 * cred;
		else if (s[i].grade2[j] == "A-")
			totalGradePoints2 += 3.67 * cred;
		else if (s[i].grade2[j] == "B+")
			totalGradePoints2 += 3.33 * cred;
		else if (s[i].grade2[j] == "B")
			totalGradePoints2 += 3.0 * cred;
		else if (s[i].grade2[j] == "B-")
			totalGradePoints2 += 2.67 * cred;
		else if (s[i].grade2[j] == "C+")
			totalGradePoints2 += 2.33 * cred;
		else if (s[i].grade2[j] == "C")
			totalGradePoints2 += 2.0 * cred;
		else if (s[i].grade2[j] == "C-")
			totalGradePoints2 += 1.67 * cred;
		else if (s[i].grade2[j] == "D+")
			totalGradePoints2 += 1.33 * cred;
		else if (s[i].grade2[j] == "D")
			totalGradePoints2 += 1.0 * cred;
		else if (s[i].grade2[j] == "F")
			totalGradePoints2 += 0.0 * cred;
		else
			totalGradePoints2 += 0.0 * cred;
	}

	// Calculate CGPA
	float t1 = totalGradePoints1 / totalCredits1;
	float t2 = totalGradePoints2 / totalCredits2;
	float totalGradePoints = totalGradePoints1 + totalGradePoints2;
	float totalCredits = totalCredits1 + totalCredits2;
	s[i].cgpa = totalGradePoints / totalCredits;
	s[i].sem1gpa = t1;
	s[i].sem2gpa = t2;
	ofstream file;
	file.open("semesterDetails.txt",ios::app);
	file<<"1st Semester GPA: "<<t1<<endl;
	file<<"2st Semester GPA: "<<t2<<endl;
	file<<"Total CGP: "<<s[i].cgpa<<endl;
	file.close();
}
void updateAcademic(int i)
{
	system("cls");
	cout << "\n\n\t\t\t** Update Academic Details **";

	cout << "\n\n\t\t** Enter Semester 1 Details \n\n**" << endl;
	for (int j = 0; j < 7; j++) {
		cout << "Enter the Updated Grade of " << s[i].sub1[j] << " : ";
		cin >> s[i].grade1[j];
	}

	cout << "\n\n\t\t** Enter Semester 2 Details \n\n**" << endl;
	for (int j = 0; j < 6; j++) {
		cout << "Enter the Updated Grade of " << s[i].sub2[j] << " : ";
		cin >> s[i].grade2[j];
	}

	cgpaCalculator(i);
}


void update()
{
    int found = 0;
    system("cls");
    cout << "\n\n\n\t\t\t** Update Record **";
    if (i == 0)
    {
        cout << "\n\n** No Record found! **";
        system("pause");
        return ;
    }

    int id;
    cout << "\n\n Enter Student Id: ";
    cin >> id;

    for (int a = 0; a < i; a++)
    {
        if (id == s[a].id)
        {
            cout << "\n\n Enter Student Name: ";
            cin.ignore();
            getline(cin, s[a].name);

            // Additional fields you can update
            cout << "\n\n Enter Father Name: ";
            cin.ignore();
            getline(cin, s[a].nameF);
            cout << "\n\n Enter Contact No.: ";
            cin >> s[a].contact;
            cout << "\n\n Enter Student Address: ";
            cin.ignore();
            getline(cin, s[a].address);

            // Call the updateAcademic function to update academic details
            updateAcademic(a);

            cout << "\n\n\n * Update Record Successfully * ";
            found++;
            break; // Stop searching after finding the student with the given ID
        }
    }

    if (found == 0)
        cout << "\n\n * Student ID Not Found *";

    system("pause");		// system pause is used to stop the execution of programe and wait for the usser to press a key before program exit. 
}

void search()
{
	system("cls");
	cout << "\n\n\n\t\t\t** Search Recoord **";
	if (i == 0)
		cout << "\n\n** No Record found **";
	else
	{
		int id, found = 0;
		cout << "\n Enter Student ID: ";
		cin >> id;
		for (int a = 0; a < i; a++)
		{
			if (id == s[a].id)
			{
				cout << "\n\n Student Name: " << s[a].name;
				cout << "\n\n Student Father Name: " << s[a].nameF;
				cout << "\n\n Student Contect Number: " << s[a].contact;
				cout << "\n\n Student Department: " << s[a].dpmt;
				cout << "\n\n Student Address: " << s[a].address;
				cout << "\n\n Student Semester 1 GPA: " << s[a].sem1gpa;
				cout << "\n\n Student Semester 2 GPA: " << s[a].sem2gpa;
				cout << "\n\n Student Total CGPA: " << s[a].cgpa;

				cout << "\n\n** Semester 1 Results **\n\n" << endl;
				cout << " Subjects:          Grades:" << endl;
				for (int j = 0; j < 7; j++) {
					cout <<setw(10)<< s[a].sub1[j] << "           " << s[a].grade1[j] << endl;
				}
				cout << "\n\n** Semester 2 Results **\n\n" << endl;
				cout << " Subjects:          Grades:" << endl;
				for (int j = 0; j < 6; j++) {
				cout <<setw(10)<< s[a].sub2[j] << "           " << s[a].grade2[j] << endl;
				}
				found++;
			}
		}
		if (found == 0)
			cout << "\n\n * Student ID Not Found *";
	}
	getch();
	system("pause");
}
void del()
{
	system("cls");
	int j;
	cout << "\n\n\n\t\t\t** Delete Record **";
	if (i == 0)
		cout << "\n\n** No Record found **";
	else
	{
		int id, found = 0;
		cout << "\n\n Enter Student ID: ";
		cin >> id;
		for (int a = 0; a <= i; a++)
		{
			if (id == s[a].id)
			{
				for (int m = a; m < i - 1; m++)
				{
					s[m].id = s[m + 1].id;
					s[m].name = s[m + 1].name;
					s[m].nameF = s[m + 1].nameF;
				    s[m].contact=s[m+1].contact;
					s[m].address = s[m + 1].address;
				    s[m].dpmt = s[m+1].dpmt;
				    s[m].sub1[j] = s[m+1].sub1[j];
				    s[m].grade1[j] = s[m+1].grade1[j];
				    s[m].sub2[j] = s[m+1].sub2[j];
				    s[m].grade2[j] = s[m+1].grade2[j];	    
				}
				cout << "\n\n\n Delete Record Successfully";
				found++;
				i--;   // This will decrease the total count by 1 since one record is deleted.
				break;
			}

		}
		if (found == 0)
			cout << "\n\n** Student ID not found **";
	}
	system("pause");
}
void show()
{
	system("cls");
	cout << "\n\n\n\t\t\t** Show All Record **";
	ifstream file;
	file.open("studentRecord.txt");
	ifstream semesterFile;
	semesterFile.open("semesterDetails.txt");
	if(!file)
		cout<<"Error reading file"<<endl;
	string lineFile, lineSemester;
    
    while (getline(file, lineFile) || getline(semesterFile, lineSemester)) {
        cout << lineFile << "\t" << lineSemester << endl;
    }

    semesterFile.close();
    file.close();
	semesterFile.close();
	file.close();	
	

	
	system("pause");
}
int main()
{
	system("COLOR 9F");
	cout << "\n\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t\t\t" << setw(11) << "" << setw(28) << "" << endl;
	cout << "\t\t\t\t" << setw(13) << "" << "\tSEMESTER PROJECT" << setw(5) << "" << endl;
	cout << "\t\t\t\t" << setw(11) << "" << setw(28) << "" << endl;
	cout << "\t\t\t\t\t" << "* * * * * * * * * * * * * * * * *" << endl;
	cout << "\n\tINSTITUTE: GCUF" << "\t\t\t\t\t\t\t\t\t" << setw(5) << "SEMESTER: SPRING 2023" << endl;
	cout << "\n\tDEPARTMENT: COMPUTER SCIENCE" << "\t\t\t\t\t\t\tFACULTY: PHYSICAL SCIENCE" << endl;
	cout << "\n\t\t\t\t\t" << "  * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t\t\t" << setw(11) << "" << setw(28) << "" << endl;
	cout << "\t\t\t\t" << setw(13) << " " << "Student Record Management System" << setw(5) << "" << endl;
	cout << "\t\t\t\t" << setw(11) << setw(28) << "" << endl;
	cout << "\t\t\t\t\t" << "  * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\n\n\t\t\t\t\t\tDVELOPED BY:\n\t\t\t\t\tM. Faizan\n\t\t\t\t\tM. Shahid\n\t\t\t\t\ttUsman";
	cout << "\n\n\t\t\t\t" << "       \t  * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\n\n\t\t\t\t\tPress Enter to Continue..." << endl;
	cin.get();
p:
	system("cls");
	int choice;
	cout << "\n\n\t\t\t*Welcome to Student Record Management System*" << endl;

	cout << "\n\n\t\t\t\t1.Insert Record:";
	cout << "\n\n\t\t\t\t2.Search Record: ";
	cout << "\n\n\t\t\t\t3.Update Record:";
	cout << "\n\n\t\t\t\t4.Delete Recoed:";
	cout << "\n\n\t\t\t\t5.Show Record:";
	cout << "\n\n\t\t\t\t6.Exit:";
	cout << "\n\n\t\t\t\tEnter Your Choice: ";
	cin >> choice;

	switch (choice)

	{
	case 1:
		insert();
		break;
	case 2:
		search();
		break;
	case 3:
		update();
		break;
	case 4:
		del();
		break;
	case 5:
		show();
		break;
	case 6:
		exit(0);
	default:
		cout << "\a\n\n Invalid Choice!";

	}
	getch();   // it is used to get chractor from user and program terminates. 
	goto p;    // We used it because we want to return to main menu after completing our work.
	system("pause");
}
