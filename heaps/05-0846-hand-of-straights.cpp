#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>

// STL shortcuts
#define all(x) begin(x), end(x)

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

/* Approach 1 (Heap):
class Solution {
  public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        // must split hand into equal‑sized groups
        if (hand.size() % groupSize)
            return false;

        int maxi = *max_element(all(hand));
        int mini = *min_element(all(hand));

        // freq array: count[v] = how many copies of card v remain
        vi count(maxi + 1, 0);
        iterate(it, hand)
            count[it]++;

        // min‑heap of the *smallest* card values still available
        priority_queue<int, vi, greater<int>> pq;
        loop(i, 0, count.size())
            if (count[i])
                pq.push(i);

        // keep forming consecutive runs of length groupSize
        while (!pq.empty()) {
            int start = pq.top();                   // smallest card left

            if (start + groupSize > count.size())   // not enough room
                return false;

            // consume cards [start, ..., start+groupSize‑1]
            loop(i, start, start + groupSize) {
                if (count[i] == 0)      // missing card
                    return false;

                if (--count[i] == 0) {  // use one copy
                    if (i != pq.top())  // must always pop in order
                        return false;

                    pq.pop();
                }
            }
        }

        return true; // all cards grouped
    }
};
*/

/* Approach 2 (Hashing):*/
class Solution {
  public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize) // total cards must fit exact groups
            return false;

        map<int, int> freq;          // ordered freq table: card → count
        iterate(it, hand)
            freq[it]++;

        while (!freq.empty()) {
            int start = freq.begin()->first; // smallest remaining card

            loop(i, start, start + groupSize) {
                auto it = freq.find(i); // need each consecutive card
                if (it == freq.end())
                    return false;

                if (--it->second == 0)  // use one copy
                    freq.erase(it);     // remove key when exhausted
            }
        }

        return true; // all cards grouped successfully
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << obj.isNStraightHand(v, 3) << endl;
    v = {1, 2, 3, 4, 5};
    cout << obj.isNStraightHand(v, 4) << endl;
    v = {1, 1, 2, 2, 3, 3};
    cout << obj.isNStraightHand(v, 2) << endl;
    return 0;
}

/*
Problem: Hand of Straights
*/