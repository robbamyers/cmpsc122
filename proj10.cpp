/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 31, 2021
Time of Last Modification: 8:20pm EST, Monday, Oct 25, 2021
Description: To get practice in designing recursive function. 
*/
#include <iostream>
#include <vector>
using namespace std;

void Print(ostream& out, int a, int b);
bool isMember(vector<int>& x, int y, int i);
int main() {
	srand(time(NULL));
	int valueToSearch;
	// Part 1
	Print(cout, 2, 5);
	vector<int> test;
	for(int i=0;i<10;i++){
		test.push_back(rand() % 10);
		cout << test[i] << endl;
	}
	// Part 2
	cout << "Please enter an integer you would like to find: ";
	cin >> valueToSearch;
	if(isMember(test, valueToSearch, 0)){
		cout << "Found!";
	}
	else{
		cout << "Not found!";
	}
}
void Print(ostream& out, int a, int b){
	if(a > b){
		return;
	}
	else{
		for(int i=0; i < a;i++){
			out << "- ";
		}
		out << endl;
		Print(out, a+1,b);
		for (int j=0; j < a; j++){
			out << "- ";
		}
		out << endl;
	}
}
bool isMember(vector<int>& x, int y, int i){
	if(x[i] == y){
		return true;
	}
	else if(x[i] == '\0'){
		return false;
	}
	else{
		return isMember(x, y, i+1);
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
7
8
9
5
6
5
8
7
3
8
Please enter an integer you would like to find: 1
Not found!
*/