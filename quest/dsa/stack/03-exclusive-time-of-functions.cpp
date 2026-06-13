#include "template.hpp"

/* Approach (Stack + Simulation): */
class Solution {
  public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vi res(n, 0);
        stack<int> st;

        int prevTime = 0;

        loop(i, 0, sz(logs)) {
            stringstream ss(logs[i]);
            string idStr, op, timeStr;

            getline(ss, idStr, ':');
            getline(ss, op, ':');
            getline(ss, timeStr, ':');

            int id = stoi(idStr);
            int time = stoi(timeStr);

            if (op == "start") {
                if (!st.empty())
                    res[st.top()] += time - prevTime;

                st.push(id);
                prevTime = time;
            } else {
                res[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    nvec_t<string, 1> l = {"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
    auto res = obj.exclusiveTime(2, l);
    print(res);
    l = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
    res = obj.exclusiveTime(1, l);
    print(res);
    l = {"0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"};
    res = obj.exclusiveTime(2, l);
    print(res);
    return 0;
}

/*
Problem: Exclusive Time of Functions
*/