#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
bool searchLinkedList(Node *head, int x)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << searchLinkedList(head, 3) << endl;
    return 0;
}

/*
Problem: Search in Linked List.
*/