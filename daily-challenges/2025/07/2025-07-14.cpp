#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
  public:
    int getDecimalValue(ListNode *head) {
        int result = 0;

        // Traverse once, left-shifting the result and adding current bit
        while (head) {
            result = (result << 1) | head->val;
            head = head->next;
        }

        return result;
    }
};

int main() {
    Solution obj;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    cout << obj.getDecimalValue(head) << endl;

    ListNode *head2 = new ListNode(0);
    cout << obj.getDecimalValue(head2) << endl;

    ListNode *head3 = new ListNode(1);
    head3->next = new ListNode(0);
    head3->next->next = new ListNode(1);
    head3->next->next->next = new ListNode(0);
    head3->next->next->next->next = new ListNode(1);
    cout << obj.getDecimalValue(head3) << endl;
    return 0;
}

/*
Problem: Convert Binary Number in a Linked List to Integer
*/