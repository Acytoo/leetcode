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
// From huahua
class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> res (k);
    int idx = 0;
    for (int i = 0; i < n; ++i) {
      while (idx && res[idx - 1] > nums[i] && idx + n - i - 1 >= k)
        --idx;
      if (idx < k)
        res[idx++] = nums[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
