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
		bool operator==(const Date & d);
		Date & operator++();
		void display(ostream & COUT) const;
		
	private:
		int month, day, year;
};
ostream & operator<<(ostream & COUT, const Date & d);
Date operator+ (const Date & d, int x);
Date operator+ (int x, const Date & d);

