#include <bits/stdc++.h>
using namespace std;
class DLLNode
{
public:
    int data;
    DLLNode *next, *prev;
    DLLNode(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
DLLNode *constructDLL(vector<int> &arr)
{
    int n = arr.size();
    DLLNode *head = new DLLNode(arr[0]);
    DLLNode *prev = head;
    for (int i = 1; i < n; i++)
    {
        DLLNode *temp = new DLLNode(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}
DLLNode *reverseDLL(DLLNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    DLLNode *currNode = head;
    DLLNode *prevNode = NULL;
    while (currNode != NULL)
    {
        prevNode = currNode->prev;
        currNode->prev = currNode->next;
        currNode->next = prevNode;
        currNode = currNode->prev;
    }
    return prevNode->prev;
}
void display(DLLNode *&head)
{
    DLLNode *temp = head;
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
    vector<int> arr = {1, 2, 3, 4, 5};
    DLLNode *head = constructDLL(arr);
    display(head);
    head = reverseDLL(head);
    display(head);
    return 0;
}

/*
Problem: Reverse a Doubly Linked List.
*/