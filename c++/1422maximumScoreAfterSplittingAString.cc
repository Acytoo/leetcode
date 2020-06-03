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
  int maxScore(string s) {
    bitset<500> ss (s);
    const int total_1 = ss.count(), n = s.size(), total_0 = n - total_1;
    int res = 0;
    for (int i = 1; i < n; ++i) {
      bitset<500> left (s.substr(0, i));
      const int left_1 = left.count(), score = i - left_1 + total_1 - left_1;
      res = max(res, score);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
