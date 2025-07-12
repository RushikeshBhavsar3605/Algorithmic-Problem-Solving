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
void deleteAllOccurOfX(Node *&head, int x)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            if (curr == head)
                head = head->next;
            prev = curr->prev;
            next = curr->next;
            if (prev)
                prev->next = next;
            if (next)
                next->prev = prev;
            Node *temp = curr;
            curr = next;
            delete temp;
        }
        else
            curr = curr->next;
    }
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
    vector<int> arr = {2, 2, 10, 8, 4, 2, 5, 2};
    Node *head = constructDLL(arr);
    display(head);
    deleteAllOccurOfX(head, 2);
    display(head);
    return 0;
}

/*
Problem: Delete All Occurrences of a Given Key in a Doubly Linked List.
*/