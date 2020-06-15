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
class Solution {  // O(n) ave
 public:
  int minMoves2(vector<int>& nums) {
    const int mid = nums.size() >> 1;
    nth_element(nums.begin(), nums.begin() + mid, nums.end());
    int res = 0;
    for (const int num: nums)
      res += abs(num - nums[mid]);
    return res;
  }
};

class Solution1 {  // O(nlogn)
 public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int mid = nums[nums.size() >> 1];
    int res = 0;
    for (const int num: nums)
      res += abs(mid - num);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
