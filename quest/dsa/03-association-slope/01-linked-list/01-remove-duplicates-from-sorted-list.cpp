#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr = head;
        ListNode *temp, *toDelete;

        while (curr) {
            temp = curr->next;
            while (temp && temp->val == curr->val) {
                toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }

            curr->next = temp;
            curr = temp;
        }

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
Problem: Remove Duplicates from Sorted List
*/