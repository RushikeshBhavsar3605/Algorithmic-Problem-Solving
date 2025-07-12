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
Node *insertAtEnd(Node *head, int x)
{
    if (head == NULL)
        return new Node(x);
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(x);
    return head;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "End" << endl;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    display(head);
    insertAtEnd(head, 6);
    display(head);
    return 0;
}

/*
Problem: Insert a Node in Linked List.
*/