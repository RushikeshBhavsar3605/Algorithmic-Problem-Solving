#include "template.hpp"

class Node {
  public:
    int value;
    vector<Node *> next;

    Node(int val, int level) {
        value = val;
        next.resize(level + 1, nullptr);
    }

    int level() const { return sz(next) - 1; }
};

class SkipList {
  private:
    static const int MAX_LEVEL = 16;
    static constexpr double P = 0.5;

    Node *head;
    int currentLevel;

    int randomLevel() {
        int level = 0;

        while (level < MAX_LEVEL && (rand() & 1))
            level++;

        return level;
    }

  public:
    SkipList() {
        currentLevel = 0;
        head = new Node(INT_MIN, MAX_LEVEL);
    }

    bool search(int key) {
        Node *curr = head;

        for (int level = currentLevel; level >= 0; level--) {
            while (curr->next[level] && curr->next[level]->value < key)
                curr = curr->next[level];
        }

        curr = curr->next[0];

        return curr && curr->value == key;
    }

    void insert(int key) {
        Node *update[MAX_LEVEL + 1];
        Node *curr = head;

        for (int level = currentLevel; level >= 0; level--) {
            while (curr->next[level] && curr->next[level]->value < key)
                curr = curr->next[level];

            update[level] = curr;
        }

        curr = curr->next[0];
        if (curr && curr->value == key)
            return;

        int newLevel = randomLevel();
        if (newLevel > currentLevel) {
            for (int level = currentLevel + 1; level <= newLevel; level++)
                update[level] = head;

            currentLevel = newLevel;
        }

        Node *newNode = new Node(key, newLevel);

        for (int level = 0; level <= newLevel; level++) {
            newNode->next[level] = update[level]->next[level];
            update[level]->next[level] = newNode;
        }
    }

    void erase(int key) {
        Node *update[MAX_LEVEL + 1];
        Node *curr = head;

        for (int level = currentLevel; level >= 0; level--) {
            while (curr->next[level] && curr->next[level]->value < key)
                curr = curr->next[level];

            update[level] = curr;
        }

        curr = curr->next[0];
        if (!curr || curr->value != key)
            return;

        for (int level = 0; level <= currentLevel; level++) {
            if (update[level]->next[level] != curr)
                break;

            update[level]->next[level] = curr->next[level];
        }

        delete curr;

        while (currentLevel > 0 && head->next[currentLevel] == nullptr)
            currentLevel--;
    }

    void prettyPrint() {
        std::cout << "--- Skip List Visualization ---\n";

        std::vector<Node *> baseNodes;
        Node *curr = head->next[0];
        while (curr != nullptr) {
            baseNodes.push_back(curr);
            curr = curr->next[0];
        }

        std::vector<int> nodeWidths;
        std::vector<std::string> nodeStrings;
        for (Node *n : baseNodes) {
            std::string s = "[" + std::to_string(n->value) + "]";
            nodeStrings.push_back(s);
            nodeWidths.push_back(s.length());
        }

        for (int i = currentLevel; i >= 0; i--) {
            std::string levelPrefix = "Level " + std::to_string(i) + ": ";
            std::cout << levelPrefix;

            Node *activeNode = head->next[i];

            for (size_t idx = 0; idx < baseNodes.size(); ++idx) {
                Node *baseNode = baseNodes[idx];
                int width = nodeWidths[idx];

                if (activeNode != nullptr && baseNode == activeNode) {
                    std::string valStr = std::to_string(activeNode->value);
                    int padLeft = (width - valStr.length()) / 2;
                    int padRight = width - valStr.length() - padLeft;

                    std::cout << std::string(padLeft, '-') << valStr << std::string(padRight, '-');
                    activeNode = activeNode->next[i];
                } else {
                    std::cout << std::string(width, '-');
                }

                if (idx < baseNodes.size() - 1) {
                    std::cout << "-";
                }
            }
            std::cout << "\n";

            if (i > 0) {
                std::cout << std::string(levelPrefix.length(), ' ');

                activeNode = head->next[i];
                for (size_t idx = 0; idx < baseNodes.size(); ++idx) {
                    Node *baseNode = baseNodes[idx];
                    int width = nodeWidths[idx];

                    if (activeNode != nullptr && baseNode == activeNode) {
                        int pipePos = width / 2;
                        std::cout << std::string(pipePos, ' ') << "|" << std::string(width - pipePos - 1, ' ');
                        activeNode = activeNode->next[i];
                    } else {
                        std::cout << std::string(width, ' ');
                    }

                    if (idx < baseNodes.size() - 1)
                        std::cout << " ";
                }
                std::cout << "\n";
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    SkipList sl;
    sl.insert(10);
    sl.insert(20);
    sl.insert(15);
    sl.insert(7);
    sl.insert(35);
    sl.insert(25);

    sl.prettyPrint();

    cout << "\nSearch 15: " << (sl.search(15) ? "Found" : "Not Found") << '\n';

    cout << "Search 100: " << (sl.search(100) ? "Found" : "Not Found") << '\n';

    sl.erase(20);

    cout << "\nAfter deleting 20:\n";
    sl.prettyPrint();

    return 0;
}

/*
Problem:
*/