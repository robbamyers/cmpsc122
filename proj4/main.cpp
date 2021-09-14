#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	int month,day,year;
	Date mydate1;
	Date* mydate1ptr = &mydate1;

	cout << "The initialized date is: " << mydate1 << endl;

	cout << "Please enter a date in this sequence: Month, Day, Year: ";
	cin >> month >> day >> year;
	mydate1.setMonth(month);
	mydate1.setDay(day);
	mydate1.setYear(year);

	cout << "Please enter a second date in this sequence: Month, Day, Year: ";
	cin >> month >> day >> year;
	Date mydate2(month, day, year);
	Date* mydate2ptr = &mydate2;
	
	cout << "Printing the two days:\n";
	cout << "The date is (M/D/Y): " << mydate1 << endl;
	cout << "The date is (M/D/Y): " << mydate2 << endl;
	
	if(*mydate1ptr == *mydate2ptr){
		cout << "The dates are the same" << endl;
	}
	else{
		cout << "The dates are different" << endl;
	}
	cout << "After incrementing" << endl;
	++mydate1;
	++mydate2;
	cout << "Date is: " << mydate1 << endl;
	cout << "Date is: " << mydate2 << endl;

	Date date3, date4;
    date3 = mydate1 + 82;
    date4 = 6 + mydate2;
	cout << "After addition" << endl;
	cout << "Date is: " << date3 << endl;
	cout << "Date is: " << date4 << endl;
}
