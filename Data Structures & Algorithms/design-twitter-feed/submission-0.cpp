class Twitter {
public:
    map<int, vector<int>> friends;
    stack<pair<int, int>> st;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        st.push(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        stack<pair<int, int>> help = st;
        vector<int> ans;
        vector<int> list = friends[userId];
        while(ans.size()<10 && !help.empty()){
            auto it = help.top();
            int user = it.first;
            int tweet = it.second;
            if(user==userId || find(list.begin(), list.end(), user) != list.end())
            {
                ans.push_back(tweet);
            }
            help.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto &v = friends[followerId];
v.erase(remove(v.begin(), v.end(), followeeId), v.end());
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */