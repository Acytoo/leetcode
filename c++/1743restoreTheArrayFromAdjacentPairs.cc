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
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> res (adjacentPairs.size() + 1);
    unordered_map<int, int> nums;
    unordered_map<int, vector<int>> g;
    set<int> visited;
    for (const auto &a: adjacentPairs) {
      ++nums[a[0]];
      ++nums[a[1]];
      g[a[0]].emplace_back(a[1]);
      g[a[1]].emplace_back(a[0]);
    }
    vector<int> head_tail;
    for (auto &[key, val]: nums) {
      if (val == 1) head_tail.emplace_back(key);
      if (head_tail.size() == 2) break;
    }
    res.front() = head_tail.front();
    res.back() = head_tail.back();
    visited.insert(res.front());
    visited.insert(res.back());
    for (int i = 0, n = adjacentPairs.size() - 1; i < n; ++i) {
      for (int next: g[res[i]])
        if (visited.count(next) == 0) {
          res[i + 1] = next;
          visited.insert(next);
        }
    }
    return res;
  }
};

class Solution_WA {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> res (adjacentPairs.size() + 1);
    unordered_map<int, int> nums, adj1, adj2;
    for (const auto &a: adjacentPairs) {
      ++nums[a[0]];
      ++nums[a[1]];
      if (adj1.count(a[0]))
        adj1[a[1]] = a[0];
      else
        adj1[a[0]] = a[1];
    }
    vector<int> head_tail;
    for (auto &[key, val]: nums) {
      if (val == 1) head_tail.emplace_back(key);
      if (head_tail.size() == 2) break;
    }
    if (adj1.count(head_tail[0]))
      res.front() = head_tail[0];
    else
      res.front() = head_tail[1];
    for (int i = 0, n = adjacentPairs.size(); i < n; ) {
      if (adj1.count(res[i])) {
        res[++i] = adj1[res[i]];
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
