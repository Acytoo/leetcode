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
  int longestMountain(vector<int>& A) {
    if (A.empty()) return 0;
    const int n = A.size();
    int inc[n], dec[n];
    memset(inc, 0, sizeof(inc));
    memset(dec, 0, sizeof(inc));

    for (int i = 1; i < n; ++i)
      if (A[i - 1] < A[i]) inc[i] = inc[i - 1] + 1;
    for (int i = n - 2; i >= 0; --i)
      if (A[i + 1] < A[i]) dec[i] = dec [i + 1] + 1;

    int res = 0;
    for (int i = 0; i < n; ++i)
      if (inc[i] && dec[i])
        res = max(res, inc[i] + dec[i] + 1);
    return res >= 3? res: 0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
