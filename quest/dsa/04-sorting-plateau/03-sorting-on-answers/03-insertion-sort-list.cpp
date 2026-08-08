#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = head;

        while (curr != nullptr) {
            ListNode *next = curr->next;
            ListNode *prev = dummy;

            while (prev->next != nullptr && prev->next->val <= curr->val)
                prev = prev->next;

            curr->next = prev->next;
            prev->next = curr;

            curr = next;
        }

        return dummy->next;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    print(head);
    auto res = obj.insertionSortList(head);
    print(res);
    return 0;
}

/*
Problem: Insertion Sort List
*/