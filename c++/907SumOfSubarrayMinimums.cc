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
  int sumSubarrayMins(vector<int>& A) {
    constexpr int kMod = 1e9 + 7;
    int res = 0;
    const int n = A.size();
    vector<int> left (n), right (n);
    stack<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
      int len = 1;
      while (!s.empty() && A[i] < s.top().first) {
        len += s.top().second;
        s.pop();
      }
      s.emplace(A[i], len);
      left[i] = len;
    }
    while (!s.empty()) s.pop();
    for (int i = n - 1; i >= 0; --i) {
      int len = 1;
      while (!s.empty() && A[i] <= s.top().first) {
        len += s.top().second;
        s.pop();
      }
      s.emplace(A[i], len);
      right[i] = len;
    }
    for (int i = 0; i < n; ++i)
      res = (static_cast<long>(res) + left[i] * A[i] * right[i]) % kMod;
    return res % kMod;
  }
};

int main() {
  Solution s;
  
  return 0;
}
