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
// 1 <= deliciousness.length <= 10^5 -> O(n) time complexity?
// 0 <= deliciousness[i] <= 2^20
class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    constexpr int kMod = 1e9 + 7;
    unordered_map<int, int> m;
    long res = 0;
    for (int d: deliciousness) {
      for (int t = 1; t <= 1<<21; t <<= 1) {
        auto it = m.find(t - d);
        if (it != m.end())
          res += it->second;
      }
      ++m[d];
    }
    return static_cast<int>(res % kMod);
  }
};

class Solution_TLE {
 public:
  int countPairs(vector<int>& deliciousness) {
    constexpr int kMod = 1e9 + 7;
    bitset<2100000> p2;  // power of two
    p2[1] = 1;
    int cur = 1;
    for (int i = 0; i < 21; ++i)
      p2[cur <<= 1] = 1;
    long res = 0;
    int nums[2100000];
    memset(nums, 0, sizeof nums);
    const int max_deli = *max_element(deliciousness.begin(), deliciousness.end());

    for_each(deliciousness.begin(), deliciousness.end(), [&](const int i) { ++nums[i]; });
    for (int i = 0; i <= max_deli; ++i) {
      if (nums[i] == 0) continue;
      if (p2[i]) res += (nums[i] * (nums[i] - 1)) >> 1;
      for (int j = i + 1; j <= max_deli; ++j) {
        if (nums[j] == 0) continue;
        if (p2[i + j])
          res += nums[i] * nums[j];
      }
    }
    return static_cast<int>(res % kMod);
  }
};

class Solution_TLE {
 public:
  int countPairs(vector<int>& deliciousness) {
    constexpr int kMod = 1e9 + 7;
    bitset<2100000> p2;  // power of two
    p2[1] = 1;
    int cur = 1;
    for (int i = 0; i < 21; ++i)
      p2[cur <<= 1] = 1;
    long res = 0;
    for (int i = 0, n = deliciousness.size(); i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (p2[deliciousness[i] + deliciousness[j]])
          ++res;
    return static_cast<int>(res % kMod);
  }
};

int main() {
  Solution s;
  
  return 0;
}
