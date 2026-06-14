#include "template.hpp"

/* Approach (Naive): */
class Solution {
  public:
    string mapWordWeights(vector<string> &words, vector<int> &weights) {
        string res;

        iterate(word, words) {
            int sum = 0;
            iterate(ch, word) sum += weights[ch - 'a'];

            sum %= 26;
            res.pb('z' - sum);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    nvec_t<string, 1> w1 = {"abcd", "def", "xyz"};
    vi w2 = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};
    auto res = obj.mapWordWeights(w1, w2);
    print(res);
    w1 = {"a", "b", "c"};
    w2 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    res = obj.mapWordWeights(w1, w2);
    print(res);
    w1 = {"abcd"};
    w2 = {7, 5, 3, 4, 3, 5, 4, 9, 4, 2, 2, 7, 10, 2, 5, 10, 6, 1, 2, 2, 4, 1, 3, 4, 4, 5};
    res = obj.mapWordWeights(w1, w2);
    print(res);
    return 0;
}

/*
Problem: Weighted Word Mapping
*/