#include "template.hpp"

/* Approach (Pointers): */
class Solution {
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0, head);
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        while (n--)
            fast = fast->next;

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *node = slow->next;
        slow->next = node->next;
        delete node;

        return dummy.next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 4, 5};
    auto res = obj.removeNthFromEnd(getLinkedList(v), 2);
    print(res);
    return 0;
}

/*
Problem: Remove Nth Node From End of List
*/