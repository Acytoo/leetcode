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
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    bitset<100001> user, zero, one;  // zero: 0 if lose zero, 1 if lose one;;; one: 0 if lose at most 1 and 1 if more
    for (const auto &a : matches) {
      user[a[0]] = 1;
      user[a[1]] = 1;
      if (zero[a[1]] == 1) one[a[1]] = 1;
      zero[a[1]] = 1;
    }
    vector<int> z, o;
    for (int i = 0; i < 100001; ++i)
      if (user[i] == 1) {
        if (zero[i] == 0) z.emplace_back(i);
        else if (one[i] == 0) o.emplace_back(i);
      }
    return {z, o};
  }
};

class Solution_HASH {  // hash map
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int> m;  // user -> lose
    for (const auto a : matches) {
      if (m.count(a[0]) == 0)
        m[a[0]] = 0;
      auto idx = m.find(a[1]);
      if (idx == m.end()) m[a[1]] = 1;
      else ++(idx->second);
    }
    vector<int> z, o;
    for (const auto &[k, v] : m)
      if (v == 0) z.emplace_back(k);
      else if (v == 1) o.emplace_back(k);
    sort(z.begin(), z.end());
    sort(o.begin(), o.end());
    return {z, o};
  }
};

class Solution_MAP {  // RB tree
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> m;  // user -> lose
    for (const auto a : matches) {
      if (m.count(a[0]) == 0)
        m[a[0]] = 0;
      map<int,int>::iterator idx = m.find(a[1]);
      if (idx == m.end()) m[a[1]] = 1;
      else ++(idx->second);
    }
    vector<int> z, o;
    for (const auto &[k, v] : m)
      if (v == 0) z.emplace_back(k);
      else if (v == 1) o.emplace_back(k);
    return {z, o};
  }
};

int main() {
  Solution s;
  
  return 0;
}
