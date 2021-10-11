/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 10, 2021
Time of Last Modification: 8:17pm EST, Sunday, Oct 10, 2021
Description: In this assignment students will practice templates in C++. 
*/
#include <iostream>
using namespace std;

template <typename T1>
class myList{
public:
	myList():size(0),CAP(10),p(0),A(new T1[CAP]){} // default constructor
	void myFill();
	void print();
	void myDelete(T1 k);
	T1* myBegin();
	T1* myEnd();
private:
	T1 size;
	T1 CAP;
	T1* p;
	T1* A;
};

// class member function defintions
template <typename T1>
void myList<T1>::myFill(){
	for(int i=0; i < CAP; i++){
		A[i] = rand() % 26 + 97; // add a random number between 97 and 122 (ASCII lower case alphabet)
		size++;
	}
}
template <typename T1>
void myList<T1>::print(){
	for(int i=0; i < size; i++){
		cout << A[i] << endl;
	}
}
template <typename T1>
void myList<T1>::myDelete(T1 k){
	for(int i=0; i < size; i++){ // loop through each element in the list
		if(A[i] == k){ // check if the element to delete is in list on each iteration
			for(int j=i; j < size; j++){ // if element is in list, set that element equal to the next value until end of list
				A[j] = A[j + 1];
			}
			size--; // reduce size by 1
		}
	}
}
template <typename T1>
T1* myList<T1>::myBegin(){
	T1* ptr = A; // pointer to first element in list
	return ptr;
}
template <typename T1>
T1* myList<T1>::myEnd(){
	T1* ptr = &A[size - 1]; // pointer to last element in list
	return ptr;
}