#include "template.hpp"

/* Approach 1 (Sorting):
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        umap<string, nvec_t<string, 1>> groups;

        iterate(str, strs) {
            string key = str;
            sort(all(key));
            groups[key].pb(str);
        }

        nvec_t<string, 2> res;

        for (auto &[_, group] : groups)
            res.pb(group);

        return res;
    }
};
*/

/* Approach 2 (Hashing): */
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        umap<string, nvec_t<string, 1>> groups;

        iterate(str, strs) {
            vi freq(26, 0);
            iterate(ch, str)
                freq[ch - 'a']++;

            string key;
            iterate(count, freq)
                key += "#" + to_string(count);

            groups[key].pb(str);
        }

        nvec_t<string, 2> res;

        for (auto &[_, group] : groups)
            res.pb(group);

        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution obj;
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = obj.groupAnagrams(v);
    print(res);
    v = {""};
    res = obj.groupAnagrams(v);
    print(res);
    v = {"a"};
    res = obj.groupAnagrams(v);
    print(res);
    return 0;
}

/*
Problem: Group Anagrams
*/