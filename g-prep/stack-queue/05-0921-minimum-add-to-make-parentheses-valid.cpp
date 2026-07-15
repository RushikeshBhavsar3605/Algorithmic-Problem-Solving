#include "template.hpp"

/* Approach (Stack): */
class Solution {
  public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int moves = 0;

        iterate(it, s) {
            if (it == '(')
                st.push(it);
            else if (st.empty())
                moves++;
            else
                st.pop();
        }

        return moves + sz(st);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    auto res = obj.minAddToMakeValid("())");
    print(res);
    res = obj.minAddToMakeValid("(((");
    print(res);
    return 0;
}

/*
Problem: Minimum Add to Make Parentheses Valid
*/