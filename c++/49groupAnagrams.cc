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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<int>> m;
    for (int i=0, stop=strs.size(); i<stop; ++i) {
      string bk (strs[i]);
      sort(bk.begin(), bk.end());
      m[bk].push_back(i);
    }
    for (auto& i: m) {
      res.push_back({});
      for (auto j: i.second)
        res.back().emplace_back(move(strs[j]));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
