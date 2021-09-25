/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, September 26, 2021
Time of Last Modification: 7:33pm EST, Saturday, September 25, 2021
Description: In this assignment students will practice using dynamic arrays to create functions in List class. 
*/

#include <cassert>
#include <iostream>
#include "DyList.h"

using namespace std;
bool DyList::compare(const DyList& d){
	// loop through this and check if each element in this array is equal to corresponding elements in d array
	for(int i = 0; i < ListSize; i++){
		if(ArrayPtr[i] != d.ArrayPtr[i]){
			return false;
		}
	}
	return true;
}
void DyList::copyResize(DyList& d){
	// set this list size and capacity equal to d list size and capacity
	ListSize = d.ListSize;
	ListCapacity = d.ListCapacity;
	// delete allocated array in this
	delete [] ArrayPtr;
	// allocate new memory for array
	ArrayPtr = new(nothrow) ElementType[ListCapacity];
	// copy array to new resized space in memory
	for(int i = 0; i < ListSize; i++){
		ArrayPtr[i] = d.ArrayPtr[i];
	}
}
void DyList::deleteElm(ElementType j){
	// loop through list and delete elements that match argument
	for(int i = 0; i < ListSize; i++){
		if(ArrayPtr[i] == j){
			erase(i);
		}
	}
}
void DyList::reverse(){
	// create a temporary array of equal capacity
	ElementType temp[ListCapacity];
	// counter
	ElementType j = ListSize - 1;
	// copy elements to temporary
	for(int i = 0; i < ListSize; i++){
		temp[i] = ArrayPtr[i];
	}
	// reverse the order of elements
	for(int i = 0; i < ListSize; i++){
		ArrayPtr[i] = temp[j];
		j--;
	}
}
// constructor
DyList::DyList(int maxSize):ListSize(0),ListCapacity(maxSize){
	// check if size is positive integer
	if (maxSize > 0){
		ArrayPtr = new(nothrow) ElementType[maxSize];
		assert(ArrayPtr != 0);
	}
	else{
		cerr << "ListCapacity must be a positive number" << endl;
		exit(1);
	}
}
// destructor
DyList::~DyList(){
	delete [] ArrayPtr;
}
// copy constructor
DyList::DyList(const DyList & oldList)
: ListSize(oldList.ListSize), ListCapacity(oldList.ListCapacity){
	// allocate memory for new array
	ArrayPtr = new(nothrow) ElementType[ListCapacity];
	// check that memory is available
	if(ArrayPtr != 0){
		// add elements from oldList to existing list
		for(int i = 0; i < ListSize; i++){
			ArrayPtr[i] = oldList.ArrayPtr[i];
		}
	}
	else{
		cerr << "No memory available!" << endl;
		exit(1);
	}
}
// assignmet operator
DyList & DyList::operator=(const DyList & oldList){
	// check if lists are different
	if(this != &oldList){
		// check that capacities are not equal
		if(ListCapacity != oldList.ListCapacity){
			// delete the original array
			delete [] ArrayPtr;
			// set listCapacity to the oldList capacity
			ListCapacity = oldList.ListCapacity;
			// allocate memory for a new array
			ArrayPtr = new(nothrow) ElementType[ListCapacity];
			// if memory not available
			if(ArrayPtr == 0){
				cerr << "No memory available!" << endl;
				exit(1);
			}
		}
		// if capacities are equal just change list size and add elements		
		ListSize = oldList.ListSize;
		for(int i = 0; i < ListSize; i++){
			ArrayPtr[i] = oldList.ArrayPtr[i];
		}
	}
	// return object
	return *this;
}
// check if ListSize is empty
bool DyList::empty() const{
	return ListSize == 0;
}
// insert an element at a certain position
void DyList::insert(ElementType item, int pos){
	if(ListSize == ListCapacity){
		cerr << "No space available" << endl;
		exit(1);
	}
	if(pos < 0 || pos > ListSize){
		cerr << "Location not available" << endl;
		return;
	}
	// shift loop
	for(int i = ListSize; i > pos; i--){
		ArrayPtr[i] = ArrayPtr[i - 1];
	}
	ArrayPtr[pos] = item; // assign element to pos
	ListSize++; // decrement size by 1
}
// erase item from list
void DyList::erase(int pos){
	if(ListSize == 0){
		cerr << "List is empty!" << endl;
		return;
	}
	if(pos < 0 || pos >= ListSize){
		cerr << "Out of range" << endl;
		return;
	}
	// shift loop
	for(int i = pos; i < ListSize; i++){
		ArrayPtr[i] = ArrayPtr[i + 1];
	}
	ListSize--; // decrement size by 1
}
void DyList::print(ostream & out) const{
	out << "[";
	for(int i = 0; i < ListSize; i++){
		out << ArrayPtr[i];
		if (i != ListSize - 1){
			out << ",";
		}
	}
	out << "]";
}
ostream & operator<< (ostream & out, const DyList & vList){
	vList.print(out);
	return out;
}
/* Sample Output:
List inlist is: [11,13,15,17,19,21,20,18,16,14,12,10]

List empty? No

copy constructor to create list myList:  myList is: [11,13,15,17,19,21,20,18,16,14,12,10]


myList after inserting one new element is:[11,13,332,15,17,19,21,20,18,16,14,12,10]

New list llist is created as: [0,3,6,9,12,15,18]

Lists intList and llist  are not equal

Copy intList to llist: 
llist now is: [11,13,15,17,19,21,20,18,16,14,12,10]

Deleting 10 from llist
llist after deleting 10 is now: [11,13,15,17,19,21,20,18,16,14,12]

The reversed list intlist is:
[10,12,14,16,18,20,21,19,17,15,13,11]
*/
