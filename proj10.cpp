/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 31, 2021
Time of Last Modification: 4:32pm EST, Saturday, Oct 30, 2021
Description: To get practice in designing recursive function. 
*/
#include <iostream>
#include <array>
using namespace std;
const int SIZE = 10;
void Print(ostream& out, int a, int b);
bool isMember(const array<int, SIZE>& x, int y, int i);
int main() {
	srand(time(NULL));
	int valueToSearch;
	// Part 1
	Print(cout, 2, 5); 
	// Part 2
	array<int, SIZE> test; // create array
	for(int i=0;i<SIZE;i++){ // populate array w/ random values 0-9
		test[i] = rand() % 10;
		cout << test[i] << " ";
	}
	cout << endl;
	cout << "Please enter an integer you would like to find: ";
	cin >> valueToSearch;
	if(isMember(test, valueToSearch, 0)){ // call to recursive function
		cout << "Found!";
	}
	else{
		cout << "Not found!";
	}
}
void Print(ostream& out, int a, int b){
	if(a > b){ 
		return; // base case
	}
	else{
		for(int i=0; i < a;i++){ // print "-" int a number of times
			out << "- ";
		}
		out << endl;
		Print(out, a+1,b); // recursive call
		for (int j=0; j < a; j++){ // continue after recursive call
			out << "- ";
		}
		out << endl;
	}
}
bool isMember(const array<int, SIZE>& x, int y, int i){
	if(x[i] == y){ 
		return true; // primary case to end recursion
	}
	else if(i == x.size() - 1){
		return false; // secondary case to end recursion
	}
	else{
		return isMember(x, y, i+1); // recursive call
	}
}
/* Sample Output:
- - 
- - - 
- - - - 
- - - - - 
- - - - - 
- - - - 
- - - 
- - 
4 8 0 4 5 3 2 8 8 1 
Please enter an integer you would like to find: 9
Not found!
*/
