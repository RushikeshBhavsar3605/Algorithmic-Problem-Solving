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

class Node {
  public:
    int key, value;
    Node *prev, *next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = next = NULL;
    }
};

void insertAtHead(Node *&head, Node *&newNode) {
    Node *nextNode = head->next;
    head->next = newNode;
    newNode->prev = head;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

void deleteNode(Node *&node) {
    Node *prevNode = node->prev;
    Node *nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

class LRUCache {
  public:
    unordered_map<int, Node *> mp;
    Node *head, *tail;
    int size;

    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        deleteNode(mp[key]);
        insertAtHead(head, mp[key]);
        return mp[key]->value;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end() && mp.size() == size) {
            Node *lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
            delete lru;
        } else if (mp.find(key) != mp.end()) {
            Node *old = mp[key];
            deleteNode(old);
            mp.erase(key);
            delete old;
        }

        Node *newNode = new Node(key, value);
        insertAtHead(head, newNode);
        mp[key] = newNode;
    }
};

int main() {
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}

/*
Problem: LRU Cache
*/