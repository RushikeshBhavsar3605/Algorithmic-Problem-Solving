#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *bottom;
    Node(int val)
    {
        data = val;
        next = bottom = NULL;
    }
};
void displayNextBottom(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "End" << endl
         << endl;
    curr = head;
    while (curr != NULL)
    {
        Node *temp = curr;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->bottom;
        }
        cout << "End" << endl;
        curr = curr->next;
    }
}
Node *flatten(Node *root)
{
    if (root == 0)
        return NULL;
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> min_heap;
    Node *curr = root;
    while (curr != NULL)
    {
        min_heap.push({curr->data, curr});
        curr = curr->next;
    }
    Node *dummyNode = new Node(-1);
    curr = dummyNode;
    while (!min_heap.empty())
    {
        auto it = min_heap.top();
        min_heap.pop();
        if (it.second->bottom != NULL)
            min_heap.push({it.second->bottom->data, it.second->bottom});
        curr->bottom = it.second;
        curr = curr->bottom;
    }
    return dummyNode->bottom;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->bottom;
    }
    cout << "End" << endl;
}
int main()
{
    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);
    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);
    displayNextBottom(head);
    head = flatten(head);
    cout << endl
         << endl;
    display(head);
    return 0;
}

/*
Problem: Flattening a Linked List.
*/