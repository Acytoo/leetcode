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
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    vector<int> res(N), count(N);
    vector<vector<int>> tree(N);
    for (auto &edge : edges) {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }
    helper(tree, 0, -1, count, res);
    helper2(tree, 0, -1, count, res);
    return res;
  }
  void helper(vector<vector<int>>& tree, int cur, int pre, vector<int>& count, vector<int>& res) {
    for (int i : tree[cur]) {
      if (i == pre) continue;
      helper(tree, i, cur, count, res);
      count[cur] += count[i];
      res[cur] += res[i] + count[i];
    }
    ++count[cur];
  }
  void helper2(vector<vector<int>>& tree, int cur, int pre, vector<int>& count, vector<int>& res) {
    for (int i : tree[cur]) {
      if (i == pre) continue;
      res[i] = res[cur] - count[i] + count.size() - count[i];
      helper2(tree, i, cur, count, res);
    }
  }
};

class Solution1 {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

  }
};

int main() {
  Solution s;
  
  return 0;
}
