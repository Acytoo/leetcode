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
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    set<vector<int>> s;
    const int n = nums.size();
    vector<int> cur;
    function<void(int)> helper =
        [&] (int idx) {
          if (idx >= n) {
            if (cur.size() >= 2) s.insert(cur);
            return ;
          }
          for (int i = idx; i < n; ++i)
            if (cur.empty() || nums[i] >= cur.back()) {
              cur.emplace_back(nums[i]);
              if (cur.size() >= 2) s.insert(cur);
              helper(i + 1);
              cur.pop_back();
            }
        };
    helper(0);
    return {s.begin(), s.end()};
  }
};

int main() {
  Solution s;
  
  return 0;
}
