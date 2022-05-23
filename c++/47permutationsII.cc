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
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    bitset<8> used;
    function<void(void)> dfs = [&] () {
      if (cur.size() == n) {
        res.push_back(cur);
        return;
      }
      for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        if (i && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = 1;
        cur.emplace_back(nums[i]);
        dfs();
        cur.pop_back();
        used[i] = 0;
      };
    };
    dfs();
    return res;
  }
};

class Solution_OLD {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> used (n);
    function<void(void)> dfs =
        [&] () {
          if (cur.size() == n) {
            res.push_back(cur);
            return ;
          }
          for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            if (i && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            cur.emplace_back(nums[i]);
            dfs();
            cur.pop_back();
            used[i] = false;
          }
        };
    dfs();
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
