#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    int pairSum(ListNode *head) {
        vi nums;
        while (head) {
            nums.pb(head->val);
            head = head->next;
        }

        int n = sz(nums);
        int maxi = 0;

        loop(i, 0, n / 2)
            updateMax(maxi, nums[i] + nums[n - i - 1]);

        return maxi;
    }
};
*/

/* Approach 2 (Reverse Linked List): */
class Solution {
  private:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr) {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

  public:
    int pairSum(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *head2 = reverseList(slow);
        ListNode *curr1 = head;
        ListNode *curr2 = head2;

        int maxi = 0;
        while (curr1 && curr2) {
            updateMax(maxi, curr1->val + curr2->val);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        reverseList(head2);

        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    auto res = obj.pairSum(head);
    print(res);
    return 0;
}

/*
Problem: Maximum Twin Sum of a Linked List
*/