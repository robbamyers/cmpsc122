/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, September 12, 2021
Time of Last Modification: 2:46am EST, Wednesday, September 8, 2021
Description: Practice creating and working with classes in C++
*/
#include <iostream>
#include "Date.h"
using namespace std;

bool DateComp(Date* date1, Date* date2);
int main() {
	int month,day,year;
	Date mydate1; // instantiate mydate1 with default constructor
	Date* mydate1ptr = &mydate1; // create a pointer to this class

	cout << "The initialized date is: ";
	mydate1.printDate(); // prints 0/0/000 from default constructor

	cout << "Please enter a date in this sequence: Month, Day, Year: ";
	cin >> month >> day >> year;
	mydate1.setMonth(month);
	mydate1.setDay(day);
	mydate1.setYear(year);

	cout << "Please enter a second date in this sequence: Month, Day, Year: ";
	cin >> month >> day >> year;
	Date mydate2(month, day, year); // instantiate mydate2 with overloaded constructor
	Date* mydate2ptr = &mydate2; // create a pointer to this class

	cout << "Printing the two days:\n";
	cout << "The date is (M/D/Y): ";
	mydate1.printDate(); // prints first date entered
	cout << "The date is (M/D/Y): ";
	mydate2.printDate(); // prints second date entered
	if(DateComp(mydate1ptr, mydate2ptr)== true){
		cout << "The dates are the same";
	}
	else{
		cout << "The dates are different";
	}
}
/* Sample Output:
The initialized date is: 0/0/0
Please enter a date in this sequence: Month, Day, Year: 13 32 -1992
Invalid month.
Please re-enter the month: 12
Invalid day for this month.
Please re-enter the day: 31
Invalid year (must be greater than 0).
Please re-enter the year: 1992
Please enter a second date in this sequence: Month, Day, Year: 2 30 1995
Invalid day for this month.
Please re-enter the day: 28
Printing the two days:
The date is (M/D/Y): 12/31/1992
The date is (M/D/Y): 2/28/1995
The dates are different
*/
bool DateComp(Date* date1, Date* date2){
	// checks if month, day, and year are the same
	if((date1->getMonth() == date2->getMonth()) && (date1->getDay() == date2->getDay()) && (date1->getYear() == date2->getYear())){
		return true;
	}
	else{
		return false;
	}
}