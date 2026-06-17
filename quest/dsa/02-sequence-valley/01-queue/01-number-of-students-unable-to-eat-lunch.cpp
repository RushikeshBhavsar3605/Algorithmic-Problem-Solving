#include "template.hpp"

/* Approach 1 (Naive):
class Solution {
  public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        queue<int> q;
        iterate(student, students)
            q.push(student);

        int idx = 0;
        int itr = sz(students);

        while (!q.empty() && itr-- != 0) {
            if (q.front() == sandwiches[idx]) {
                idx++;
                itr = sz(students);
            } else
                q.push(q.front());

            q.pop();
        }

        return sz(q);
    }
};
*/

/* Approach 2 (Counting): */
class Solution {
  public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        int zeroCnt = 0;
        int oneCnt = 0;
        iterate(it, students)
            it == 0 ? zeroCnt++ : oneCnt++;

        int n = sz(students);
        loop(i, 0, n) {
            sandwiches[i] == 0 ? zeroCnt-- : oneCnt--;

            if (zeroCnt == -1 || oneCnt == -1)
                return n - i;
        }

        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vi v1 = {1, 1, 0, 0};
    vi v2 = {0, 1, 0, 1};
    auto res = obj.countStudents(v1, v2);
    print(res);
    v1 = {1, 1, 1, 0, 0, 1};
    v2 = {1, 0, 0, 0, 1, 1};
    res = obj.countStudents(v1, v2);
    print(res);
    return 0;
}

/*
Problem: Number of Students Unable to Eat Lunch
*/