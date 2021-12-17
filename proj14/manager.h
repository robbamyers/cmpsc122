/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, Dec 5, 2021
Time of Last Modification: 11:02pm EST, Saturday, Dec 4, 2021
Description: To gain experience on creating derived classes and inheritance. 

File: manager.h
Manager class definition.
*/
#ifndef _MANAGER_H
#define _MANAGER_H

#include "employee.h"

class Manager : public Employee {
public:
	Manager(string theName,
        float thePayRate,
        bool isSalaried);
	bool getSalaried() const;
	float pay(float hoursWorked) const;
};

//Manager method definitions.
Manager::Manager(string theName,
                 float thePayRate,
                 bool isSalaried)
  : Employee(theName, thePayRate)
{
  salaried = isSalaried;
}
bool Manager::getSalaried() const
{
	return salaried;
}
float Manager::pay(float hoursWorked) const
{
  if (salaried)
    return payRate;
  // else 
  return Employee::pay(hoursWorked);
}

#endif // not defined _MANAGER_H 

