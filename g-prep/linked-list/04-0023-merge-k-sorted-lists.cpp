#include "template.hpp"

/* Approach 1 (Merge Pointer):
class Solution {
  private:
    ListNode *merge(ListNode *a, ListNode *b) {
        ListNode dummy;
        ListNode *tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;

        int interval = 1;

        while (interval < sz(lists)) {
            for (int i = 0; i + interval < sz(lists); i += interval * 2)
                lists[i] = merge(lists[i], lists[i + interval]);

            interval *= 2;
        }

        return lists[0];
    }
};
*/

/* Approach 2 (Heap): */
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> minHeap(cmp);

        iterate(node, lists) if (node) minHeap.push(node);

        ListNode dummy;
        ListNode *tail = &dummy;

        while (!minHeap.empty()) {
            ListNode *node = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                minHeap.push(node->next);
        }

        return dummy.next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {1, 4, 5};
    vi v2 = {1, 3, 4};
    vi v3 = {2, 6};
    vector<ListNode *> v = {getLinkedList(v1), getLinkedList(v2), getLinkedList(v3)};
    auto res = obj.mergeKLists(v);
    print(res);
    return 0;
}

/*
Problem: Merge k Sorted Lists
*/