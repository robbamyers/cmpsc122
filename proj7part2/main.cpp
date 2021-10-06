/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 10, 2021
Time of Last Modification: 8:36am EST, Tuesday, Oct 5, 2021
Description: In this assignment students will practice adding functions to manipulate stacks and queues in STL C++.
*/
#include <iostream>
#include "Stack.h"
using namespace std;

bool isPrime(int);
int main() {
	int n;
	Stack s;
	cout << "Please enter an integer\n";
	cin >> n;
	for(int i = 2; i <= n; i++){
		if(isPrime(i) && n % i == 0){
			while(n % i == 0){
				s.push(i);
				n /= i;	
			}
		}
	}
	s.display(cout);
}
bool isPrime(int n){
	if(n <= 1){
		return false;
	}
	for(int i = 2; i < n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
/* Sample Output:
Please enter an integer
850
[17] [5] [5] [2]
*/