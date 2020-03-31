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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>>& A) {
    const int m = A.size(), n = A[0].size();
    vector<vector<int>> res (n, vector<int> (m));
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j)
        res[i][j] = A[j][i];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
