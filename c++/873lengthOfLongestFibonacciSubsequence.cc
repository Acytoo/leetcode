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

// 3 <= A.length <= 1000
// 1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& A) {
    const int n = A.size();
    vector<vector<int>> dp (n, vector<int> (n, 2));
    int res =  0;

    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        int pre = A[k] - A[j];
        if (A[j] <= pre) break;
        int i = lower_bound(A.begin(), A.begin() + j, pre) - A.begin();
        if (A[i] != pre) continue;
        dp[j][k] = dp[i][j] + 1;
        res = max(res, dp[j][k]);
      }

    return res;
  }
};

class Solution1 {
 public:
  int lenLongestFibSubseq(vector<int>& A) {
    const int n = A.size();
    int **dp = new int *[n];
    for (int i = 0; i < n; ++i) dp[i] = new int [n];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dp[i][j] = 2;
    int res =  0;

    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        int pre = A[k] - A[j];
        if (A[j] <= pre) break;
        int i = lower_bound(A.begin(), A.begin() + j, pre) - A.begin();
        if (A[i] != pre) continue;
        dp[j][k] = dp[i][j] + 1;
        res = max(res, dp[j][k]);
      }

    for (int i = 0; i < n; ++i)
      delete[] dp[i];
    delete[] dp;
    return res;
  }
};

class Solution3 {
 public:
  int lenLongestFibSubseq(vector<int>& A) {
    unordered_set<int> s (A.begin(), A.end());
    const int n = A.size();
    int res = 2;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        int a = A[i], b = A[j], c = a + b, l = 2;
        if (static_cast<long> (a) * res > A.back()) break;
        while (s.count(c)) {
          a = b;
          b = c;
          c = a + b;
          ++l;
        }
        res = max(res, l);
      }
    return res > 2? res: 0;
  }
};

int main() {
  Solution s;
  // int n = 0;
  // cin >> n;
  // int nn = n * n;
  // cout << n << " " << nn << endl;
  // int *p = new int [nn];
  // for (int i = 0; i < nn; ++i) cout << p[i] << " ";
  // cout << endl;
  // cout << "size " << sizeof(p) << endl;
  // memset(p, 0, sizeof(p));
  // for (int i = 0; i < nn; ++i) cout << p[i] << " ";
  // cout << endl;
  // delete p;
  // int b[5] = {1,2,3,4,5};
  // for (int i = 0; i < 5; ++i) cout << b[i] << " ";
  // cout << endl;
  // memset(b, 0, sizeof(b));
  // for (int i = 0; i < 5; ++i) cout << b[i] << " ";
  // cout << endl;
  // cout << sizeof(b) << endl;

  return 0;
}
