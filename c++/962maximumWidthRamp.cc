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
  int maxWidthRamp(vector<int>& A) {
    const int n = A.size();
    int res = 0;
    stack<int> s;  // for index
    for (int i = 0; i < n; ++i)
      if (s.empty() || A[i] < A[s.top()])
        s.push(i);
    for (int i = n - 1; i >= 0; --i)
      while (!s.empty() && A[i] >= A[s.top()]) {
        res = max(res, i - s.top());
        s.pop();
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
