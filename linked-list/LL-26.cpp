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
Node *constructLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *temp = head;
        head = new Node(arr[i]);
        head->next = temp;
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
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "End" << endl;
}
int main()
{
    vector<int> arr = {2, 5, 7, 7, 8, 8, 9, 9, 9, 9};
    Node *head = constructLL(arr);
    display(head);
    head = removeDuplicates(head);
    display(head);
    return 0;
}

/*
Problem: Remove Duplicates from a Sorted Linked List.
*/