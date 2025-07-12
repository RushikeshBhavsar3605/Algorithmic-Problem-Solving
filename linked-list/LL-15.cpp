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
bool isPalindrome(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = reverseList(slow->next);
    ListNode *first = head;
    ListNode *second = newHead;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverseList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseList(newHead);
    return true;
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
    vector<int> arr = {1, 2, 3, 2, 1};
    ListNode *head = constructLL(arr);
    display(head);
    cout << isPalindrome(head) << endl;
    display(head);
    return 0;
}

/*
Problem: Palindrome Linked List.
*/