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
ListNode *reverse(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
ListNode *getKthListNode(ListNode *curr, int k)
{
    k--;
    while (curr != NULL && k > 0)
    {
        k--;
        curr = curr->next;
    }
    return curr;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *curr = head;
    ListNode *prevLast = NULL;
    while (curr != NULL)
    {
        ListNode *kthListNode = getKthListNode(curr, k);
        if (kthListNode == NULL)
        {
            if (prevLast)
                prevLast->next = curr;
            break;
        }
        ListNode *nextListNode = kthListNode->next;
        kthListNode->next = NULL;
        reverse(curr);
        if (curr == head)
            head = kthListNode;
        else
            prevLast->next = kthListNode;
        prevLast = curr;
        curr = nextListNode;
    }
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
    head = reverseKGroup(head, 2);
    display(head);
    return 0;
}

/*
Problem: Reverse Nodes in K-Group.
*/