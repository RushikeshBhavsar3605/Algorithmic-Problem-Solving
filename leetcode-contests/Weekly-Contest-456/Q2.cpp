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
    private:
    int LCP(const string& a, const string& b) {
    int i = 0;
    while (i < a.size() && i < b.size() && a[i] == b[i]) {
        i++;
    }
    return i;
}
  public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
    if (n == 1) {
        return {0};
    }
    if (n == 2) {
        return {0, 0};
    }

    vector<int> orig;
    for (int i = 0; i < n - 1; i++) {
        orig.push_back(longestCommonPrefix(words[i], words[i+1]));
    }

    vector<int> prefix_max(n-1);
    prefix_max[0] = orig[0];
    for (int i = 1; i < n-1; i++) {
        prefix_max[i] = max(prefix_max[i-1], orig[i]);
    }

    vector<int> suffix_max(n-1);
    suffix_max[n-2] = orig[n-2];
    for (int i = n-3; i >= 0; i--) {
        suffix_max[i] = max(suffix_max[i+1], orig[i]);
    }

    vector<int> ans(n, 0);
    for (int k = 0; k < n; k++) {
        int candidate = 0;
        if (k >= 2) {
            candidate = max(candidate, prefix_max[k-2]);
        }
        if (k <= n-3) {
            candidate = max(candidate, suffix_max[k+1]);
        }
        if (k >= 1 && k <= n-2) {
            int new_pair_val = longestCommonPrefix(words[k-1], words[k+1]);
            candidate = max(candidate, new_pair_val);
        }
        ans[k] = candidate;
    }

    return ans;
    }
};

// class Solution {
//   public:
//     vector<int> longestCommonPrefix(vector<string>& words) {
//         vi prefix(words.size(), 0), suffix(words.size(), 0);
//         int length = 0;
//         loop(i, 0, words.size()-1) {
//             string word1 = words[i];
//             string word2 = words[i+1];
//             int currLength = 0;
//             loop(j, 0, word1.size()) {
//                 if (word1[j]!=word2[j])
//                     break;
//                 currLength++;
//             }
//             length=max(length, currLength);
//             prefix[i+1] = length;
//         }
//         length = 0;
//         revloop(i, words.size()-2, 0) {
//             string word1 = words[i];
//             string word2 = words[i+1];
//             int currLength = 0;
//             loop(j, 0, word1.size()) {
//                 if (word1[j]!=word2[j])
//                 break;
//                 currLength++;
//             }
//             length=max(length, currLength);
//             suffix[i] = length;
//         }
//         iterate(it, prefix) {
//             cout << it << " ";
//         }cout << endl;
//         iterate(it, suffix) {
//             cout << it << " ";
//         }
//         cout << endl;
//         vi result;
//         int n = words.size()-1;
//         loop(i, 0, words.size()) {

//             result.push_back(max(prefix[i], suffix[i]));
//         }
//         return result;
//     }
// };

// class Solution {
//   public:
//     vector<int> longestCommonPrefix(vector<string>& words) {
//         vi result;
//         vi compute;
//         loop(i, 0, words.size()-1) {
//             string word1 = words[i];
//             string word2 = words[i+1];
//             int length = 0;
//             loop(j, 0, word1.size()) {
//                 if (word1[j]!=word2[j])
//                     break;
//                 length++;
//             }
//             compute.push_back(length);
//         }
//     }
// };

int main() {
    Solution obj;
    vector<string> ws={"jump","run","run","jump","run"};
    vi res = obj.longestCommonPrefix(ws);
    cout << endl << endl;
    iterate(it, res)
        cout << it << " ";
    return 0;
}

/*
Problem:
*/