#include "template.hpp"

/* Approach (Naive): */
class Solution {
  private:
    int toSeconds(string &time) {
        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int s = stoi(time.substr(6, 2));

        return h * 3600 + m * 60 + s;
    }

  public:
    int secondsBetweenTimes(string startTime, string endTime) {
        return toSeconds(endTime) - toSeconds(startTime);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.secondsBetweenTimes("01:00:00", "01:00:25");
    print(res);
    res = obj.secondsBetweenTimes("12:34:56", "13:00:00");
    print(res);
    return 0;
}

/*
Problem: Number of Elapsed Seconds Between Two Times
*/