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
  int findMaximumXOR(vector<int>& nums) {
    int res = 0, mask = 0;
    for (int i=31; i>=0; --i) {
      mask |= (1 << i);
      unordered_set<int> s;
      for (const int num: nums)
        s.insert(num & mask);
      int t = res | (1 << i);
      for (const int prefix: s)
        if (s.count(t ^ prefix)) {
          res = t;
          break;
        }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
