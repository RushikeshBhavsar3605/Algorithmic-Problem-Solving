#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define vll vector<ll>

#define repeat(count) for (int _iter = 0; _iter < (count); ++_iter)
#define iterate(var, start, end) for (int var = (start); var <= (end); ++var)
#define reverse_iterate(var, start, end) for (int var = (start); var >= (end); --var)

#define resize_vec(vec, size, value) vec.assign(size, value)
#define find_in_set(setname, element) (setname.find(element) != setname.end())

#define fastio()                                                                                                       \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr)

#define pair_int std::pair<int, int>
#define long_pair std::pair<long long, long long>

#define is_between(x, low, high) ((x) >= (low) && (x) <= (high))

int main() { return 0; }

/*
Problem:
*/

vi inCnt; resize_vec(inCnt, n, 0);
        vector<vi> adj(n);
        for (auto &ed : E) {
            adj[ed[0]].push_back(ed[1]);
            inCnt[ed[1]]++;
        }
        auto mid = make_pair(adj, inCnt);
        vi req(n, 0);
        iterate(u, 0, n-1) for (int v : mid.first[u]) req[v] |= 1<<u;

        int FULL = (1<<n) - 1;
        vll dp(1<<n, -1);
        dp[0] = 0;
        iterate(mask, 0, FULL) if (dp[mask] >= 0) {
            int pos = __builtin_popcount(mask) + 1;
            iterate(i, 0, n-1) {
                if (!((mask>>i)&1) && ((req[i]&mask) == req[i])) {
                    int nxt = mask | (1<<i);
                    dp[nxt] = max(dp[nxt], dp[mask] + (ll)S[i] * pos);
                }
            }
        }

        return (int)dp[FULL];



        fastio();
        
        unordered_map<int, set<int>> rows, cols;
        
        for (auto& b : buildings) {
            rows[b[0]].insert(b[1]);
            cols[b[1]].insert(b[0]);
        }

        int covered = 0;
        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            auto left = rows[x].lower_bound(y);
            bool has_left = (left != rows[x].begin());

            auto right = rows[x].upper_bound(y);
            bool has_right = (right != rows[x].end());

            auto up = cols[y].lower_bound(x);
            bool has_up = (up != cols[y].begin());

            auto down = cols[y].upper_bound(x);
            bool has_down = (down != cols[y].end());

            if (has_left && has_right && has_up && has_down)
                covered++;
        }

        return covered;



        vector<int> solveQueries(int n, vector<int>& N, int MD, vector<vector<int>>& queries) {
            preprocess(N, MD);
            computeLR();
            precomputeJumps();
            vector<int> result;
            RESERVE_VECTOR(result, Q.size());
            for (const auto& query : Q) {
                result.push_back(handleQuery(query[0], query[1]));
            }
            return result;
        }



        int N, D, LOG;
    vector<int> sortedArray, position, leftBound, rightBound;
    vector<vector<pair<int, int>>> jumpTable;

    void preprocess(vector<int>& nums, int maxDiff) {
        N = nums.size();
        D = maxDiff;
        sortedArray.resize(N);
        position.resize(N);
        vector<pair<int, int>> sortedPairs(N);

        for (int i = 0; i < N; ++i) {
            sortedPairs[i] = { nums[i], i };
        }
        sort(sortedPairs.begin(), sortedPairs.end());

        for (int i = 0; i < N; ++i) {
            sortedArray[i] = sortedPairs[i].first;
            position[sortedPairs[i].second] = i;
        }
    }

    void computeLR() {
        INIT_VECTOR(leftBound, N, 0);
        INIT_VECTOR(rightBound, N, 0);
        int leftIndex = 0;

        for (int i = 0; i < N; ++i) {
            while (sortedArray[i] - sortedArray[leftIndex] > D) {
                ++leftIndex;
            }
            leftBound[i] = leftIndex;
        }

        int rightIndex = N - 1;
        for (int i = N - 1; i >= 0; --i) {
            while (rightIndex >= 0 && sortedArray[rightIndex] - sortedArray[i] > D) {
                --rightIndex;
            }
            rightBound[i] = rightIndex;
        }
    }

    void precomputeJumps() {
        LOG = 0;
        while ((1 << LOG) <= N) ++LOG;
        jumpTable.assign(LOG, vector<pair<int, int>>(N));

        for (int i = 0; i < N; ++i) {
            jumpTable[0][i] = { leftBound[i], rightBound[i] };
        }

        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < N; ++i) {
                auto [l1, r1] = jumpTable[k - 1][i];
                auto [l2, r2] = jumpTable[k - 1][l1];
                auto [l3, r3] = jumpTable[k - 1][r1];
                jumpTable[k][i] = { l2, r3 };
            }
        }
    }

    int handleQuery(int u0, int v0) {
        int u = position[u0], v = position[v0];
        if (u == v) return 0;
        if (u > v) SWAP(u, v);

        int jumpCount = 0;
        int left = u, right = u;
        for (int k = LOG - 1; k >= 0; --k) {
            auto [l2, r2] = jumpTable[k][right];
            if (r2 < v) {
                jumpCount += (1 << k);
                left = jumpTable[k][left].first;
                right = r2;
            }
        }

        auto [lF, rF] = jumpTable[0][right];
        if (rF < v) return -1;
        return jumpCount + 1;
    }


    #define INIT_VECTOR(v, size, value) v.resize(size, value)
#define RESERVE_VECTOR(v, size) v.reserve(size)
#define SWAP(a, b) { auto tmp = a; a = b; b = tmp; }
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)


#define vi vector<int>
        for (int i = 0; i < N; ++i) {
            jumpTable[0][i] = { leftBound[i], rightBound[i] };
        }

        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < N; ++i) {
                auto [l1, r1] = jumpTable[k - 1][i];
                auto [l2, r2] = jumpTable[k - 1][l1];
                auto [l3, r3] = jumpTable[k - 1][r1];
                jumpTable[k][i] = { l2, r3 };
            }
        }
    }

    int handleQuery(int u0, int v0) {
        int u = position[u0], v = position[v0];
        if (u == v) return 0;
        if (u > v) SWAP(u, v);

        int jumpCount = 0;
        int left = u, right = u;
        for (int k = LOG - 1; k >= 0; --k) {
            auto [l2, r2] = jumpTable[k][right];
            if (r2 < v) {
                jumpCount += (1 << k);
                left = jumpTable[k][left].first;
                right = r2;
            }
        }

        auto [lF, rF] = jumpTable[0][right];
        if (rF < v) return -1;
        return jumpCount + 1;
    }
public:
    vector<int> pathExistenceQueries(int n, vector<int>& N, int MD, vector<vector<int>>& Q) {
        preprocess(N, MD);
            computeLR();
            precomputeJumps();
            vector<int> result;
            RESERVE_VECTOR(result, Q.size());
            for (const auto& query : Q) {
                result.push_back(handleQuery(query[0], query[1]));
            }
            return result;
    }
};©leetcode