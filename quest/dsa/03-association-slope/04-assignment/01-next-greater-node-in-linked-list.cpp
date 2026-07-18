#include "template.hpp"

/* Approach (Linked List + Monotonic Stack): */
class Solution {
  private:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

  public:
    vector<int> nextLargerNodes(ListNode *head) {
        head = reverseList(head);

        vi res;
        stack<int> st;
        ListNode *curr = head;

        while (curr) {
            while (!st.empty() && st.top() <= curr->val)
                st.pop();

            res.pb(st.empty() ? 0 : st.top());
            st.push(curr->val);

            curr = curr->next;
        }

        head = reverseList(head);
        reverse(all(res));

        return res;
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
Problem: Next Greater Node In Linked List
*/