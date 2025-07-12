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
    int key, value, freq;
    Node *prev, *next;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->freq = 1;
        prev = next = NULL;
    }
};

class DLL {
  public:
    Node *head, *tail; // sentinel head/tail

    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // insert node right after head
    void insertFront(Node *&newNode) {
        Node *nextNode = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }

    // unlink node from list
    void removeNode(Node *&node) {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    bool isEmpty() { return head->next == tail; } // check empty
};

class LFUCache {
  private:
    int capacity, currSize, minFreq;
    unordered_map<int, Node *> keyTable; // key -> node
    unordered_map<int, DLL *> freqTable; // freq -> list of nodes

    // update node freq and relocate in freqTable
    void touch(Node *node) {
        int f = node->freq;
        DLL *oldList = freqTable[f];

        oldList->removeNode(node);
        if (f == minFreq && oldList->isEmpty())
            ++minFreq;

        node->freq++;
        if (!freqTable.count(node->freq))
            freqTable[node->freq] = new DLL();

        freqTable[node->freq]->insertFront(node);
    }

  public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->currSize = 0;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyTable.find(key) == keyTable.end())
            return -1;

        Node *node = keyTable[key]; // hit: bump freq
        touch(node);
        return node->value;
    }

    void put(int key, int value) {
        if (keyTable.count(key)) {
            Node *node = keyTable[key];
            node->value = value; // update value
            touch(node);         // bump freq
        } else {
            if (currSize == capacity) {
                DLL *list = freqTable[minFreq];
                Node *toRemove = list->tail->prev; // LFU node
                list->removeNode(toRemove);

                keyTable.erase(toRemove->key);
                delete toRemove;
                --currSize;
            }

            Node *node = new Node(key, value);
            keyTable[key] = node;
            minFreq = 1; // new node freq=1

            if (!freqTable.count(1))
                freqTable[1] = new DLL();
            freqTable[1]->insertFront(node);

            currSize++;
        }
    }
};

int main() {
    LFUCache *obj = new LFUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}

/*
Problem: LFU Cache
*/