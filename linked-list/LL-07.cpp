#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node *constructDLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node *addNode(Node *head, int pos, int data)
{
    Node *temp = head;
    while (temp != NULL && pos != 0)
    {
        temp = temp->next;
        pos--;
    }
    Node *newNode = new Node(data);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
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
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = constructDLL(arr);
    display(head);
    head = addNode(head, 3, 8);
    display(head);
    return 0;
}

/*
Problem: Insert a Node in a Doubly Linked
*/