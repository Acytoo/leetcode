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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    const int n = nums.size();
    multiset<long> s;
    for (int i=0; i<n; ++i) {
      if (i > k)
        s.erase(s.find(nums[i-k-1]));

      auto it = s.insert(nums[i]);
      if (it != s.begin() && *it - *prev(it) <= t) return true;
      if (next(it) != s.end() && *next(it) - *it <= t) return true;
    }
    return false;
  }
};


int main() {
  Solution s;
  vector<int> a = {10,15,18,24};
  cout << s.containsNearbyAlmostDuplicate(a, 3, 3) << endl;
  return 0;
}
