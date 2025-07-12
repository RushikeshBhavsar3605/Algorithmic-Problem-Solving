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
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vi result;

        iterate(it, asteroids)
            if (it > 0)
                result.push_back(it);
            else {
                while (!result.empty() && result.back() > 0 && result.back() < -it)
                    result.pop_back();

                if (result.empty() || result.back() < 0)
                    result.push_back(it);

                if (!result.empty() && result.back() == -it)
                    result.pop_back();
            }

        return result;
    }
};

int main() {
    Solution obj;
    vi asteroids = {5, 10, -5};
    vi result = obj.asteroidCollision(asteroids);
    iterate(it, result) cout << it << " ";
    return 0;
}

/*
Problem: Asteroid Collision
*/