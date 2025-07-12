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
void makeCycle(ListNode *head, int pos)
{
    ListNode *temp;
    ListNode *startListNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
            startListNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startListNode;
}
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;
    do
    {
        if (fast == NULL || fast->next == NULL)
            return NULL;
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    if (slow == fast)
        return fast;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast->next;
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
    ListNode *node = detectCycle(head);
    // cout << node->data << endl;
    makeCycle(head, 3);
    node = detectCycle(head);
    cout << node->data << endl;
    return 0;
}

/*
Problem: Detect Linked List Cycle - II
*/