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
// Or using next_permutation
class Solution {
 public:
  Solution(vector<int>& nums) {
    nums_ = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return nums_;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> res (nums_);
    std::random_shuffle(res.begin(), res.end());
    return res;
  }
 private:
  vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
  Solution s;
  
  return 0;
}
