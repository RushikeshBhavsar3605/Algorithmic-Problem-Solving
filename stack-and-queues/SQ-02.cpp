#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};
void MyQueue ::push(int x)
{
    arr[rear++] = x;
}
int MyQueue ::pop()
{
    if (front == rear)
        return -1;
    return arr[front++];
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
Problem: Implement Queue using Array
*/