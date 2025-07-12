#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};
ListNode *constructLL(vector<int> &arr)
{
    int n = arr.size();
    ListNode *head = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        ListNode *temp = head;
        head = new ListNode(arr[i]);
        head->next = temp;
    }
    return head;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    int size = 1;
    ListNode *curr = head;
    while (curr->next != NULL)
    {
        size++;
        curr = curr->next;
    }
    curr->next = head;
    int totalSize = size - (k % size);
    curr = head;
    while (curr != NULL)
    {
        if (--totalSize == 0)
            break;
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
}
void display(ListNode *&head)
{
    ListNode *temp = head;
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
    ListNode *head = constructLL(arr);
    display(head);
    head = rotateRight(head, 2);
    display(head);
    return 0;
}

/*
Problem: Rotate List.
*/