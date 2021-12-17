/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, Dec 5, 2021
Time of Last Modification: 11:02pm EST, Saturday, Dec 4, 2021
Description: To gain experience on creating derived classes and inheritance. 

File: Empltest.cpp
This program illustrates the creation and use of employee objects.
*/

#include <iostream>
#include "employee.h"
#include "manager.h"
#include "Supervisor.h"
using namespace std;


int main()
{
  Employee empl("John", 25.0);
  Manager mgr("Matthew", 1200.0, true);
  Supervisor sup("Denise", 780.0, "Accounting");
// Assume all employees worked 40 hours this period.

  cout << "For Employee:" << endl;
  cout << "Name: " << empl.getName() << endl;
  cout << "Pay: " << empl.pay(40.0) << endl;
  cout << "Changing the Employee's name..." << endl;
  empl.setName("Doug");
  cout << "New Name: " << empl.getName() << endl;


  cout << endl;
  cout << "For Manager:" << endl;
  cout << "Name: " << mgr.getName() << endl;
  cout << "Salaried: " << mgr.getSalaried() << endl;
  cout << "Pay: " << mgr.pay(40.0) << endl;
  cout << "Changing the Manager's salaried status..." << endl;
  mgr.setSalaried(false);
  cout << "New Pay: " << mgr.pay(40.0) << endl;

  cout << endl;   
  cout << "For Supervisor:" << endl;
  cout << "Name: " << sup.getName() << endl;
  cout << "Pay: " << sup.pay(40.0) << endl;
  cout << "Dept: " << sup.getDept() << endl;
  cout << "Changing the Supervisor's pay rate..." << endl;
  sup.setPayRate(900.0);
  cout << "New Pay: " << sup.pay(40.0) << endl;

  return 0;
}



