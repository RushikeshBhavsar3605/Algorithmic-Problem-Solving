#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
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
Node *deleteNode(Node *head, int x)
{
    if (x == 1 && head != NULL)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
    Node *curr = head;
    while (curr != NULL && x != 2)
    {
        curr = curr->next;
        x--;
    }
    if (curr == NULL || curr->next == NULL)
        return head;
    Node *nodeDelete = curr->next;
    curr->next = nodeDelete->next;
    if (nodeDelete->next != NULL)
        nodeDelete->next->prev = curr;
    delete nodeDelete;
    return head;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << " -> " << "End" << endl;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "End" << endl;
}
int main()
{
    vector<int> arr = {29, 78};
    Node *head = constructDLL(arr);
    display(head);
    head = deleteNode(head, 1);
    display(head);
    return 0;
}

/*
Problem: Delete Node in a Doubly Linked List.
*/