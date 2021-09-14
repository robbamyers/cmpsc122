/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, September 19, 2021
Time of Last Modification: 8:39pm EST, Monday, September 13, 2021
Description: identifying and working with overloaded functions/writing and testing some overloaded operators
*/
#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	// variable declarations
	int month,day,year;
	Date date1;
	cout << "The initialized date is: " << date1 << endl; // display date from constructor

	cout << "Please enter a date in this sequence: Month, Day, Year: ";
	cin >> month >> day >> year;
	date1.setMonth(month);
	date1.setDay(day);
	date1.setYear(year);

	cout << "Please enter a second date in this sequence: Month, Day, Year: ";
	cin >> month >> day >> year;
	Date date2(month, day, year); // create date2 object with overloaded constructor
	
	cout << "Printing the two days:\n";
	cout << "The date is (M/D/Y): " << date1 << endl;
	cout << "The date is (M/D/Y): " << date2 << endl;
	
	if(date1 == date2){ // using overloaded operator "=="
		cout << "The dates are the same" << endl;
	}
	else{
		cout << "The dates are different" << endl;
	}
	cout << "After incrementing" << endl;
	++date1; // using overloaded prefix incrementor operator "++"
	++date2;
	cout << "Date is: " << date1 << endl;
	cout << "Date is: " << date2 << endl;
	cout << "After addition" << endl;
	cout << "Date is: " << date1 << endl;
	cout << "Date is: " << date2 << endl;
	Date date3, date4;
	date3 = date1 + 82; // using overloaded operator "+"
	date4 = 6 + date2; // using overloaded operator "+"
	cout << "Date is: " << date3 << endl;
	cout << "Date is: " << date4 << endl;
}
/* Sample Execution:
The initialized date is: 0/0/0
Please enter a date in this sequence: Month, Day, Year: 1 1 1
Please enter a second date in this sequence: Month, Day, Year: 2 2 2
Printing the two days:
The date is (M/D/Y): 1/1/1
The date is (M/D/Y): 2/2/2
The dates are different
After incrementing
Date is: 1/2/1
Date is: 2/3/2
After addition
Date is: 1/2/1
Date is: 2/3/2
Date is: 3/25/1
Date is: 2/9/2
*/
