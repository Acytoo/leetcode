#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>
#include <list>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
constexpr int kMaxTweets = 10;
class Twitter {
 public:
  /** Initialize your data structure here. */
  Twitter() {
    time_ = 0;
    user_tweets_.clear();
    user_follows_.clear();
    // user_follows_.reserve(10);
    // user_tweets_.reserve(10);
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    auto& tweets = user_tweets_[userId];
    if (tweets.size() == kMaxTweets)
      tweets.pop_front();
    tweets.emplace_back(++time_, tweetId);
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> res;
    vector<pair<int, int>> feed (user_tweets_[userId].begin(), user_tweets_[userId].end()); // pairs
    for (int uid: user_follows_[userId])
      feed.insert(feed.end(), user_tweets_[uid].begin(), user_tweets_[uid].end());
    sort(feed.rbegin(), feed.rend());  // new tweets first
    for (int i=0, stop=min(kMaxTweets, (int)feed.size()); i<stop; ++i)
      res.push_back(feed[i].second);
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId) {
    if (followeeId == followerId)
      return ;
    // cout << user_follows_[followerId].size() << endl;
    // user_follows_[followerId].insert(1);
    user_follows_[followerId].insert(followeeId);
    // cout << "ad" << endl;
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followeeId == followerId)
      return ;
    user_follows_[followerId].erase(followeeId);
  }
 private:
  int time_;
  unordered_map<int, deque<pair<int, int>>> user_tweets_;
  // unordered_map<int, vector<int>> user_follows_;
  unordered_map<int, unordered_set<int>> user_follows_;
};

int main() {
  Twitter* twitter = new Twitter();
  twitter->postTweet(1, 5);
  twitter->postTweet(1, 6);
  twitter->postTweet(1, 7);
  vector<int> tmp = twitter->getNewsFeed(1);
  for (int i: tmp)
    cout << i << " ";
  cout << endl;

  twitter->follow(1, 2);
  twitter->postTweet(2, 10);
  twitter->postTweet(2, 11);
  tmp = twitter->getNewsFeed(1);
  for (int i: tmp)
    cout << i << " ";
  cout << endl;
  delete twitter;
  return 0;
}
