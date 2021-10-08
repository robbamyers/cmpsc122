/*
Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

Assisted by and Assisted line numbers: None
Robert Myers
rfm5594
CMPSC122
Due Time: 11:59pm EST, Sunday, October 10, 2021
Time of Last Modification: 11:15am EST, Thursday, Oct 7, 2021
Description: In this assignment students will practice adding functions to manipulate stacks and queues in STL C++.
*/
#include <iostream>
#include <queue>
using namespace std;

void print(queue<int> q);
int BeforeLast(queue<int> &q);
int maximum(queue<int> &q);
int main() {
	srand(time(NULL)); // seed rand with system time
	queue<int> q;
	for(int i=0; i < 10; i++){ // loop to populate queue
		q.push(rand() % 100);
	}
	print(q);
	cout << "The value before last is: " << BeforeLast(q) << endl;
	cout<<"The maximum value of the queue is: "<< maximum(q) <<endl;
}
void print(queue<int> q){ // passed by value (copy)
	while(!q.empty()){ // loop to print
		cout << q.front() << endl;
		q.pop(); // remove values while looping
	}
}
int BeforeLast(queue<int> &q){ // queue passed by reference
	queue<int> qCopy;
	qCopy.swap(q); // create copy of queue
	int result;
	while(qCopy.front() != qCopy.back()){ // loop through, stopping at last element
		result = qCopy.front();
		q.push(qCopy.front()); // repopulate q passed by referece
		qCopy.pop();
	}
	return result;
}
int maximum(queue<int> &q){ // queue passed by reference
	queue<int> qCopy;
	qCopy.swap(q); // create copy of queue
	int max = qCopy.front(); // set max to first value
	while(!qCopy.empty()){ // loop through queue
		if(qCopy.front() >= max){ // check if front is larger than max
			max = qCopy.front();
			qCopy.pop();
		}
		else{
			qCopy.pop();
		}
	}
	return max;
}
/* Sample Output:
24
63
67
57
0
41
74
12
42
51
The value before last is: 42
The maximum value of the queue is: 74
*/