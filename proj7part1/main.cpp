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