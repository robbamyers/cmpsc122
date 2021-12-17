/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, Dec 5, 2021
Time of Last Modification: 11:02pm EST, Saturday, Dec 4, 2021
Description: To gain experience on creating derived classes and inheritance.

File: employee.h
Employee class definition.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
public:
	Employee(string theName, float thePayRate);
	string getName() const;
	float getPayRate() const;
	float pay(float hoursWorked) const;
	void setName(string input);
    void setPayRate(float input);
	void setSalaried(bool input); 
protected:
	string name;
	float payRate;
	bool salaried;
};

//Employee method definitions.
Employee::Employee(string theName, float thePayRate)
{
	name = theName;
	payRate = thePayRate;
}

string Employee::getName() const
{
	return name;
}
float Employee::getPayRate() const
{
	return payRate;
}
float Employee::pay(float hoursWorked) const
{
	return hoursWorked * payRate;
}
void Employee::setName(string input)
{
	name = input;
}
void Employee::setPayRate(float input)
{
	payRate = input;
}
void Employee::setSalaried(bool input)
{
	salaried = input;
}

#endif /* not defined _EMPLOYEE_H */

