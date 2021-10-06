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
