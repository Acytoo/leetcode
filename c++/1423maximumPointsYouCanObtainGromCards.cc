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
  int maxScore(vector<int>& cardPoints, int k) {
    int cur = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0), res = cur;
    for (int i = 0, n = cardPoints.size() - 1; i < k; ++i) {
      cur = cur - cardPoints[k - i - 1] + cardPoints[n - i];
      res = max(res, cur);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
