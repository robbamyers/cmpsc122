/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 10, 2021
Time of Last Modification: 8:17pm EST, Sunday, Oct 10, 2021
Description: In this assignment students will practice templates in C++. 
*/
#include <iostream>
#include "proj8.h"
using namespace std;
int main() {
	// Int Part
	srand(time(NULL));
	int k;
	myList<int> intList;
	intList.myFill();
	intList.print();
	cout << "Which item would you like to delete?\n";
	cin >> k;
	cout << "Deleting " << k << ". Printing new list...\n";
	intList.myDelete(k);
	intList.print();
	cout << "The beginning is: " << *intList.myBegin() << endl;
	cout << "The end is: " << *intList.myEnd() << endl;
	// Char Part
	char c;
	myList<char> charList;
	charList.myFill();
	charList.print();
	cout << "Which item would you like to delete?\n";
	cin >> c;
	cout << "Deleting " << c << ". Printing new list...\n";
	charList.myDelete(c);
	charList.print();
	cout << "The beginning is: " << *charList.myBegin() << endl;
	cout << "The end is: " << *charList.myEnd() << endl;
}
/* Sample Output:
120
109
119
114
117
119
97
108
111
101
Which item would you like to delete?
119
Deleting 119. Printing new list...
120
109
114
117
97
108
111
101
The beginning is: 120
The end is: 101
v
j
o
a
e
l
f
g
a
c
Which item would you like to delete?
a
Deleting a. Printing new list...
v
j
o
e
l
f
g
c
The beginning is: v
The end is: c
*/