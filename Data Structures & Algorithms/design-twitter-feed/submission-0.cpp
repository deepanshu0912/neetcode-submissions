class Twitter {
public:
    int timer = 0;

    map<int, vector<pair<int,int>>> tweet;
    map<int, set<int>> fol;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({timer, tweetId});
        timer++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        // user's own tweets
        for (auto t : tweet[userId]) {
            pq.push(t);
        }

        // followed users' tweets
        for (auto f : fol[userId]) {
            for (auto t : tweet[f]) {
                pq.push(t);
            }
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            fol[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
    }
};