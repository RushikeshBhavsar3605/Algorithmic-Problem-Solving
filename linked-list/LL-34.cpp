#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node *next, *prev;
    Node(string val)
    {
        data = val;
        next = prev = NULL;
    }
};
class BrowserHistory
{
    Node *currentPage;

public:
    BrowserHistory(string homepage)
    {
        currentPage = new Node(homepage);
    }

    void visit(string url)
    {
        Node *newPage = new Node(url);
        currentPage->next = newPage;
        newPage->prev = currentPage;
        currentPage = newPage;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (currentPage->prev)
                currentPage = currentPage->prev;
            else
                break;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (currentPage->next)
                currentPage = currentPage->next;
            else
                break;
            steps--;
        }
        return currentPage->data;
    }
};
int main()
{
    BrowserHistory *obj = new BrowserHistory("google.com");
    obj->visit("facebook.com");
    obj->visit("apple.com");
    obj->visit("uber.com");
    cout << obj->back(2) << endl;
    cout << obj->forward(2) << endl;
    return 0;
}

/*
Problem: Design Browser History.
*/