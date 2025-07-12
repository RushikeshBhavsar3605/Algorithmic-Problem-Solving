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

class heap {
  public:
    vi tree;

    void insert(int val) {
        tree.push_back(val);
        int index = tree.size() - 1;

        while (index) {
            int parent = (index - 1) / 2;

            if (tree[parent] < tree[index]) {
                swap(tree[parent], tree[index]);
                index = parent;
            } else
                return;
        }
    }

    void remove() {
        int size = tree.size();
        if (size == 0)
            return;

        tree[0] = tree[size - 1];
        tree.pop_back();
        size--;

        int index = 0;
        while (index < size) {
            int largest = index;
            int leftChild = index * 2 + 1;
            int rightChild = index * 2 + 2;

            if (leftChild < size && tree[largest] < tree[leftChild])
                largest = leftChild;
            if (rightChild < size && tree[largest] < tree[rightChild])
                largest = rightChild;

            if (largest != index) {
                swap(tree[index], tree[largest]);
                index = largest;
            } else
                break;
        }
    }

    void print() {
        loop(i, 0, tree.size()) cout << tree[i] << " ";
        cout << endl;
    }
};

void heapify(vi &tree, int index, int length) {
    int largest = index;
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;

    if (leftChild < length && tree[largest] < tree[leftChild])
        largest = leftChild;
    if (rightChild < length && tree[largest] < tree[rightChild])
        largest = rightChild;

    if (largest != index) {
        swap(tree[index], tree[largest]);
        heapify(tree, largest, length);
    }
}

int main() {
    heap h;
    h.insert(30);
    h.insert(20);
    h.insert(40);
    h.insert(50);
    h.print();
    h.remove();
    h.print();
    h.remove();
    h.print();

    cout << endl << endl;

    vi v = {54, 53, 55, 52, 50};
    revloop(i, v.size() / 2 - 1, 0) heapify(v, i, v.size());
    iterate(it, v) cout << it << " ";
    return 0;
}

/*
Problem:
*/
/*
Insertion
30 ->      30 -> 30    ->    40    ->   40    ->    40   ->   50
           /     /  \        /  \       /  \        /  \      /  \
          20    20   40     20  30     20  30      50  30    40   30
                                      /           /         /
                                     50          20        20

Deletion
    50     ->     20     ->   20    ->  40   ->   30    ->   30
   /  \          /  \        /  \      /  \      /  \       /
  40  30        40  30      40  30    20  30    20  40     20
 /             /
20            50
*/