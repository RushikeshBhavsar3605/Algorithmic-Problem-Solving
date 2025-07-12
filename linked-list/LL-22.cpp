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
int helper(Node *head)
{
    if (head == NULL)
        return 1;
    int carry = helper(head->next);
    int sum = head->data + carry;
    head->data = (sum < 10) ? sum : 0;
    carry = (sum < 10) ? 0 : 1;
    return carry;
}
Node *addOne(Node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newHead = new Node(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}
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
int main()
{
    vector<int> arr = {4, 5, 6};
    Node *head = constructLL(arr);
    display(head);
    head = addOne(head);
    display(head);
    return 0;
}

/*
Problem: Add 1 to a Linked List Number.
*/