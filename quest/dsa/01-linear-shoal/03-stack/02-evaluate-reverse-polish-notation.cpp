#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;

        iterate(token, tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                switch (token[0]) {
                case '+':
                    st.push(num2 + num1);
                    break;
                case '-':
                    st.push(num2 - num1);
                    break;
                case '*':
                    st.push(num2 * num1);
                    break;
                case '/':
                    st.push(num2 / num1);
                    break;
                default:
                    break;
                }
            } else
                st.push(stoi(token));
        }

        return st.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    nvec_t<string, 1> v = {"2", "1", "+", "3", "*"};
    auto res = obj.evalRPN(v);
    print(res);
    v = {"4", "13", "5", "/", "+"};
    res = obj.evalRPN(v);
    print(res);
    v = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    res = obj.evalRPN(v);
    print(res);
    return 0;
}

/*
Problem: Evaluate Reverse Polish Notation
*/