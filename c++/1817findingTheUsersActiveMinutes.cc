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
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int> res (k);
    unordered_map<int, unordered_set<int>> m;
    for (const auto &log : logs)
      m[log[0]].insert(log[1]);
    for (const auto &[_, v] : m)
      ++res[v.size() - 1];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
