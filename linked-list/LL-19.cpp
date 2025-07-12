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
ListNode *merge(ListNode *list1, ListNode *list2)
{
    ListNode *startNode = new ListNode(0);
    ListNode *curr = startNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if (list1 != NULL)
        curr->next = list1;
    else
        curr->next = list2;
    return startNode->next;
}
ListNode *findMiddle(ListNode *head)
{
    ListNode *temp = NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;
    return slow;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *mid = findMiddle(head);

    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);

    return merge(left, right);
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
    vector<int> arr = {2, 1, 3, 4, 5};
    ListNode *head = constructLL(arr);
    display(head);
    head = sortList(head);
    display(head);
    return 0;
}

/*
Problem: Sort Linked List.
*/