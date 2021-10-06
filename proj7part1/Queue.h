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
using namespace std;

template <typename QueueElement>
class Queue
{
    public:
        Queue();
        void print(Queue<QueueElement> q);
        void enqueue(const QueueElement &q);
        QueueElement BeforeLast(Queue<QueueElement> &q);
        QueueElement maximum(Queue<QueueElement> &q);
    private:
        class Node
        {
        public:
            QueueElement data;
            Node* next;
            Node(QueueElement value, Node* link = NULL): data(value), next(link){}
        };
        Node* front;
        Node* back;
};

template <typename QueueElement>
Queue<QueueElement>::Queue() : front(NULL), back(NULL){}

template <typename QueueElement>
void Queue<QueueElement>::print(Queue<QueueElement> q){
    for(Node* i = q.front; i != NULL; i = i->next){
        cout << i->data << endl;
    }
}
template <typename QueueElement>
void Queue<QueueElement>::enqueue(const QueueElement &q){
    Node* n = new Node(q);
    if(this->front == NULL && this->back == NULL){
        this->front = this->back = n;
    }
    else{
        back->next = n;
        back = n;
    }
}
template <typename QueueElement>
QueueElement Queue<QueueElement>::BeforeLast(Queue<QueueElement> &q){
    Node* ptr = q.front;
    Node* last = q.front;
    while(ptr != q.back){
        last = ptr;
        ptr = ptr->next;
    }
    return last->data;
}
template <typename QueueElement>
QueueElement Queue<QueueElement>::maximum(Queue<QueueElement> &q){
    QueueElement max = q.front->data;
    Node* ptr = q.front;
    while(ptr != NULL){
        if(ptr->data > max){
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}






#ifndef PROJ7PART1_QUEUE_H
#define PROJ7PART1_QUEUE_H

#endif //PROJ7PART1_QUEUE_H
