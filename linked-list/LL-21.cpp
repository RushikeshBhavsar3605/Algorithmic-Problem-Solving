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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *dummy1 = headA;
    ListNode *dummy2 = headB;
    while (dummy1 != dummy2)
    {
        dummy1 = (dummy1 == NULL) ? headB : dummy1->next;
        dummy2 = (dummy2 == NULL) ? headA : dummy2->next;
    }
    return dummy1;
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
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = new ListNode(2);
    headA->next->next->next->next = new ListNode(4);
    ListNode *headB = new ListNode(3);
    headB->next = headA->next->next->next;
    display(headA);
    display(headB);
    cout << getIntersectionNode(headA, headB)->data << endl;
    return 0;
}

/*
Problem: Intersection of Two Linked Lists.
*/