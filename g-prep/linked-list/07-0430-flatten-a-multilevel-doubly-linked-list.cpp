#include "template.hpp"

/* Approach 1 (Recursive):
class Solution {
  private:
    Node *dfs(Node *head) {
        Node *curr = head;
        Node *tail = head;

        while (curr) {
            Node *next = curr->next;

            if (curr->child) {
                Node *childHead = curr->child;
                Node *childTail = dfs(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                tail = childTail;
            } else
                tail = curr;

            curr = next;
        }

        return tail;
    }

  public:
    Node *flatten(Node *head) {
        dfs(head);
        return head;
    }
};
*/

/* Approach 2 (Iterative Stack): */
class Solution {
  public:
    Node *flatten(Node *head) {
        if (!head)
            return nullptr;

        stack<Node *> st;
        st.push(head);

        Node *prev = nullptr;

        while (!st.empty()) {
            Node *curr = st.top();
            st.pop();

            if (prev) {
                prev->next = curr;
                curr->prev = prev;
            }

            if (curr->next)
                st.push(curr->next);

            if (curr->child) {
                st.push(curr->child);
                curr->child = nullptr;
            }

            prev = curr;
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
Problem: Flatten a Multilevel Doubly Linked List
*/