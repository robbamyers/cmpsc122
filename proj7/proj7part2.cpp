/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 10, 2021
Time of Last Modification: 10:09am EST, Thurs, Oct 7, 2021
Description: In this assignment students will practice adding functions to manipulate stacks and queues in STL C++.
*/
#include <iostream>
#include <stack> // include stack from stdlib
using namespace std;

bool isPrime(int n);
int main() {
	int n; // declare an int n
	stack<int> s; // declare a stack s
	cout << "Please enter an integer n greater than 1:" << endl;
	cin >> n; // prompty and read in n from user
	for(int i = 2; i <= n; i++){ // loop to find prime divisors
		if(isPrime(i) && n % i == 0){ // conditional to check for prime divisor
			while(n % i == 0){ // loop to repeat prime disivor until non longer divisable
				s.push(i);
				n /= i;	
			}
		}
	}
	while(!s.empty()){ // loop through queue until it's empty
		cout << s.top() << " "; // display top of queue
		s.pop(); // remove top of queue
	}
}
bool isPrime(int n){
	if(n <= 1){ // 1 and 0 are not prime
		return false;
	}
	for(int i = 2; i < n; i++){ // check all numbers between 2 and n to see if any divide n evenly, if so not prime
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
/*Sample Output:
Please enter an integer n greater than 1:
850
17 5 5 2
*/