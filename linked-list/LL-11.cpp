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
ListNode *reverseList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
ListNode *reverseListRecursive(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newHead = reverseListRecursive(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
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
    head = reverseList(head);
    display(head);
    head = reverseListRecursive(head);
    display(head);
    return 0;
}

/*
Problem: Reverse Linked List.
*/