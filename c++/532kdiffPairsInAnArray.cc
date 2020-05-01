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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// k: absolute difference
class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;;  // num --> count
    for (const int num: nums) ++m[num];
    int res = 0;

    if (k == 0) {
      for (const auto &kv: m)
        if (kv.second > 1) ++res;
    } else {
      for (const auto &kv: m)
        if (m.count(kv.first + k)) ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
