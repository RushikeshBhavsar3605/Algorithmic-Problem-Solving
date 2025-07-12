#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
private:
    stack<int> input, output;

public:
    MyQueue() {}

    void push(int x) { input.push(x); }

    int pop()
    {
        if (output.empty())
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        int element = output.top();
        output.pop();
        return element;
    }

    int peek()
    {
        if (output.empty())
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        return output.top();
    }

    bool empty() { return input.empty() && output.empty(); }
};
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
Problem: Implement Queue using Stacks
*/