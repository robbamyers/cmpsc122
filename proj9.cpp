/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 17, 2021
Time of Last Modification: 2:19pm EST, Saturday, Oct 16, 2021
Description: In this lab we take a close look at how we can use the vector in our own programs we will use an iterator to access and retrieve data from it. 
*/
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
bool isPresent(vector<T> data, T value);
template <typename T>
void removerDuplicates (vector<T>& data);
template <typename T>
void Print(const vector<T> &v);
template <typename T>
void removeIf(vector<T>& data, T value);

int main() {
	srand(time(NULL)); // seed rand with system time values
	vector<int> vec;

	for(int i=0; i<10; i++){ // loop to add random values between 1-10 to vector
		vec.push_back(rand() % 10);
	}
	cout << "This is the vector:\n";
	Print(vec);

	int y;
	cout << "Enter a number to check if it's present: ";
	cin >> y;
	if(isPresent(vec, y)){ // harcode 4 to check isPresent
	  cout << "Present!\n";
	}
	else{
		cout << "Not present!\n";
	}

	cout << "Remove duplicates from vector:\n";
	removerDuplicates(vec);
	Print(vec);

	int x;
	cout << "Remove values greater than or eqaul to: ";
	cin >> x;
	removeIf(vec, x);
	Print(vec);
}

template <typename T>
bool isPresent(vector<T> data, T value){
	typename vector<T>::iterator begin = data.begin(), end = data.end();
	while(begin != end){ // loop through each element in vector
		if(*begin == value){ // check if defrenced iterator is present
			return true;
		}
		begin++;
	}
	return false;
}
template <typename T>
void removerDuplicates (vector<T>& data){
	typename vector<T>::iterator begin = data.begin(), end = data.end(), itr3; // create new vector
	sort(begin, end); // sort the passed in vector
	itr3 = unique(begin,end); // assign the position after last unique value to itr3
	data.resize(distance(begin,itr3)); // resize, ending at position after last element (itr3) 
}
template <typename T>
void Print(const vector<T> &v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}
template <typename T>
void removeIf(vector<T>& data, T value){
	typename vector<T>::iterator newEnd;
	newEnd = remove_if(data.begin(), data.end(), bind2nd(greater_equal<T>(),value)); // transforms data into vector that just contains elements greater than value, points to end of this vector
	data.erase(newEnd,data.end()); // erase everything from newEnd position to data.end
}
/* Sample Output:
This is the vector:
1 1 1 3 4 9 7 8 7 9 
Enter a number to check if it's present: 8
Present!
Remove duplicates from vector:
1 3 4 7 8 9 
Remove values greater than or eqaul to: 4
1 3 
*/