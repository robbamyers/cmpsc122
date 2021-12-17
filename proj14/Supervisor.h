/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, Dec 5, 2021
Time of Last Modification: 11:02pm EST, Saturday, Dec 4, 2021
Description: To gain experience on creating derived classes and inheritance. 

File: Supervisor.h
Supervisor class definition.
*/
#ifndef _SUPERVISOR_H
#define _SUPERVISOR_H

#include "manager.h"

class Supervisor : public Manager {
public:
	Supervisor(string theName, float thePayRate, string theDepartment);
	string getDept() const;
	void setDept(string input);
private: // declaring department private (nothing to inherit)
	string department;
};

// Supervisor method definitions
Supervisor::Supervisor(string theName, float thePayRate, string theDepartment): Manager(theName, thePayRate, true)
{
	department = theDepartment;
}
string Supervisor::getDept() const
{
	return department;
}
void Supervisor::setDept(string input){
	department = input;
}

#endif

/* What class should Supervisor inherit from?
   The manager class makes the most sense because the manager class takes into consideration whether or not the position is salaried or not when calling the pay function. 
*/