/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, September 5, 2021
Time of Last Modification: 11:59am EST, Sunday, September 5, 2021
Description: In this exercise you will expand on a program by using the reference and dereference operators to pass a structure instance by reference to a function and manipulate it. You will also create a dynamic array for associated data.
*/
#include <iostream>
using namespace std;

struct Student{
    string name;
    int ID;
    double * grade; //Part 2: Updated to pointer
};
// Part 1:
void inputStudent(Student &s,const int &gradeCount); // Part 2: Added gradeCount as param
void gradeValidation(Student &s, int i);
void printStudentInfo(Student &s,const int &gradeCount); // Part 2: Added gradeCount as param

int main() {
	// Part 1:
	// Student stud; Commenting out for Part3
	// Part 2: Added prompt to read in number of grades
	int gradeCount;
	cout << "How many grades are there? ";
	cin >> gradeCount;
	// Part 3: Added prompt to read in number of students
	int n;
	cout << "How many students are there? ";
	cin >> n;
	Student *studArr = new Student[n];
	for(int i=0; i < n; i++){
		inputStudent(studArr[i], gradeCount);
		printStudentInfo(studArr[i], gradeCount);
	}
}
/* Sample Execution:
How many grades are there? 3
How many students are there? 4
Please enter a name: Robbie
Please enter an Id: 87342
Please enter grade 1: 98
Please enter grade 2: 96
Please enter grade 3: 72
Student Info:
Name: Robbie
ID: 87342
Grade 1: 98
Grade 2: 96
Grade 3: 72
Please enter a name: Jessica
Please enter an Id: 87
Please enter grade 1: 98
Please enter grade 2: 99
Please enter grade 3: 101
Please enter a grade between 0-100
Please re-enter grade 3: 100
Student Info:
Name: Jessica
ID: 87
Grade 1: 98
Grade 2: 99
Grade 3: 100
Please enter a name: Matt
Please enter an Id: 87345
Please enter grade 1: 92
Please enter grade 2: 94
Please enter grade 3: 12
Student Info:
Name: Matt
ID: 87345
Grade 1: 92
Grade 2: 94
Grade 3: 12
Please enter a name: Tim
Please enter an Id: 98345
Please enter grade 1: -1
Please enter a grade between 0-100
Please re-enter grade 1: 0
Please enter grade 2: 99
Please enter grade 3: 87 
Student Info:
Name: Tim
ID: 98345
Grade 1: 0
Grade 2: 99
Grade 3: 87
*/

// Part 1:
void inputStudent(Student &s, const int &gradeCount){
	cout << "Please enter a name: ";
	cin >> s.name;
	cout << "Please enter an Id: ";
	cin >> s.ID;
	// Part 2: Dynamic array for grades
	s.grade = new double[gradeCount]; 
	for(int i = 0; i < gradeCount; i++){
		cout << "Please enter grade " << (i+1) << ": ";
		cin >> s.grade[i];
		gradeValidation(s,i);
	}
}
// function to validate grades each time they are entered
void gradeValidation(Student &s, int i){
	while(s.grade[i]< 0.0 || s.grade[i] > 100.0){
		cout << "Please enter a grade between 0-100\n";
		cout << "Please re-enter grade " << (i+1) << ": ";
		cin >> (s.grade[i]);
	}
}
void printStudentInfo(Student &s, const int &gradeCount){
	cout << "Student Info:\n";
	cout << "Name: " << s.name << endl;
	cout << "ID: " << s.ID << endl;
	for(int i=0; i<gradeCount; i++){
		cout << "Grade " << (i+1) << ": " << s.grade[i] << endl;
	}
	// after student info is printed, delete from dynamic memory
	delete [] s.grade;
}