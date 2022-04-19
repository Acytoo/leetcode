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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto a : nums) ++m[a];
    vector<pair<int, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), [] (const auto &a, const auto &b) {
      return a.second > b.second;
    });
    vector<int> res;
    res.reserve(k);
    while (--k >= 0) res.emplace_back(vec[k].first);
    return res;
  }
};

class Solution_OLD {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto i: nums) {
      auto it = m.find(i);
      if (it == m.end())
        m[i] = 1;
      else
        ++(it->second);
    }
    vector<pair<int, int>> tmp;
    for (auto i: m)
      tmp.emplace_back(move(i));

    sort(tmp.begin(), tmp.end(), [=](const pair<int, int>& a, const pair<int, int>& b) {
      return a.second > b.second;
    });
    vector<int> res(k);
    int i=0;
    auto it = tmp.begin();
    while (i < k) {
      res[i] = it->first;
      ++i;
      ++it;
    }
    return res;
  }
};


int main() {
  Solution s;

  return 0;
}
