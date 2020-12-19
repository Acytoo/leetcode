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

// 与操作，参与的数越多，越小。一个数与上一个数，最大的可能是他本身，因为只有 1 & 1 = 1, 1 & 0 = 0 & 1 = 0 & 0 = 0，不同位上出现了0的话，一定会减小。
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From leetcode solution
class Solution {
 public:
  int closestToTarget(vector<int>& arr, int target) {
    int res = abs(arr[0] - target);
    vector<int> valid = {arr[0]};
    for (int num: arr) {
      vector<int> validNew = {num};
      res = min(res, abs(num - target));
      for (int prev: valid) {
        validNew.push_back(prev & num);
        res = min(res, abs((prev & num) - target));
      }
      validNew.erase(unique(validNew.begin(), validNew.end()), validNew.end());
      valid = validNew;
    }
    return res;
  }
};

class Solution_TLE3 {
 public:
  int closestToTarget(vector<int>& arr, int target) {
    const int n = arr.size();
    int res = abs(-1000000000 - target);
    for (int l = 0; l < n; ++l) {
      int cur = arr[l];
      for (int i = l; i < n; ++i) {
        cur &= arr[i];
        res = min(res, abs(cur - target));
        if (res == 0) return 0;
        if (cur < target) break;
      }
      if (cur > target) break; // 这层循环只会让cur变大，因为参与与运算的数字在减少
    }
    return res;
  }
};

class Solution_TLE2 {
 public:
  int closestToTarget(vector<int>& arr, int target) {
    const int n = arr.size();
    int res = abs(-1000000000 - target);
    for (int l = 0; l < n; ++l) {
      int cur = arr[l];
      for (int i = l; i < n; ++i) {
        cur &= arr[i];
        res = min(res, abs(cur - target));
        if (res == 0) return 0;
        if (cur < target) break;
      }
    }
    return res;
  }
};

class Solution_TLE1 {
 public:
  int closestToTarget(vector<int>& arr, int target) {
    const int n = arr.size();
    int res = INT_MAX;
    for (int l = 0; l < n; ++l) {
      int cur = arr[l];
      res = min(res, abs(cur - target));
      for (int i = l + 1; i < n; ++i) {
        cur &= arr[i];
        res = min(res, abs(cur - target));
      }
    }
    return min(res, abs(-1000000000 - target));
  }
};


int main() {
  Solution s;
  
  return 0;
}
