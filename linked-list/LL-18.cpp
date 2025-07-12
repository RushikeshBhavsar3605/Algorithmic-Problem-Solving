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
ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *delNode = slow->next;
    slow->next = slow->next->next;
    delete (delNode);
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
    deleteMiddle(head);
    display(head);
    return 0;
}

/*
Problem: Delete the Middle Node of a Linked List.
*/