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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 1 <= A.length <= 10000
class Solution {
 public:
  int largestSumAfterKNegations(vector<int>& A, int K) {
    const int n = A.size();
    vector<int> neg, pos;
    neg.reserve(n);
    pos.reserve(n);
    bool zero = false;
    for (const int a: A)
      if (a < 0)
        neg.push_back(a);
      else if (0 < a)
        pos.push_back(a);
      else
        zero = true;
    sort(neg.begin(), neg.end());
    int negn = neg.size(), res = 0;
    if (negn >= K) {
      for (int i=0; i<K; ++i) res -= neg[i];
      for (int i=K; i<negn; ++i) res += neg[i];
      res = accumulate(pos.begin(), pos.end(), res);
      return res;
    } else {
      int left = K - negn;
      if ((left&1)==0 || zero) {
        for (const int i: neg) res -= i;
        res = accumulate(pos.begin(), pos.end(), res);
        return res;
      } else {
        int min_pos = *min_element(pos.begin(), pos.end()),
            max_neg = neg.empty()? INT_MAX: -neg.back();
        for (const int i: neg) res -= i;
        res = accumulate(pos.begin(), pos.end(), res);
        res -= min(min_pos, max_neg)<<1;
        return res;
      }
    }
  }
};

int main() {
  Solution s;
  
  return 0;
}
