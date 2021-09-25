/*-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
#ifndef DyLIST
#define DyLIST

typedef int ElementType;
class DyList
{
public:
	bool compare(const DyList&);
	void copyResize( DyList&);
	void deleteElm(ElementType);
	void reverse();

	/******** Function Members ********/
	/***** Class constructor *****/
	DyList(int maxSize = 1024);
	/*----------------------------------------------------------------------
	Construct a List object.

	Precondition:  maxSize is a positive integer with default value 1024.
	Postcondition: An empty List object is constructed; ListCapacity ==
	maxSize (default value 1024); ArrayPtr points to a run-time
	array with ListCapacity as its capacity; and ListSize is 0.
	-----------------------------------------------------------------------*/


	/***** Class destructor *****/
	~DyList();
	/*----------------------------------------------------------------------
	Destroys a List object.

	Precondition:  The life of a List object is over.
	Postcondition: The memory dynamically allocated by the constructor
	for the array pointed to by ArrayPtr has been returned to
	the heap.
	------------------------------------------------------------------*/

	/***** Copy constructor *****/
	DyList(const DyList & oldList);
	/*----------------------------------------------------------------------
	Construct a copy of a List object.

	Precondition:  A copy of oldList is needed; oldList is a const
	reference parameter.
	Postcondition: A copy of oldList has been constructed.
	-----------------------------------------------------------------------*/

	/***** Assignment operator *****/
	DyList & operator=(const DyList & oldList);
	/*----------------------------------------------------------------------
	Assign a copy of a List object to the current object.

	Precondition: none
	Postcondition: A copy of oldList has been assigned to this
	object.  A reference to this list is returned.
	-----------------------------------------------------------------------*/

	/***** empty operation *****/
	bool empty() const;
	/*----------------------------------------------------------------------
	Check if a list is empty.

	Precondition:  None
	Postcondition: true is returned if the list is empty,
	false if not.
	-----------------------------------------------------------------------*/

	/***** insert and erase *****/
	void insert(ElementType item, int pos);
	/*----------------------------------------------------------------------
	Insert a value into the list at a given position.

	Precondition:  item is the value to be inserted; there is room in
	the array (ListSize < CAPACITY); Make sure that pos is not negative 
        And it is less than ListSize.

	Postcondition: item has been inserted into the list at the position
	determined by pos (provided there is room and pos is a legal
	position).
	-----------------------------------------------------------------------*/

	void erase(int pos);
	/*----------------------------------------------------------------------
	Remove a value from the list at a given position.

	Precondition:  The list is not empty and Make sure that pos is not negative 
        And it is less than ListSize.
	Postcondition: element at the position determined by pos has been
	removed (provided pos is a legal position).
	----------------------------------------------------------------------*/

	/***** output *****/
	void print(ostream & out) const;
	/*----------------------------------------------------------------------
	Print a list.

	Precondition:  The ostream out is open.
	Postcondition: The list represented by this DyList object has been
	inserted into out.
	-----------------------------------------------------------------------*/
	int getSize() { return ListSize; }
private:
	/******** Data Members ********/
	int ListSize;                // current size of list stored in array
	int ListCapacity;            // capacity of array
	ElementType *ArrayPtr;  // pointer to dynamically-allocated array

}; //--- end of List class

   //------ Prototype of output operator
ostream & operator<< (ostream & out, const DyList & vList);

#endif 