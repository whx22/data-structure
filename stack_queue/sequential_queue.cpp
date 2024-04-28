/*
 * Queue : 
 * Characteristics ：First In, First Out(FIFO)
 * Allow Insertion : Rear
 * Allow Deletion : Front
 * 
 * Sequential Queue
 */

#include <iostream>
#include <exception>
using namespace std;

#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int front;  // 指针队头元素的前一位
    int rear;   // 指向队尾元素
} Queue;

// Initialize Queue
void initQueue(Queue& queue) {
    queue.front = 0;
    queue.rear = 0;
}

// Enter Queue
void enterQueue(Queue& queue, const int& element) {
    if (queue.front == (queue.rear + 1) % MAXSIZE) {
        throw out_of_range("error : the queue is full");
    }
    queue.rear = (queue.rear + 1) % MAXSIZE;
    queue.data[queue.rear] = element;
}

// Exit Queue
void exitQueue(Queue& queue, int& element) {
    if (queue.front == queue.rear) {
        throw out_of_range("error : the queue is empty");
    }
    queue.front = (queue.front + 1) % MAXSIZE;
    element = queue.data[queue.front];
}

int main(void) {    
    return EXIT_SUCCESS;
}