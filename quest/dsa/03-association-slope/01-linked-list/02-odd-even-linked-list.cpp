#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.solve();
    print(res);
    return 0;
}

/*
Problem: Odd Even Linked List
*/