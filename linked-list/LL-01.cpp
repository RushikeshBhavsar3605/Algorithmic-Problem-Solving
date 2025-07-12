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
    Node *head = constructLL(arr);
    display(head);
    return 0;
}

/*
Problem: Array to Linked List.
*/