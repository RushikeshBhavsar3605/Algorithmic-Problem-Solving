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

/* Approach 1 (Design Data Structure): */
class FoodRatings {
  private:
    // Stores, for each cuisine, a set of (-rating, foodName) pairs, sorted by descending rating then lexicographically
    umap<string, set<pair<int, string>>> cuisineRatings;
    // Stores the current rating for each food
    umap<string, int> foodRating;
    // Maps each food to its cuisine
    umap<string, string> foodToCuisine;

  public:
    // Initialize mappings and sets with input data
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        loop(i, 0, sz(foods)) {
            // Insert into cuisine's set: use negative rating for descending order, break ties by name
            cuisineRatings[cuisines[i]].insert({-ratings[i], foods[i]});
            foodRating[foods[i]] = ratings[i];
            foodToCuisine[foods[i]] = cuisines[i];
        }
    }

    // Change rating for a food, update all related structures
    void changeRating(string food, int newRating) {
        auto &cuisine = foodToCuisine[food];
        int oldRating = foodRating[food];
        // Erase old pair, insert new rating (maintains order in set)
        cuisineRatings[cuisine].erase({-oldRating, food});
        cuisineRatings[cuisine].insert({-newRating, food});

        foodRating[food] = newRating;
    }

    // Return the food with highest rating for given cuisine (lex smallest for ties)
    string highestRated(string cuisine) {
        // .begin() gives the highest-rated food due to ordering
        return (cuisineRatings[cuisine].begin())->ss; // FIX: should be ->second
    }
};

int main() {
    vector<string> f = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> c = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vi r = {9, 12, 8, 15, 14, 7};
    FoodRatings obj(f, c, r);
    cout << obj.highestRated("korean") << endl;
    cout << obj.highestRated("japanese") << endl;
    obj.changeRating("sushi", 16);
    cout << obj.highestRated("japanese") << endl;
    obj.changeRating("ramen", 16);
    cout << obj.highestRated("japanese") << endl;
}

/*
Problem: Design a Food Rating System
*/