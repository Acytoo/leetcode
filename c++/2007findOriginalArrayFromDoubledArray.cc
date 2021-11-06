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
  vector<int> findOriginalArray(vector<int>& changed) {
    const int n = changed.size();
    if (n & 1) return {};
    int nums[100001];
    memset(nums, 0, sizeof nums);
    int maxnumber = -1;
    for (const int a : changed) {
      maxnumber = max(maxnumber, a);
      ++nums[a];
    }
    int idx = 0, i = maxnumber, stop = n >> 1;
    vector<int> res;
    while (idx < stop) {
      if (nums[i] < 0) return {};
      if (nums[i] == 0) {
        --i;
        continue;
      }
      if (i & 1) return {};
      const int ori = i >> 1;
      res.emplace_back(ori);
      --nums[ori];
      --nums[i];
      ++idx;
    }
    for (int i = 0; i < maxnumber; ++i)
      if (nums[i] != 0) return {};
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
