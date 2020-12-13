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

// 2 <= nums.length <= 10^5
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From leetcode
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res;
    res.reserve(n);
    int sum_diff = 0;
    for (int i = 0; i < n; ++i) sum_diff += nums[i] - nums[0];
    res.emplace_back(sum_diff);
    for (int i = 1; i < n; ++i) {
      sum_diff += ((i << 1) - n ) * (nums[i] - nums[i - 1]);
      res.emplace_back(sum_diff);
    }
    return res;
  }
};

// 1, 4, 6, 8, 10:
// res[0] = 4 - 1 + 6 - 1 + 8 - 1 + 10 - 1 = [(4 + 6 + 8 + 10) - (1 * 4)]
// res[1] = [(1 - 4)] + [(6 - 4) + (8 - 4) + (10 - 4)] = [4 - 1] + [6 + 8 + 10 - (4 * 3)]
// res[2] = [(6 - 1) + (6 - 4)] + [(8 - 6) + (10 - 6)] = [(6 * 2) - [1 + 4]] + [(8 + 10) - (6 * 2)]
class Solution1 {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res;
    res.reserve(n);
    int *prefix_sum = new int [n];
    memset(prefix_sum, 0, sizeof(prefix_sum));
    prefix_sum[0] = nums[0];
    for (int i = 1; i < n; ++i) prefix_sum[i] = prefix_sum[i - 1] + nums[i];

    res.emplace_back(prefix_sum[n - 1] - nums[0] * n);
    for (int i = 1, nn = n - 1; i < n; ++i) {
      int cur = 0;
      cur = nums[i] * i - prefix_sum[i - 1];
      cur += prefix_sum[nn] - prefix_sum[i] - nums[i] * (nn - i);
      res.emplace_back(cur);
    }
    delete [] prefix_sum;
    return res;
  }
};

class Solution_TLE4 {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res;
    res.reserve(n);
    int *abs_diffs = new int [n * n];
    memset(abs_diffs, 0, sizeof(abs_diffs));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < i; ++j)
        abs_diffs[i  * n + j] = nums[i] - nums[j];

    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < i; ++j) cur += abs_diffs[i * n + j];
      for (int j = i + 1; j < n; ++j) cur += abs_diffs[j * n +i];
      res.emplace_back(cur);
    }
    delete [] abs_diffs;
    return res;
  }
};

class Solution_TLE3 {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < i; ++j) cur += nums[i] - nums[j];
      for (int j = i + 1; j < n; ++j) cur += nums[j] - nums[i];
      res.emplace_back(cur);
    }
    return res;
  }
};

class Solution_TLE2 {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < n; ++j) {
        cur += abs(nums[i] - nums[j]);
      }
      res.emplace_back(cur);
    }
    return res;
  }
};

class Solution_TLE1 {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    const int n = nums.size();
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        res[i] += abs(nums[i] - nums[j]);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
