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
    bool checkVowels(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        
        return false;
    }

    bool checkConsonant(char ch) {
        if (isalpha(ch) && !checkVowels(ch))
            return true;
        
        return false;
    }

  public:
    bool isValid(string word) {
        if (word.size() < 3)
            return false;

        bool vowel = false;
        bool consonant = false;

        loop(i, 0, word.size()) {
            if (('0' <= word[i] && word[i] <= '9') ||
                ('a' <= word[i] && word[i] <= 'z') ||
                ('A' <= word[i] && word[i] <= 'Z')) {
                if (checkVowels(word[i]))
                    vowel = true;
                
                if (checkConsonant(word[i]))
                    consonant = true;
            } else
                return false;
        }

        return vowel && consonant;
    }
};

int main() {
    Solution obj;
    cout << obj.isValid("234Adas") << endl;
    cout << obj.isValid("b3") << endl;
    cout << obj.isValid("a3$e") << endl;
    return 0;
}

/*
Problem: Valid Word
*/