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


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    l_ = vector<int> (n, 0);
    n_ = vector<int> (n, 0);
    l_[0] = 1;

    // find the length of LIS
    int max_len = 0;
    for (int i=0; i<n; ++i)
      max_len = max(max_len, lenLIS(nums, i));

    // find the number of subsequences with length max_len
    int res = 0;
    for (int i=0; i<n; ++i)
      if (l_[i] == max_len)
        res += cntLIS(nums, i);

    return res;
  }
 private:
  // l_[i]: length of LIS end with nums[i]
  // n_[i]: number of LIS end with nums[i] that has length l_[i]
  vector<int> l_, n_;

  int lenLIS(const vector<int>& nums, int n) {
    if (n == 0)
      return 1;
    int max_len = 1;
    for (int i=0; i<n; ++i)
      if (nums[i] < nums[n])
        max_len = max(max_len, l_[i] + 1);
    return l_[n] = max_len;
  }

  int cntLIS(const vector<int>& nums, int n) {
    if (n == 0)
      return 1;
    if (n_[n] > 0)
      return n_[n];

    int total_num = 0, l = l_[n] - 1;
    for (int i=0; i<n; ++i)
      if (nums[i] < nums[n] && l_[i] == l)
        total_num += cntLIS(nums, i);

    if (total_num == 0)
      total_num = 1;
    return n_[n] = total_num;
  }
};

class Solution1 {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0)
      return 0;
    l_ = vector<int> (n, 0);
    n_ = vector<int> (n, 0);

    // find the length of LIS
    int max_len = 0;
    for (int i=0; i<n; ++i)
      max_len = max(max_len, lenLIS(nums, i));

    // find the number if LIS with length max_len
    int res = 0;
    for (int i=0; i<n; ++i)
      if (lenLIS(nums, i) == max_len)
        res += cntLIS(nums, i);

    return res;
  }
 private:
  // l_[i]: length of LIS end with nums[i]
  // n_[i]: number of LIS end with nums[i] that has length l_[i]
  vector<int> l_, n_;

  int lenLIS(const vector<int>& nums, int n) {
    if (n == 0)
      return 1;
    if (l_[n] > 0)
      return l_[n];

    int max_len = 1;
    for (int i=0; i<n; ++i)
      if (nums[i] < nums[n])
        max_len = max(max_len, lenLIS(nums, i) + 1);
    return l_[n] = max_len;
  }

  int cntLIS(const vector<int>& nums, int n) {
    if (n == 0)
      return 1;
    if (n_[n] > 0)
      return n_[n];

    int total_num = 0, l = lenLIS(nums, n);
    for (int i=0; i<n; ++i)
      if (nums[i] < nums[n] && lenLIS(nums, i) == l-1)
        total_num += cntLIS(nums, i);

    if (total_num == 0)
      total_num = 1;
    return n_[n] = total_num;
  }
};

int main() {
  Solution s;
  
  return 0;
}
