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
  private:
    bool checkCode(string &s) {
        if (s.size() == 0)
            return false;
        
        iterate(it, s) {
            if (('0' <= it && it <= '9') || ('a' <= it && it <= 'z') || ('A' <= it && it <= 'Z') || (it == '_'))
                ;
            else
                return false;
        }

        return true;
    }
    bool checkLine(string &s) {
        if (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant")
            return true;

        return false;
    }

  public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive) {
        vector<pair<string, string>> mp;
        loop(i, 0, code.size())
            if (checkCode(code[i]) && checkLine(businessLine[i]) && isActive[i])
                mp.push_back({businessLine[i], code[i]});
        
        sort(all(mp));
        vector<string> result;
        iterate(it, mp)
            result.push_back(it.second);

        return result;
    }
};

int main() {
    Solution obj;
    vector<string> code = {"GROCERY15","ELECTRONICS_50","DISCOUNT10"},
                   businessLine = {"grocery","electronics","invalid"};
    vector<bool> isActive = {false,true,true};
    vector<string> res = obj.validateCoupons(code, businessLine, isActive);
    iterate(it, res) cout << it << " ";
    return 0;
}

/*
Problem:
*/