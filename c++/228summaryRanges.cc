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
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.empty()) return res;

    int n = nums.size(), i = 0, num = nums[0], start_num = num;
    string cur = to_string(num);
    while (++i < n) {
      if (nums[i] == num+1) {
        num = nums[i];
        continue;
      }
      if (num > start_num) {
        cur += "->" + to_string(num);
      }
      res.emplace_back(move(cur));
      num = nums[i];
      cur = to_string(num);
      start_num = nums[i];
    }
    if (num > start_num) {
      cur += "->" + to_string(num);
    }
    res.emplace_back(move(cur));
    num = nums[i];
    // cur = to_string(num);
    start_num = num;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
