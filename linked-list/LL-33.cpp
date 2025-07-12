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
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
        return NULL;
    priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> min_heap;
    for (int i = 0; i < n; i++)
    {
        if (lists[i] != NULL)
            min_heap.push({lists[i]->data, lists[i]});
    }
    ListNode *dummyNode = new ListNode(-1);
    ListNode *curr = dummyNode;
    while (!min_heap.empty())
    {
        auto it = min_heap.top();
        min_heap.pop();
        if (it.second->next != NULL)
            min_heap.push({it.second->next->data, it.second->next});
        curr->next = it.second;
        curr = curr->next;
    }
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
    vector<int> arr = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};
    ListNode *head = constructLL(arr);
    ListNode *head2 = constructLL(arr2);
    ListNode *head3 = constructLL(arr3);
    display(head);
    display(head2);
    display(head3);
    vector<ListNode *> v = {head, head2, head3};
    head = mergeKLists(v);
    display(head);
    return 0;
}

/*
Problem: Merge K Sorted Lists.
*/