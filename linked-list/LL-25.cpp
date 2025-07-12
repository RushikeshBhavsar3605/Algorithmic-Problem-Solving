#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
Node *constructDLL(vector<int> &arr)
{
    int n = arr.size();
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node *findTail(Node *head)
{
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    return tail;
}
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    if (head == NULL || head->next == NULL)
        return {{-1, -1}};
    vector<pair<int, int>> result;
    Node *low = head, *high = findTail(head);
    while (low->data < high->data)
    {
        int sum = low->data + high->data;
        if (sum == target)
        {
            result.push_back({low->data, high->data});
            low = low->next;
            high = high->prev;
        }
        else if (sum < target)
            low = low->next;
        else
            high = high->prev;
    }
    return result;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << " -> " << "End" << endl;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "End" << endl;
}
int main()
{
    vector<int> arr = {1, 2, 4, 5, 6, 8, 9};
    Node *head = constructDLL(arr);
    display(head);
    vector<pair<int, int>> result = findPairsWithGivenSum(head, 7);
    for (auto i : result)
        cout << i.first << " " << i.second << endl;
    return 0;
}

/*
Problem: Find Pairs with given Sum in Doubly Linked List.
*/