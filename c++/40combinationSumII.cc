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
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> res;       // Using set
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, res, path);
    return vector<vector<int>>(res.begin(), res.end());
  }
  void dfs(const vector<int>& candidates, int target, int idx,
           set<vector<int>>& res, vector<int>& path) {
    if (target == 0) {
      res.insert(path);
      return;
    }
    for (int i=idx, stop=candidates.size(); i < stop; ++i) {
      if (target < candidates[i]) return;
      path.push_back(candidates[i]);
      dfs(candidates, target-candidates[i], i+1, res, path);
      path.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> a = {1,3,2,4,1,7};
  for (auto i : s.combinationSum2(a, 10)) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
