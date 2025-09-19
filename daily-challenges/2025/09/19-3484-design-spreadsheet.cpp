#include <bits/stdc++.h>
using namespace std;

// Type Aliases
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long long>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>

// STL Shortcuts
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define uniq(v)                                                                                                        \
    sort(all(v));                                                                                                      \
    v.erase(unique(all(v)), v.end())

// Unordered Containers
#define umap unordered_map
#define uset unordered_set

// Loop Macros (readable & consistent)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define revloop(i, a, b) for (int i = a; i >= b; i--)
#define iterate(x, a) for (auto &x : a)

// Min/Max Updaters (more explicit names)
#define updateMin(a, b) (a = min(a, b))
#define updateMax(a, b) (a = max(a, b))

// Debug Macros (OJ-safe: outputs to cerr)
#define dump(a)                                                                                                        \
    do {                                                                                                               \
        cerr << #a << " = ";                                                                                           \
        for (auto &x : a)                                                                                              \
            cerr << x << " ";                                                                                          \
        cerr << "\n";                                                                                                  \
    } while (0)
#define dump2D(a)                                                                                                      \
    do {                                                                                                               \
        cerr << #a << ":\n";                                                                                           \
        for (auto &row : a) {                                                                                          \
            for (auto &x : row)                                                                                        \
                cerr << x << " ";                                                                                      \
            cerr << "\n";                                                                                              \
        }                                                                                                              \
    } while (0)

/* Approach 1 (Naive): */
class Spreadsheet {
  private:
    // Fixed grid: rows x 26 (columns A..Z), initialized to 0 (unset => 0 semantics)
    vvi mat;

    // Parse a cell like "B10" into 0-based indices: (rowIndex, colIndex)
    // - Column: first char 'A'..'Z'
    // - Row: numeric suffix, 1-indexed in input -> convert to 0-indexed for storage
    pii parseCell(string &s) {
        int col = s[0] - 'A';            // 'A'->0, 'B'->1, ..., 'Z'->25
        int row = stoi(s.substr(1)) - 1; // parse full numeric tail, then 1-based -> 0-based

        // NOTE: No bounds checks here; caller must ensure 0 <= row < mat.size() and 0 <= col < 26
        // In production: assert(0 <= col && col < 26 && 0 <= row && row < (int)mat.size());

        return {row, col};
    }

    // Evaluate a token that is either:
    // - a non-negative integer literal (e.g., "42"), or
    // - a cell reference like "C7"
    // Returns the integer value (cell read from mat, default 0 due to initialization)
    int valueOf(string &tok) {
        if (isdigit(tok[0]))
            return stoi(tok); // numeric literal

        pii c = parseCell(tok); // cell reference
        int row = c.ff;
        int col = c.ss;

        // Assumes within bounds given problem constraints
        return mat[row][col];
    }

  public:
    // Construct a sheet with `rows` rows and 26 columns, all initialized to 0
    Spreadsheet(int rows) {
        mat.resize(rows, vi(26, 0));
    }

    // Set a specific cell (e.g., "A1") to a concrete integer value
    void setCell(string cell, int value) {
        pii c = parseCell(cell);
        int row = c.ff;
        int col = c.ss;
        mat[row][col] = value; // O(1) write
    }

    // Reset a specific cell back to 0 (matches "unset reads as 0" semantics)
    void resetCell(string cell) {
        pii c = parseCell(cell);
        int row = c.ff;
        int col = c.ss;
        mat[row][col] = 0; // O(1) write; no dependency tracking in this problem
    }

    // Evaluate a formula strictly of the form "=X+Y"
    // where X and Y are each either an integer or a cell reference.
    int getValue(string formula) {
        // Find the '+' separating the two operands; skip the leading '='
        int plusPos = formula.find('+');
        string a = formula.substr(1, plusPos - 1); // operand X between '=' and '+'
        string b = formula.substr(plusPos + 1);    // operand Y after '+'
        // NOTE: No trimming; assumes inputs are well-formed with no spaces per problem spec.
        // In production: validate plusPos != npos and operands non-empty.

        // Evaluate each operand and sum
        return valueOf(a) + valueOf(b);
    }
};

int main() {
    Spreadsheet obj(3);
    cout << obj.getValue("=5+7") << endl;
    obj.setCell("A1", 10);
    cout << obj.getValue("=A1+6") << endl;
    obj.setCell("B2", 15);
    cout << obj.getValue("=A1+B2") << endl;
    obj.resetCell("A1");
    cout << obj.getValue("=A1+B2") << endl;
}

/*
Problem: Design Spreadsheet
*/