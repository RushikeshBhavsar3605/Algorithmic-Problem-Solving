#include "template.hpp"

class Solution {
  private:
    nvec_t<string, 2> res;
    nvec_t<string, 1> path;

    bool isPalindrome(const string &s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--])
                return false;

        return true;
    }

    void helper(const string &s, int start) {
        if (start == sz(s)) {
            res.pb(path);
            return;
        }

        loop(end, start, sz(s)) {
            if (!isPalindrome(s, start, end))
                continue;

            path.pb(s.substr(start, end - start + 1));
            helper(s, end + 1);
            path.pop_back();
        }
    }

  public:
    vector<vector<string>> partition(string s) {
        res.clear();

        helper(s, 0);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.partition("aab");
    print(res);
    res = obj.partition("a");
    print(res);
    return 0;
}

/*
Problem: Palindrome Partitioning
*/