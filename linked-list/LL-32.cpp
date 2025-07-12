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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
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
    return dummyNode->next;
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
    vector<int> arr = {1, 2, 4};
    vector<int> arr2 = {1, 3, 4};
    ListNode *head = constructLL(arr);
    ListNode *head2 = constructLL(arr2);
    display(head);
    display(head2);
    head = mergeTwoLists(head, head2);
    display(head);
    return 0;
}

/*
Problem: Merge Two Sorted Lists.
*/