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
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

/* Approach 1 (Two Pointer):
class Solution {
  private:
    ListNode *merge(ListNode *&list1, ListNode *&list2) {
        ListNode *dummyNode = new ListNode(-1); // sentinel to simplify edge-cases
        ListNode *curr = dummyNode;

        // Pick smaller node from the two lists until one list is exhausted
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // Attach the remaining (non-empty) list
        if (list1 != NULL)
            curr->next = list1;
        else
            curr->next = list2;

        return dummyNode->next; // head of merged list
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;

        ListNode *head = lists[0];
        loop(i, 1, lists.size())
            head = merge(head, lists[i]); // iteratively merge into single list

        return head;
    }
};
*/

class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // min-heap: (node value, node*) so the smallest node is on top
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

        // seed the heap with the first node of every non-empty list
        loop(i, 0, lists.size())
            if (lists[i] != NULL)
                pq.push({lists[i]->val, lists[i]});

        ListNode *head = new ListNode(-1); // sentinel to build the answer list
        ListNode *curr = head;

        while (!pq.empty()) {
            auto it = pq.top(); // extract smallest node
            int val = it.first;
            ListNode *node = it.second;
            pq.pop();

            if (node->next)     // push successor into heap (if any)
                pq.push({node->next->val, node->next});

            curr->next = node;  // append to result
            curr = curr->next;
        }

        return head->next;      // head of merged list
    }
};

int main() {
    Solution obj;
    // obj.solve();
    return 0;
}

/*
Problem:
*/