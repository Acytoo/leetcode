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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> m;
    for (int i=0, stop=groupSizes.size(); i<stop; ++i)
      m[groupSizes[i]].push_back(i);

    vector<vector<int>> res;
    for (auto each_pair: m) {
      // group size = each_pair.first, each member's id is in each_pair.second(vector)
      int idx = 0, n = each_pair.second.size(), group_cnt = n / each_pair.first;
      for (int i=0; i<group_cnt; ++i) {
        vector<int> cur_group (each_pair.first);
        for (int j=0; j<each_pair.first; ++j)
          cur_group[j] = each_pair.second[idx++];
        res.emplace_back(cur_group.begin(), cur_group.end());
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {3,3,3,3,3,1,3};
  a = {2,1,3,3,3,2};
  vector<vector<int>> res = s.groupThePeople(a);
  for (auto i: res) {
    for (auto j: i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}
