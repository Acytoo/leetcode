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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
  // Brute force
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    const int n = nums.size();
    if (n % k != 0)
      return false;

    map<int, int> m;  // num -> occ
    for (int i=0; i<n; ++i)
      ++m[nums[i]];

    while (!m.empty()) {
      int start = m.begin()->first;
      for (int i=0; i<k; ++i) {
        auto it = m.find(start+i);
        if (it == m.end())
          return false;
        --it->second;
        if (it->second == 0)
          m.erase(it);
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
