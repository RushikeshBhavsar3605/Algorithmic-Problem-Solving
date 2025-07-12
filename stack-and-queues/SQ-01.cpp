#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};
void MyStack ::push(int x)
{
    arr[++top] = x;
}
int MyStack ::pop()
{
    if (top == -1)
        return -1;
    int element = arr[top--];
    return element;
}
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
Problem: Implement Stack using Array
*/