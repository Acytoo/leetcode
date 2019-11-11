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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Bit manipulation
class Solution{
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    for (int number = 0, t = 1; number < 512; ++number) { // 512 = 1 << 9
      vector<int> path;
      int sum = 0;
      for (int i=0; i< 9; ++i) {
        if (number & (1 << i)) {
          path.push_back(i+1);
          sum += (i+1);
        }
      }
      if (sum == n && path.size() == k)
        res.push_back(std::move(path));
    }
    return res;
  }
};

class Solution1 {
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(1, k, n, res, path);
    return res;
  }
  void dfs(int start, int k, int n,
            vector<vector<int>>& res, vector<int>& path) {
    if (!k) {
      if (!n)                   // sum = 0
        res.push_back(path);
      return;                   // impossible combinamtion
    }

    for (int i=start; i+k <= 10; ++i) { // 9 - i + 1 >= k ---> i, i+1, ..., 9 has at least k numbers
      if (n < i) return;        // impossible
      path.push_back(i);
      dfs(i+1, k-1, n-i, res, path);
      path.pop_back();
    }
  }
};

int main() {
  Solution s;
  for (auto i : s.combinationSum3(3, 9)) {
    for (auto j : i)
      cout << j << " ";
    cout << endl;
  }
  return 0;
}
