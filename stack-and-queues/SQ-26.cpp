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

class StockSpanner {
  public:
    // stack of {price, day_index}, monotonically decreasing by price
    stack<pair<int, int>> st;
    int size;

    // initialize day counter
    StockSpanner() { size = 1; }

    int next(int price) {
        // remove all previous days with price <= current
        while (!st.empty() && st.top().first <= price)
            st.pop();

        // if stack empty, span stretches back to day 1 (index 0)
        int index = 0;
        if (!st.empty())
            index = st.top().second;

        // record current price with its day index
        st.push(make_pair(price, size));

        // span = days since last higher price
        return (size++) - index;
    }
};

int main() {
    StockSpanner *obj = new StockSpanner();
    cout << obj->next(100) << endl;
    cout << obj->next(80) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(70) << endl;
    cout << obj->next(60) << endl;
    cout << obj->next(75) << endl;
    cout << obj->next(85) << endl;
    return 0;
}

/*
Problem: Online Stock Span
*/