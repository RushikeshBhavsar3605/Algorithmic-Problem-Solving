#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string generateTag(string caption) {
        int idx = 0;
        while (caption[idx] == ' ')
            idx++;

        if (idx >= caption.size())
            return "#";
        string result = "#" + string(1, (char)tolower(caption[idx++]));

        for (; idx < caption.size(); idx++)
            if (caption[idx - 1] == ' ' && caption[idx] != ' ')
                result.push_back(toupper(caption[idx]));
            else if (caption[idx] != ' ')
                result.push_back(tolower(caption[idx]));

        if (result.size() > 100)
            result.resize(100);

        return result;
    }
};
int main() {
    string caption = "Leetcode daily streak achieved";
    Solution obj;
    cout << obj.generateTag(caption);
    return 0;
}

/*
Problem: Generate Tag for Video Caption
*/