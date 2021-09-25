/* listtester.cpp is a program for testing class List. */

#include <iostream>
using namespace std;

#include "DyList.h"

int main()
{
	// Test the class constructor

	DyList intList;
	DyList llist;
	DyList nlist;
//testing insert by creating intList
	for (int i = 0; i < 12; i++)
	{
		intList.insert(i+10, i / 2);       //  -- Insert i at position i/2
	}								//Test output
	cout << "List inlist is: " << intList << endl;
	//}
  cout<<endl;
  //test empty()
	cout << "List empty? " << (intList.empty() ? "Yes" : "No") << endl;
  cout<<endl;

	// Test the copy constructor
	DyList myList = intList;
	////Test output
	cout << "copy constructor to create list myList: ";

	cout << " myList is: " << myList  << endl;
  cout<<endl;
	//
  cout<<endl;
	myList.insert(332, 2);

	cout << "myList after inserting one new element is:" << myList << endl;

	cout<<endl;
  
	//testing operator =
	for (int i = 0; i < 7; i++)
	{
		llist.insert(i*3,  i);       //  -- Insert i at position i/2
	}								//Test output
	cout << "New list llist is created as: "<<llist << endl;
	
	cout << endl;

	if (llist.compare(intList)) cout << "Lists intList and llist are equal" << endl;
	else cout << "Lists intList and llist  are not equal" << endl;
	//

  cout<<endl;
	cout << "Copy intList to llist: " << endl;
	llist.copyResize(intList); //bigger than original one (from intList to llist).
	cout << "llist now is: "<<llist << endl;
	cout << endl;




	cout << "Deleting 10 from llist" << endl;
	llist.deleteElm(10);
cout << "llist after deleting 10 is now: " << llist << endl;
	
  cout<<endl;
	intList.reverse();
	cout << "The reversed list intlist is:" << endl;
	cout << intList << endl;
}