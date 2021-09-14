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
using namespace std;
class Date{
	public:
		// Constructors:
		Date();
		Date(int initM, int initD, int initY);
		// Member Functions:
		void setMonth(int m);
		int getMonth();
		void setDay(int d);
		int getDay();
		void setYear(int y);
		int getYear();
		void additionHandler();
		void display(ostream & COUT) const;
		// Overloaded Member Operators:
		bool operator==(const Date & d);
		Date & operator++();
	private:
		int month, day, year;
};
// Overloaded Non-Member Operators
ostream & operator<<(ostream & COUT, const Date & d);
Date operator+ (const Date & d, int x);
Date operator+ (int x, const Date & d);

