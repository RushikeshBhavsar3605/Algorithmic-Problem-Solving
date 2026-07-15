#include "template.hpp"

class Node {
  public:
    int key, value;
    Node *prev, *next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

/* Approach (Linked List + Hashing): */
class LRUCache {
  private:
    int capacity;
    umap<int, Node *> mp;
    Node *head, *tail;

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

  public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        Node *node = mp[key];
        remove(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node *node = mp[key];
            node->value = value;
            remove(node);
            insertFront(node);
            return;
        }

        if (sz(mp) == capacity) {
            Node *lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete (lru);
        }

        Node *node = new Node(key, value);
        insertFront(node);
        mp[key] = node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LRUCache obj(2);
    obj.put(1, 1);
    obj.put(2, 2);
    print(obj.get(1));
    obj.put(3, 3);
    print(obj.get(2));
    obj.put(4, 4);
    print(obj.get(1));
    print(obj.get(3));
    print(obj.get(4));
    return 0;
}

/*
Problem: LRU Cache
*/