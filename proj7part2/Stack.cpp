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

Stack::Stack():myTop(0){}
Stack::~Stack(){
	Stack::Node* current = myTop;
	Stack::Node* next;
	while(current != 0){
		next = current->next;
		delete current;
		current = next;
	}
}

bool Stack::empty() const{
	if(myTop == 0){
		return true;
	}
	else{
		return false;
	}
}
void Stack::push(int n){
	myTop = new Stack::Node(n, myTop);
}
int Stack::top() const{
	if(!empty()){
		return myTop->data;
	}
	else{
		cout << "Stack is empty";
	}
}
void Stack::pop(){
	if(!empty()){
		Node* ptr = myTop;
		myTop = myTop->next;
		delete ptr;
	}
	else{
		cout << "stack is empty";
	}
}
void Stack::display(ostream & out) const{
	Node* ptr;
	for(ptr = myTop; ptr != 0; ptr = ptr->next){
		out << "[" << ptr->data << "] ";
	}
}
