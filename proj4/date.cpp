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
#include "Date.h"
#include <iostream>
using namespace std;

// Default Constructor
Date::Date(): month(0), day(0), year(0) {};
// Overloaded Constructor
Date::Date(int initM, int initD, int initY){
	setMonth(initM);
	setDay(initD);
	setYear(initY);
}
// Function Members
void Date::setMonth(int m){
	if(m>=1 && m<=12){
		month = m;
	}
	else{
		cerr << "Invalid month.\nPlease re-enter the month: ";
		cin >> m;
		setMonth(m); // recursive method call to validate input
	}
}
int Date::getMonth(){
	return month;
}
void Date::setDay(int d){
	// validation for months with 31 days
	if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d >= 1 && d <= 31){
		day = d;
	}
	// validation for months with 30 days
	else if((month == 4 || month == 6 || month == 9 || month == 11) && d >= 1 && d <= 30){
		day = d;
	}
	// validation for february (does not consider leap year)
	else if((month == 2) && d >= 1 && d <=28){
		day = d;
	}
	else{
		cerr << "Invalid day for this month.\nPlease re-enter the day: ";
		cin >> d;
		setDay(d); // recursive method call to validate input
	}
}
int Date::getDay(){
	return day;
}
void Date::setYear(int y){
	// ensures year >= 0 (does not consider negatives/BC values)
	if(y >= 0){
		year = y;
	}
	else{
		cerr << "Invalid year (must be greater than 0).\nPlease re-enter the year: ";
		cin >> y;
		setYear(y); // recursive method call to validate input
	}
}
int Date::getYear(){
	return year;
}
void Date::additionHandler(){
	if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 32){
			if(month == 12){
				month = 1;
				day = 1;
			}
			else{
				month++;
				day = 1;
			}
			
		}
		else if((month == 4 || month == 6 || month == 9 || month == 11) && day == 30){
			if(month == 12){
				month = 1;
				day = 1;
			}
			else{
				month++;
				day = 1;
			}
		}
		else if((month == 2) && day == 29){
			if(month == 12){
				month = 1;
				day = 1;
			}
			else{
				month++;
				day = 1;
			}
		}
}
void Date::display(ostream & COUT) const{
	COUT << month << "/" << day << "/" << year;
}
// Overloaded Operators
bool Date::operator==(const Date & d){
	if((day == d.day) && (month == d.month) && (year == d.year)){
		return true;
	}
	else{
		return false;
	}
}
Date & Date::operator++(){
	day++;
	additionHandler();
	return *this;
}
ostream & operator<<(ostream & COUT, const Date & d){
	d.display(COUT);
	return COUT;
}
Date operator+(const Date & d, int x){
	Date tempDate = x + d;
	return tempDate;
}
Date operator+(int x, const Date & d){
	Date tempDate = d;
	for(int i = 0; i < x; i++){
		++tempDate;
	}
	return tempDate;
}
