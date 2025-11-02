#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

// Printing to stdout (iostream)
#define print(x)                                                                                                       \
    do {                                                                                                               \
        std::cout << (x);                                                                                              \
    } while (0)
#define println(x)                                                                                                     \
    do {                                                                                                               \
        std::cout << (x) << '\n';                                                                                      \
    } while (0)

class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int data) {
        val = data;
        next = nullptr;
    }
};

ListNode *ArrayToList(vi v) {
    ListNode *head = new ListNode(v[0]);
    ListNode *temp = head;

    loop(i, 1, sz(v)) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }

    return head;
}

void display(ListNode *head) {
    ListNode *temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Approach 1 (Naive): */
class Solution {
  public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        uset<int> st = {all(nums)};
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr) {
            if (st.count(curr->val)) {
                if (!prev) {
                    ListNode *temp = head;
                    head = head->next;
                    curr = head;
                    delete (temp);
                } else {
                    prev->next = curr->next;
                    ListNode *temp = curr;
                    curr = curr->next;
                    delete (temp);
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

int main() {
    Solution obj;
    ListNode *head = ArrayToList({1, 2, 3, 4, 5});
    vi v = {1, 2, 3};
    display(obj.modifiedList(v, head));

    head = ArrayToList({1, 2, 1, 2, 1, 2});
    v = {1};
    display(obj.modifiedList(v, head));

    head = ArrayToList({1, 2, 3, 4});
    v = {5};
    display(obj.modifiedList(v, head));
}

/*
Problem: Delete Nodes From Linked List Present in Array
*/