class Twitter {
public:
    int count;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count, tweetId});
        if(tweetMap[userId].size()>10) {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
        count--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followMap[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        for(int followeeId: followMap[userId]){
            if(tweetMap.find(followeeId)==tweetMap.end()) continue;
            int idx = tweetMap[followeeId].size()-1;
            auto [time, tweetId] = tweetMap[followeeId][idx];
            minHeap.push({time, tweetId, followeeId, idx});
        }
        while(res.size()<10 && !minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();
            int time = curr[0];
            int tweetId = curr[1];
            int followeeId = curr[2];
            int idx = curr[3];

            res.push_back(tweetId);
            if(idx>0){
                idx--;
                auto [prevTime, prevTweetId] = tweetMap[followeeId][idx];
                minHeap.push({prevTime, prevTweetId, followeeId, idx});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followMap[followerId].count(followeeId)){
            followMap[followerId].erase(followeeId);
        }
    }
};
