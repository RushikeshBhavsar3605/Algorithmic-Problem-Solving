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
    bool checkPrime(int n) {
        int cnt = 0;
        loop(i, 1, n + 1)
            if (n % i == 0)
                cnt++;

        if (cnt == 2)
            return true;
        else
            return false;
    }

  public:
    bool checkPrimeFrequency(vector<int> &nums) {
        map<int, int> mp;
        iterate(it, nums) mp[it]++;

        iterate(it, mp) if (checkPrime(it.second)) return true;

        return false;
    }
};

int main() {
    Solution obj;
    vi nums = {2,2,2,4,4};
    cout << obj.checkPrimeFrequency(nums);
    return 0;
}

/*
Problem:
*/