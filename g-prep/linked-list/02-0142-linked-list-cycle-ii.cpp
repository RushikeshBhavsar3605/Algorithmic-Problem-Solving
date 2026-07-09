#include "template.hpp"

/* Approach (Two Pointers): */
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 2, 0, -4};
    ListNode *head = getLinkedList(v);
    head->next->next->next->next = head->next;
    auto res = obj.detectCycle(head);
    print(res);
    return 0;
}

/*
Problem: Linked List Cycle II
*/