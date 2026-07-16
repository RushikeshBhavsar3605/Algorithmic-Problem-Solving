#include "template.hpp"

/* Approach (Inplace Hashing): */
class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;

        for (Node *curr = head; curr; curr = curr->next->next) {
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
        }

        for (Node *curr = head; curr; curr = curr->next->next)
            if (curr->random)
                curr->next->random = curr->random->next;

        Node *dummy = new Node(-1);
        Node *copy = dummy;

        for (Node *curr = head; curr; curr = curr->next) {
            copy->next = curr->next;
            copy = copy->next;

            curr->next = copy->next;
        }

        return dummy->next;
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
Problem: Copy List with Random Pointer
*/