#include <bits/stdc++.h>
using namespace std;
class StackNode
{
public:
    int top, data;
    StackNode *next;
    StackNode(int x)
    {
        top = -1;
        data = x;
        next = NULL;
    }
};
class MyStack
{
private:
    StackNode *top;

public:
    void push(int x)
    {
        StackNode *current = new StackNode(x);
        current->next = top;
        top = current;
    }

    int pop()
    {
        if (!top)
            return -1;

        StackNode *current = top;
        top = top->next;
        int element = current->data;
        delete current;
        return element;
    }

    MyStack() { top = NULL; }
};
int main()
{
    MyStack *st = new MyStack();
    st->push(1);
    st->push(2);
    cout << st->pop() << endl;
    cout << st->pop() << endl;
    return 0;
}

/*
Problem: Implement Stack using Linked List
*/