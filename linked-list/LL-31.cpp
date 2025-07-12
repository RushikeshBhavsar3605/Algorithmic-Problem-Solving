#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *random;
    Node(int val)
    {
        data = val;
        next = random = NULL;
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
void insertCopyInBetween(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nextElement = curr->next;
        Node *copy = new Node(curr->data);
        copy->next = nextElement;
        curr->next = copy;
        curr = nextElement;
    }
}
void connectRandomPointers(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *copyNode = curr->next;
        if (curr->random)
            copyNode->random = curr->random->next;
        else
            copyNode->random = NULL;
        curr = curr->next->next;
    }
}
Node *getDeepCopyList(Node *head)
{
    Node *curr = head;
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while (curr != NULL)
    {
        res->next = curr->next;
        res = res->next;
        curr->next = curr->next->next;
        curr = curr->next;
    }
    return dummyNode->next;
}
Node *copyRandomList(Node *head)
{
    insertCopyInBetween(head);
    connectRandomPointers(head);
    return getDeepCopyList(head);
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
    return 0;
}

/*
Problem: Copy List with Random Pointer.
*/