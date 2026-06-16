#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    ListNode *deleteMiddle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        ListNode *prevSlow = nullptr;

        while (fast && fast->next) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (!prevSlow)
            return nullptr;

        prevSlow->next = slow->next;
        delete slow;

        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 3, 4, 7, 1, 2, 6};
    ListNode *head = getLinkedList(v);
    auto res = obj.deleteMiddle(head);
    prettyPrintLinkedList(res);
    v = {1, 2, 3, 4};
    head = getLinkedList(v);
    res = obj.deleteMiddle(head);
    prettyPrintLinkedList(res);
    v = {2, 1};
    head = getLinkedList(v);
    res = obj.deleteMiddle(head);
    prettyPrintLinkedList(res);
    return 0;
}

/*
Problem: Delete the Middle Node of a Linked List
*/