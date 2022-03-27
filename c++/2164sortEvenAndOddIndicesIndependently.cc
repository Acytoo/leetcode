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
  vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> a1, a2;
    for (int i = 0, n = nums.size(); i < n; ++i) {
      a1.emplace_back(nums[i]);
      if (++i < n) a2.emplace_back(nums[i]);
    }
    sort(a1.begin(), a1.end());
    sort(a2.rbegin(), a2.rend());
    // sort(a1.begin(), a1.end(), greater<>());
    int idx = 0;
    for (const int a : a1) {
      nums[idx] = a;
      idx += 2;
    }
    idx = 1;
    for (const int a : a2) {
      nums[idx] = a;
      idx += 2;
    }
    // reverse(nums.begin(), nums.end());
    return nums;
  }
};

int main() {
  Solution s;
  
  return 0;
}
