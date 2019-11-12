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
// sort first
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, res, path);
    return res;
  }
  void dfs(const vector<int>& candidates, int target,
           int idx, vector<vector<int>>& res, vector<int>& path) {
    if (target == 0) {
      res.push_back(path);
      return;
    }
    for (int i=idx, stop = candidates.size(); i < stop; ++i) {
      if (target < candidates[i]) return;
      path.push_back(candidates[i]);
      dfs(candidates, target-candidates[i], i, res, path);
      path.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> a = {1,3,5,6,7};
  for (auto i : s.combinationSum(a, 10)) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
