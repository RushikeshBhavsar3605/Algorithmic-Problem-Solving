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

class TweetNode {
  public:
    int tweetId;
    int timestamp;
    TweetNode *next;

    // Represents a single tweet node with ID, time, and link to next tweet
    TweetNode(int id, int time) {
        tweetId = id;
        timestamp = time;
        next = NULL;
    }
};

class Twitter {
  public:
    unordered_map<int, set<int>> userFolloweesMap; // Maps user to their followees
    unordered_map<int, TweetNode *> userTweetsMap; // Maps user to head of their tweet list
    int currentTime;

    Twitter() {
        currentTime = 0;
    }

    // Insert new tweet at the head of user's tweet list
    void postTweet(int userId, int tweetId) {
        TweetNode *newTweet = new TweetNode(tweetId, currentTime++);
        newTweet->next = userTweetsMap[userId];
        userTweetsMap[userId] = newTweet;
    }

    // Return up to 10 most recent tweets from user and followees
    vi getNewsFeed(int userId) {
        struct compare {
            bool operator()(const TweetNode *a, const TweetNode *b) {
                return a->timestamp < b->timestamp; // max-heap: latest tweets first
            }
        };
        
        priority_queue<TweetNode *, vector<TweetNode *>, compare> maxHeap;
        set<int> usersToFetch = userFolloweesMap[userId];
        usersToFetch.insert(userId); // include self

        // Push head tweet of each user into heap
        iterate(followeeId, usersToFetch)
            if (userTweetsMap.count(followeeId) && userTweetsMap[followeeId] != NULL)
                maxHeap.push(userTweetsMap[followeeId]);

        vi newsFeed;
        // Extract up to 10 latest tweets across all users
        while (!maxHeap.empty() && newsFeed.size() < 10) {
            TweetNode *topTweet = maxHeap.top();
            maxHeap.pop();
            newsFeed.push_back(topTweet->tweetId);

            // Push next tweet from same user, if exists
            if (topTweet->next != NULL)
                maxHeap.push(topTweet->next);
        }

        return newsFeed;
    }

    // Add followee to follower's set
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            userFolloweesMap[followerId].insert(followeeId);
    }

    // Remove followee from follower's set
    void unfollow(int followerId, int followeeId) {
        userFolloweesMap[followerId].erase(followeeId);
    }
};

int main() {
    Twitter *obj = new Twitter();
    obj->postTweet(1, 5);
    vi v = obj->getNewsFeed(1);
    iterate(it, v) cout << it << " ";
    cout << endl;
    obj->follow(1, 2);
    obj->postTweet(2, 6);
    v = obj->getNewsFeed(1);
    iterate(it, v) cout << it << " ";
    cout << endl;
    obj->unfollow(1, 2);
    v = obj->getNewsFeed(1);
    iterate(it, v) cout << it << " ";
    cout << endl;
    return 0;
}

/*
Problem: Design Twitter
*/

/*
 */