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
  int maxProduct(vector<int>& nums) {
    int m1 = nums[0], m2 = nums[1];
    if (m1 < m2) swap(m1, m2);
    for (int i = 2, stop = nums.size(); i < stop; ++i)
      if (m2 < nums[i])
        if (m1 <= nums[i]) {
          m2 = m1;
          m1 = nums[i];
        } else {
          m2 = nums[i];
        }
    return (m1 - 1) * (m2 - 1);
  }
};

class Solution1 {
 public:
  int maxProduct(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    return (nums[0] - 1) * (nums[1] - 1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
