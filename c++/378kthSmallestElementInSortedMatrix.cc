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
#include <utility>
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    priority_queue<int> q;
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j) {
        q.push(matrix[i][j]);
        if (q.size() > k) q.pop();
      }
    return q.top();
  }
};

// From Huahua
class Solution_faster {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    const int n = matrix.size();
    long l = matrix[0][0], r = matrix[n-1][n-1] + 1;
    while (l < r) {
      long m = (l + r) >> 1;
      int total = 0, s = n;
      for (const vector<int> &row: matrix)
        total += (s = distance(row.begin(), upper_bound(row.begin(), row.begin()+s, m)));
      if (total >= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};

int main() {
  Solution s;
  
  return 0;
}
