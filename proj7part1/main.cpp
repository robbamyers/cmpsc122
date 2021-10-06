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
#include "Queue.h"
using namespace std;

int main() {
    srand(time(NULL));
    Queue<int> a;
    for(int i = 0; i < 10; i++){
        a.enqueue(rand() %  1000);
    }
    a.print(a);
    int x = a.BeforeLast(a);
    cout << "The second to last item in queue is: " << x << endl;
    int y = a.maximum(a);
    cout << "The maximum value of the queue is: " << y << endl;
}
/* Sample Output:
731
65
857
531
368
360
628
976
232
379
The second to last item in queue is: 232
The maximum value of the queue is: 976
*/