#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *constructLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *temp = head;
        head = new Node(arr[i]);
        head->next = temp;
    }
    return head;
}
void makeCycle(Node *&head, int pos)
{
    Node *temp = head;
    Node *startNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
            startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
int countNodesinLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL || fast->next == NULL)
        return 0;
    int cnt = 1;
    Node *temp = fast->next;
    while (temp != fast)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void display(Node *&head)
{
    Node *temp = head;
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
    Node *head = constructLL(arr);
    display(head);
    makeCycle(head, 2);
    cout << countNodesinLoop(head) << endl;
    return 0;
}

/*
Problem: Find Length of Loop.
*/