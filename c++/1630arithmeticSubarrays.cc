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
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    res.reserve(l.size());

    auto isArithmetic = [&] (const int l, const int r) -> bool {
      vector<int> tmp (nums.begin() + l, nums.begin() + r + 1);
      sort(tmp.begin(), tmp.end());
      const int delta = tmp.back() - tmp.front();
      if (delta == 0) return true;
      const int spaces = tmp.size() - 1;  //等差数列中，相邻的两个数之间的“空隙”的数量。
      if (delta % spaces != 0) return false;  // 总共相差的数不能平均的分配到所有的“空隙”中，那么一定不等差
      const int d = tmp[1] - tmp[0];
      for (int i = 1; i < spaces; ++i)
        if (d != tmp[i + 1] - tmp[i]) return false;
      return true;
    };

    for (int i = 0, n = l.size(); i < n; ++i)
      res.emplace_back(isArithmetic(l[i], r[i]));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
