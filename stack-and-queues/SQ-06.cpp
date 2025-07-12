#include <bits/stdc++.h>
using namespace std;
class QueueNode
{
public:
    int data;
    QueueNode *next;
    QueueNode(int x)
    {
        data = x;
        next = NULL;
    }
};
class MyQueue
{
private:
    QueueNode *front, *rear;

public:
    MyQueue()
    {
        front = rear = NULL;
    }
    void push(int);
    int pop();
};
void MyQueue::push(int x)
{
    QueueNode *newNode = new QueueNode(x);
    if (!rear)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
int MyQueue ::pop()
{
    if (!front)
        return -1;
    QueueNode *current = front;
    front = front->next;
    if (!front)
        rear = NULL;
    int element = current->data;
    delete current;
    return element;
}
int main()
{
    MyQueue *q = new MyQueue();
    q->push(1);
    q->push(2);
    cout << q->pop() << endl;
    cout << q->pop() << endl;
    return 0;
}

/*
Problem: Implement Queue using Linked List
*/