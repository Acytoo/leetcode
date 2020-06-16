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
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> s (nums.begin(), nums.begin() + k - 1);
    vector<double> res;
    if (k & 1) {  // odd
      for (int i = k - 1, stop = nums.size(); i < stop; ++i) {
        s.insert(nums[i]);
        auto mid = next(s.begin(), k >> 1);
        res.emplace_back(static_cast<double>(*mid));
        s.erase(s.lower_bound(nums[i - k + 1]));
      }
    } else {
      for (int i = k - 1, stop = nums.size(); i < stop; ++i) {
        s.insert(nums[i]);
        auto mid = next(s.begin(), (k >> 1) - 1);
        res.emplace_back((static_cast<double>(*mid) + *next(mid)) / 2.0);
        s.erase(s.lower_bound(nums[i - k + 1]));
      }
    }
    return res;
  }
};

class Solution_same {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    multiset<int> s (nums.begin(), nums.begin() + k - 1);
    vector<double> res;
    if (k & 1) {  // odd
      for (int i = k - 1, stop = nums.size(); i < stop; ) {
        s.insert(nums[i]);
        auto mid = next(s.begin(), k >> 1);
        res.emplace_back(static_cast<double>(*mid));
        s.erase(s.lower_bound(nums[++i - k]));
      }
    } else {
      for (int i = k - 1, stop = nums.size(); i < stop; ) {
        s.insert(nums[i]);
        auto mid = next(s.begin(), (k >> 1) - 1);
        res.emplace_back((static_cast<double>(*mid) + *next(mid)) / 2.0);
        s.erase(s.lower_bound(nums[++i - k]));
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
