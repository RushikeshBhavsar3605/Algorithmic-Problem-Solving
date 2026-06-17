#include "template.hpp"

/* Approach 1 (Naive):
class MyQueue {
  private:
    stack<int> st1, st2;
    int peekEle;

  public:
    MyQueue() { peekEle = -1; }

    void push(int x) {
        if (peekEle == -1)
            peekEle = x;
        st1.push(x);
    }

    int pop() {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int front = st2.top();
        st2.pop();

        if (!st2.empty())
            peekEle = st2.top();
        else
            peekEle = -1;

        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return front;
    }

    int peek() { return peekEle; }

    bool empty() { return peekEle == -1; }
};
*/

/* Approach 2 (On Demand Switch): */
class MyQueue {
  private:
    stack<int> input, output;

  public:
    MyQueue() {}

    void push(int x) { input.push(x); }

    int pop() {
        if (output.empty())
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }

        int front = output.top();
        output.pop();

        return front;
    }

    int peek() {
        if (output.empty())
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }

        return output.top();
    }

    bool empty() { return input.empty() && output.empty(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    MyQueue obj;
    obj.push(1);
    obj.push(2);
    auto res = obj.peek();
    print(res);
    res = obj.pop();
    print(res);
    res = obj.empty();
    print(res);
    return 0;
}

/*
Problem: Implement Queue using Stacks
*/