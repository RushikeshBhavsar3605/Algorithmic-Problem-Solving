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
Node *removeDuplicates(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            if (curr->next)
                curr->next->prev = curr;
            delete temp;
        }
        else
            curr = curr->next;
    }
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
    vector<int> arr = {2, 5, 7, 7, 8, 8, 9, 9, 9, 9};
    Node *head = constructDLL(arr);
    display(head);
    head = removeDuplicates(head);
    display(head);
    return 0;
}

/*
Problem: Remove Duplicates from a Sorted Doubly Linked List.
*/