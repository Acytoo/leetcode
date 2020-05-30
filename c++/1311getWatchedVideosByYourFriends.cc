#include <iostream>
#include <sstream>
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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                        vector<vector<int>>& friends, int id, int level) {
    unordered_set<int> s {id};
    bitset<101> visited;
    visited[id] = 1;
    while (level--) {
      unordered_set<int> tmp;
      for (const int p: s) {
        for (const int f: friends[p])
          if (!visited[f]) {
            tmp.insert(f);
            visited[f] = 1;
          }
      }
      swap(tmp, s);
    }
    map<string, int> m;
    for (const int p: s)
      for (const string &vid: watchedVideos[p])
        ++m[vid];
    vector<pair<int, string>> fre_vid;
    fre_vid.reserve(m.size());
    for (const auto &kv: m) fre_vid.emplace_back(kv.second, kv.first);
    sort(fre_vid.begin(), fre_vid.end());
    vector<string> res;
    res.reserve(m.size());
    for (const auto &kv: fre_vid) res.emplace_back(move(kv.second));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
