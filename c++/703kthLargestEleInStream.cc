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
class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums): k_(k) {
    if (nums.empty())
      return ;
    sort(nums.rbegin(), nums.rend());
    int tmp = std::min(k, static_cast<int>(nums.size()));
    nums_.insert(nums_.begin(), nums.begin(), nums.begin()+tmp);
  }

  int add(int val) {
    if (nums_.size() < k_) {
      nums_.push_back(val);
      sort(nums_.rbegin(), nums_.rend());
      return nums_.back();
    }
    if (val <= nums_.back())
      return nums_.back();
    int i = k_-1;
    while (i >= 0 && nums_[i] < val) --i;
    ++i;
    for (int j=k_-1; j>i; --j)
      nums_[j] = nums_[j-1];
    nums_[i] = val;
    return nums_[k_-1];
  }
 private:
  int k_;
  vector<int> nums_;
};

int main() {
  Solution s;
  
  return 0;
}
