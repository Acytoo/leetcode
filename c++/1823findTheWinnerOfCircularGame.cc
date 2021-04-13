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
// Brute force
class Solution {
 public:
  int findTheWinner(int n, int k) {
    bitset<512> friends;  // all 0
    const int losers = n - 1;
    int idx = 1;
    while (friends.count() != losers) {
      int kk = k - 1;
      while (kk != 0) {
        if (!friends.test(idx))
          --kk;
        ++idx;
        if (idx > n) idx = 1;
      }
      while (friends.test(idx)) {
        ++idx;
        if (idx > n) idx = 1;
      }
      friends.set(idx);
      ++idx;
      if (idx > n) idx = 1;
    }
    for (int i = 1; i <= n; ++i)
      if (!friends.test(i))
        return i;
    return -1;
  }
};

class Solution1 {  // Beautiful solution from leetcode
 public:
  int findTheWinner(int n, int k) {
    // n = 1, idx = 0 winner
    // n = 2, idx = (0+k)%2 winner
    // n = 3, idx = (0+k+k)%3 winner
    int res = 0;
    for(int i = 1; i <= n; ++i)
      res = (res + k) % i;
    return res + 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
