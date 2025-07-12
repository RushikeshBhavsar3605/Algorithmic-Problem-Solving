#include <bits/stdc++.h>
using namespace std;
class MinStack
{
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() { mini = LONG_LONG_MAX; }

    void push(int val)
    {
        if (st.empty())
        {
            st.push((long long)val);
            mini = val;
            return;
        }
        if (val < mini)
        {
            st.push((long long)2 * val - mini);
            mini = val;
            return;
        }
        st.push(val);
    }

    void pop()
    {
        if (st.empty())
            return;
        long long curr = st.top();
        st.pop();
        if (curr < mini)
            mini = 2 * mini - curr;
    }

    int top()
    {
        if (st.empty())
            return -1;
        if (mini > st.top())
            return (int)mini;
        return (int)st.top();
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        return (int)mini;
    }
};
int main()
{
    MinStack *st = new MinStack();
    st->push(5);
    st->push(4);
    st->push(2);
    cout << st->getMin() << endl;
    st->pop();
    cout << st->getMin() << endl;
    st->pop();
    cout << st->getMin() << endl;
    return 0;
}

/*
Problem: Min Stack
*/