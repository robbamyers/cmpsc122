/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, August 29, 2021
Time of Last Modification: 11:43pm EST, Monday, August 23, 2021
Description: Takes a binary string as input and flips digits to create an alternating binary sequence of the same length with minimal flips.
*/

#include <iostream>
#include <vector>
using namespace std;

void getUserInput(string& userInput);
void flipCharacters(vector<char>& binarySequence, const string& userInput, int& flips);
void flipAllChars(vector<char>& binarySequence, const string& userInput, int& flips);
void displayOutput(const string& userInput, const int& flips, const vector<char>& binarySequence);

int main() {
	string userInput;
    vector<char> binarySequence;
	int flips = 0;
	
    getUserInput(userInput);
	flipCharacters(binarySequence, userInput, flips);
	if(flips == 0){
		flipAllChars(binarySequence, userInput, flips);
	}
	displayOutput(userInput, flips, binarySequence);
return 0;
}
/*
Standard Output:
Enter a string:
0001111000
The original string is 0001111000, the minimum number of flips needed is:
5
The flipped string is:
0101010101
*/


// prompt user and read in string
void getUserInput(string& userInput){
	cout << "Enter a string:\n";
    cin >> userInput;
}
// builds vector and makes flips as necessary while doing so
void flipCharacters(vector<char>& binarySequence, const string& userInput, int& flips){
	// loop through string input
	for(int i=0;i<userInput.length();i++){
		// add current char to the binarySequence vector
    	binarySequence.push_back(userInput[i]);
		// starting on the second iteration, compare the previous character to the current to see if a flip is to be made
		if(i > 0 && binarySequence[i-1] == binarySequence[i]){
			if(binarySequence[i] == '0'){
				binarySequence[i] = '1';
				// increment counter by 1;
				flips++;
			}
			else{
				binarySequence[i] = '0';
				flips++;
			}
		}
    }
}
// flips every character and counts flips
void flipAllChars(vector<char>& binarySequence, const string& userInput, int& flips){
	for(int i=0;i < binarySequence.size();i++){
		if(binarySequence[i] == '0'){
			binarySequence[i] = '1';
			flips++;
		}
		else{
			binarySequence[i] = '0';
			flips++;
		}
	}
}
// reconstructs a string from vector and displays original 
// userInput, flip count and flipped string
void displayOutput(const string& userInput, const int& flips, const vector<char>& binarySequence){
	string flippedString;
	for(int i=0;i<binarySequence.size();i++){
		flippedString+=binarySequence[i];
	}
	cout << "The original string is " << userInput << ", the minimum number of flips needed is:\n" << flips << endl;
	cout << "The flipped string is:\n" << flippedString << endl;
}



