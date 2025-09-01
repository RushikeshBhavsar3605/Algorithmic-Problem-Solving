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
    int maxDistance(string s, int k) {
        int result = 0, latitude = 0, longitude = 0;

        loop(i, 0, s.size()) {
            switch (s[i]) {
                case 'N':
                    latitude++;
                    break;
                case 'S':
                    latitude--;
                    break;
                case 'E':
                    longitude++;
                    break;
                case 'W':
                    longitude--;
                    break;
            }

            result = max(result, min(abs(latitude) + abs(longitude) + k * 2, i + 1));
        }

        return result;
    }
};

int main() {
    Solution obj;
    string s = "NWSE";
    cout << obj.maxDistance(s, 1);
    return 0;
}

/*
Problem:
*/