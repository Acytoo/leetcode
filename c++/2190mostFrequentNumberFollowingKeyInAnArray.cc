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
  int mostFrequent(vector<int>& nums, int key) {
    unordered_map<int, int> m;
    for (int i = 0, n = nums.size(); i < n; ) {
      if (nums[i] == key && ++i < n) {
        ++m[nums[i]];
      } else {
        ++i;
      }
    }
    int maxocc = 0, res = 0;
    for (const auto &[k, v] : m)
      if (v > maxocc) {
        maxocc = v;
        res = k;
      }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
