#include "template.hpp"

/* Approach (Pointers): */
class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp;

        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {1, 2, 3, 4, 5};
    auto res = obj.reverseList(getLinkedList(v));
    prettyPrintLinkedList(res);
    return 0;
}

/*
Problem: Reverse Linked List
*/