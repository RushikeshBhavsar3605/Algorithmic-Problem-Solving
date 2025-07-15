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
    vector<int> topKFrequent(vector<int> &nums, int k) {
        map<int, int> mp;  // value -> frequency
        iterate(num, nums) // custom macro: for-each element
            mp[num]++;     // count occurrences

        // min-heap stores the k highest-frequency pairs {freq, value}
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        iterate(it, mp) {
            minHeap.push({it.second, it.first}); // push current {freq, value}
            if (minHeap.size() > k)              // keep heap size ≤ k
                minHeap.pop();                   // remove lowest frequency
        }

        vi result(minHeap.size(), 0); // output container
        while (!minHeap.empty()) {    // extract in reverse order
            result[minHeap.size() - 1] = minHeap.top().second;
            minHeap.pop();
        }

        return result;
    }
};
*/

/* Approach 2 (Reverse Hashing):
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // 1) Count occurrences of every number
        unordered_map<int, int> count;
        iterate(num, nums)
            count[num]++;

        // 2) Bucket numbers by frequency: bucket[freq] → list of values
        vvi bucket(nums.size() + 1);
        iterate(it, count)
            bucket[it.second].push_back(it.first);

        // 3) Walk buckets from highest freq down, push until we hit k
        vi result;
        revloop(i, bucket.size() - 1, 1) {
            iterate(num, bucket[i]) {
                result.push_back(num);

                if (result.size() == k)
                    return result; // early-exit
            }
        }

        return {}; // fallback (shouldn’t hit)
    }
};
*/

/* Approach 3 (Reverse Hashing via Map): */
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freq;   // value -> frequency
        iterate(num, nums)
            freq[num]++;                // 1️⃣ count every number

        int maxFreq = -1;
        unordered_map<int, vi> bucket; // freq -> list of values
        iterate(num, freq) {           // 2️⃣ bucket by frequency
            maxFreq = max(maxFreq, num.second);
            bucket[num.second].push_back(num.first);
        }

        vi result;
        revloop(it, maxFreq, 1) {       // 3️⃣ scan freqs high → low
            if (!bucket.count(it))      // skip empty buckets
                continue;

            iterate(i, bucket[it]) {    // grab values in this bucket
                result.push_back(i);
                if (result.size() == k) // 4️⃣ stop once k found
                    return result;
            }
        }

        return {}; // should never hit (k ≤ n)
    }
};

int main() {
    Solution obj;
    vi v = {1, 1, 1, 2, 2, 3};
    vi result = obj.topKFrequent(v, 2);
    iterate(it, result) cout << it << " ";
    cout << endl;
    return 0;
}

/*
Problem: Top K Frequent Elements
*/