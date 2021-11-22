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
class Solution1 {  // time O(n), space O(1)
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i = 0, n = nums.size(); i < n; ++i) {
      const int tmp = abs(nums[i]);
      const int idx = tmp - 1;
      nums[idx] = -abs(nums[idx]);
    }
    vector<int> res;
    for (int i = 1, n = nums.size(); i < n; ++i)
      if (nums[i] > 0)
        res.emplace_back(i + 1);
    return res;
  }
};

class Solution {  // time : O(n), space : O(n)
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> dic(nums.size() + 1);
    for (const int a : nums) ++dic[a];
    vector<int> res;
    for (int i = 0, n = nums.size(); i <= n; ++i)
      if (dic[i] == 0)
        res.emplace_back(i);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
