#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
// Given a collection of distinct integers, return all possible permutations.
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  // solution 1:
  vector<vector<int>> permute1(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> avaliable(nums.size(), true);
    dfs1(nums, res, path, avaliable);
    return res;
  }
  void dfs1(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& avaliable) {
    int end = nums.size();
    if (end == path.size()) {
      res.push_back(path);
      return;
    }

    for (int i=0; i < end; ++i) {
      if (avaliable[i]) {
        avaliable[i] = false;
        path.push_back(nums[i]);
        dfs1(nums, res, path, avaliable);
        path.pop_back();
        avaliable[i] = true;
      }
    }
  }
  // solution 2
  vector<vector<int>> permute2(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path(nums.size());
    vector<bool> avaliable(nums.size(), true);
    dfs2(nums, res, path, avaliable, 0);
    return res;
  }
  void dfs2(const vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& avaliable, int pos) {
    int end = nums.size();
    if (end == pos) {
      res.push_back(path);
      return;
    }

    for (int i=0; i < end; ++i) {
      if (avaliable[i]) {
        avaliable[i] = false;
        path[pos] = nums[i];
        dfs2(nums, res, path, avaliable, pos+1);
        avaliable[i] = true;
      }
    }
  }

  // solution 3: enumerate positions
  // solution 4: swap

};

int main() {
  Solution s;
  vector<int> a = {1,2,3};
  vector<vector<int>> res = s.permute(a);
  for (auto row : res) {
    for (auto col : row)
      cout << col << " ";
    cout << endl;
  }
  return 0;
}
