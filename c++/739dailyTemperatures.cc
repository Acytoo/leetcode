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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;
// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100


static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // stack
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    const int n = temperatures.size();
    vector<int> res(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && temperatures[s.top()] <= temperatures[i]) s.pop();
      res[i] = s.empty() ? 0 : s.top() - i;
      s.push(i);
    }
    return res;
  }
};

class Solution_SAME {
  // Stack
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    const int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
        const int j = s.top(); s.pop();
        res[j] = i - j;
      }
      s.push(i);
    }
    return res;
  }
};

class Solution1 {
  // DP
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    const int n = T.size();
    vector<int> res (n, 0);
    function<int(int, int)> findDay = [&] (int i, int j) -> int {
      if (j >= n) return 0;
      if (T[j] > T[i]) return j - i;
      if (res[j] == 0) return 0;
      return findDay(i, j + res[j]);
    };
    for (int i = n - 2; i >= 0; --i)
      res[i] = findDay(i, i + 1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
