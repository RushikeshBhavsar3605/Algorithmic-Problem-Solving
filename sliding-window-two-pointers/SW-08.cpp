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

class Solution {
  public:
    int maxScore(vector<int> &cardPoints, int k) {
        // start with taking all k cards from the end
        int sum = accumulate(end(cardPoints) - k, end(cardPoints), 0);
        int best = sum;                              // record best score so far
        int left = 0, right = cardPoints.size() - k; // window boundaries

        // slide window: shift one card from end-window to front-window
        while (left < k && right < cardPoints.size()) {
            sum += cardPoints[left++];  // add one from front
            sum -= cardPoints[right++]; // remove one from back
            best = max(best, sum);      // update best if higher
        }

        return best;
    }
};

int main() {
    Solution obj;
    vi v = {1, 2, 3, 4, 5, 6, 1};
    cout << obj.maxScore(v, 3) << endl;
    v = {2, 2, 2};
    cout << obj.maxScore(v, 2) << endl;
    v = {9, 7, 7, 9, 7, 7, 9};
    cout << obj.maxScore(v, 7) << endl;
    v = {1, 79, 80, 1, 1, 1, 200, 1};
    cout << obj.maxScore(v, 3) << endl;
    v = {96, 90, 41, 82, 39, 74, 64, 50, 30};
    cout << obj.maxScore(v, 8) << endl;
    return 0;
}

/*
Problem: Maximum Points You Can Obtain from Cards
*/