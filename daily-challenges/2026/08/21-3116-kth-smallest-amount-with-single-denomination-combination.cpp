#include "template.hpp"

class Solution {
  private:
    ll gcd(ll a, ll b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    ll lcmm(ll a, ll b) {
        return (a / gcd(a, b)) * b;
    }

    ll count(ll x, vi &coins) {
        int n = sz(coins);
        ll count = 0;

        loop(mask, 1, (1 << n)) {
            ll lcm = 1;
            int bits = 0;
            bool valid = true;

            loop(i, 0, n) {
                if ((mask & (1 << i)) != 0) {
                    bits++;
                    lcm = lcmm(lcm, coins[i]);
                    if (lcm > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            ll mul = x / lcm;
            if (bits & 1)
                count += mul;
            else
                count -= mul;
        }

        return count;
    }

  public:
    long long findKthSmallest(vector<int> &coins, int k) {
        ll low = 1;
        ll high = LONG_LONG_MAX;

        iterate(coin, coins)
            updateMin(high, (ll)coin * k);

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v = {3, 6, 9};
    auto res = obj.findKthSmallest(v, 3);
    print(res);
    v = {5, 2};
    res = obj.findKthSmallest(v, 7);
    print(res);
    return 0;
}

/*
Problem: Kth Smallest Amount With Single Denomination Combination
*/