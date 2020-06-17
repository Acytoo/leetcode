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
class Solution {  // O(n) time, O(1) space
 public:
  vector<int> runningSum(vector<int>& nums) {
    int sum = 0;
    for (int &num: nums) num = sum += num;
    return nums;
  }
};

class Solution1 {  // O(n) time, O(n) space, stl
 public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> res (nums.size());
    partial_sum(nums.begin(), nums.end(), res.begin());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
