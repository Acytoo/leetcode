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
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    const int n = nums.size();
    res.reserve(n - k + 1);
    multiset<int> window (nums.begin(), nums.begin() + k);
    res.emplace_back(*window.rbegin());
    for (int i = k; i < n; ++i) {
      window.insert(nums[i]);
      window.erase(window.equal_range(nums[i - k]).first);
      res.emplace_back(*window.rbegin());
    }
    return res;
  }
};

class Solution_TLE {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    const int n = nums.size();
    res.reserve(n - k + 1);
    for (int i = 0, stop = n - k + 1; i < stop; ++i)
      res.emplace_back(*max_element(nums.begin() + i, nums.begin() + i + k));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
