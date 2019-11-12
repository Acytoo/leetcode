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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Bit manipulation
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    int nums_size = nums.size();
    for (int num=0, stop=1<<nums_size; num < stop; ++num) {
      vector<int> path;
      for (int i=0; i < nums_size; ++i) {
        if (num >> i & 1)
          path.push_back(nums[i]);
      }
      res.push_back(path);
    }
    return res;
  }
};

// No duplicates: Set

class Solution1 {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, res, path, 0);
    return res;
  }

  void dfs(const vector<int>& nums, vector<vector<int>>& res,
           vector<int>& path, int pos) {
    res.push_back(path);        // [] is included
    for (int i=pos, stop=nums.size(); i < stop; ++i) {
      path.push_back(nums[i]);
      dfs(nums, res, path, i+1);
      path.pop_back();
    }
  }
};

int main() {
  Solution s;
  // So easy that I even don't want to run it locally.
  return 0;
}
