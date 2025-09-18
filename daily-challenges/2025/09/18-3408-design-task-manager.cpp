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
class TaskManager {
  private:
    // Maps each userId -> set of (priority, taskId)
    umap<int, set<pii>> userToTasks;
    // Maps each taskId -> (priority, userId)
    umap<int, pii> taskToUser;
    // Global set of all tasks -> (priority, -taskId) to handle ties consistently
    set<pii> universalTasks;

  public:
    TaskManager(vector<vector<int>> &tasks) {
        iterate(task, tasks) {
            // Insert into user-specific, global, and task lookup structures
            userToTasks[task[0]].insert({-task[2], task[1]});
            taskToUser[task[1]] = {-task[2], task[0]};
            universalTasks.insert({-task[2], -task[1]});
        }
    }

    void add(int userId, int taskId, int priority) {
        // Add task to all 3 data structures
        userToTasks[userId].insert({-priority, taskId});
        taskToUser[taskId] = {-priority, userId};
        universalTasks.insert({-priority, -taskId});
    }

    void edit(int taskId, int newPriority) {
        // Fetch old priority and owner
        int priority = taskToUser[taskId].ff;
        int userId = taskToUser[taskId].ss;

        // Remove old priority entry
        userToTasks[userId].erase({priority, taskId});
        universalTasks.erase({priority, -taskId});

        // Insert with updated priority
        taskToUser[taskId] = {-newPriority, userId};
        userToTasks[userId].insert({-newPriority, taskId});
        universalTasks.insert({-newPriority, -taskId});
    }

    void rmv(int taskId) {
        // Lookup task details
        int priority = taskToUser[taskId].ff;
        int userId = taskToUser[taskId].ss;

        // Remove from all data structures
        userToTasks[userId].erase({priority, taskId});
        taskToUser.erase(taskId);
        universalTasks.erase({priority, -taskId});
    }

    int execTop() {
        // Return userId of highest priority task and remove it
        if (universalTasks.empty())
            return -1;

        int priority = universalTasks.begin()->ff;
        int taskId = -universalTasks.begin()->ss;
        int userId = taskToUser[taskId].ss;

        // Remove executed task from all structures
        taskToUser.erase(taskId);
        userToTasks[userId].erase({priority, taskId});
        universalTasks.erase({priority, -taskId});

        return userId;
    }
};

int main() {
    vvi v = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    TaskManager obj(v);
    obj.add(4, 104, 5);
    obj.edit(102, 8);
    cout << obj.execTop() << endl;
    obj.rmv(101);
    obj.add(5, 105, 15);
    cout << obj.execTop() << endl;
}

/*
Problem: Design Task Manager
*/