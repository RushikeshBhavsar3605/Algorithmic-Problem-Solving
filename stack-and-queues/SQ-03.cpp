#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() { return q.front(); }

    bool empty() { return q.empty(); }
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
Problem: Implement Stack using Queues
*/