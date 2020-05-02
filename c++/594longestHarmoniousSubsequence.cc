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
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> counts;
    for (const int num: nums) ++counts[num];

    int res = 0;
    for (const auto &kv: counts)
      if (counts.count(kv.first + 1))
        res = max(res, kv.second + counts[kv.first + 1]);
    return res;
  }
};

class Solution1 {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> counts;
    int res = 0;
    for (const int num: nums) {
      ++counts[num];
      int l = counts[num - 1],
          h = counts[num + 1];
      if (l || h)
        res = max(res, counts[num] + max(l, h));
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {2,3,4,5,6,1};
  cout << s.findLHS(a) << endl;
  return 0;
}
