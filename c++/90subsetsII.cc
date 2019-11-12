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

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    dfs(nums, res, path, 0);
    return res;
  }

  void dfs(const vector<int>& nums, vector<vector<int>>& res,
           vector<int>& path, int pos) {
    res.push_back(path);        // [] is included
    for (int i=pos, stop=nums.size(); i < stop; ++i) {
      if (pos < i && nums[i-1] == nums[i])
        continue;
      path.push_back(nums[i]);
      dfs(nums, res, path, i+1);
      path.pop_back();
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
