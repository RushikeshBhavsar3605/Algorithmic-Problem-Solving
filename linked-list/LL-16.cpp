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
ListNode *oddEvenList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
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
    head = oddEvenList(head);
    display(head);
    return 0;
}

/*
Problem: Odd Even Linked List.
*/