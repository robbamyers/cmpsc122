/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, Nov 10, 2021
Time of Last Modification: 11:02pm EST, Thursday, Nov 11, 2021
Description: To gain experience with the operations involving binary search trees. This data structure as linked list uses dynamic memory allocation to grow as the size of the data set grows. 
*/

#include <iostream>
using namespace std;

struct BST // defined globally for function definitions
{
        int data;
        BST * left;
        BST * right;
};
void bst_to_array (BST *& b,int array[],int *n);
void insert(BST *& a, int b);

int main() {
	srand(time(NULL)); // seed with random
	struct BST *root = NULL; // create a new NULL root
	int arr[10];
	for(int i=0; i < 10; i++){ // populate BST with random numbers
		arr[i] = rand() % 1000;
		cout << arr[i] << endl;
		insert(root, arr[i]);
	}
	int *newArr = new int[10]; // allocate space for array of size 10
	int *ptr = new int; // create a new int ptr
	bst_to_array(root, newArr, ptr); 
	cout << endl << "Sorted Array:" << endl;
	for(int i=0;i<10;i++){
		cout << newArr[i] << " ";
	}
} 

void bst_to_array (BST *& b,int array[],int *n){
	if(b == NULL){ // base case;
		return;
	}
	bst_to_array(b->left, array, n); // recursive left call
	array[*n] = b->data; // assign data to array
	(*n)++; // increment to next position
	bst_to_array(b->right, array, n); // recursive right call
}

void insert(BST *& a, int b){
	if (a == NULL){ // base case
		a = new BST; // allocate space for a new BST
		a->left = a->right = NULL; // set left and right to NULL
		a->data = b; // add the data
		return; 
	}
	if(b < a->data){
		insert(a->left, b); // recursive call to build the left BST
	}
	if(b > a->data){
		insert(a->right, b); // recursive call to build the right BST
	}
}
/* Sample Output:
81
972
160
934
818
562
86
843
577
109

Sorted Array:
81 86 109 160 562 577 818 843 934 972
*/