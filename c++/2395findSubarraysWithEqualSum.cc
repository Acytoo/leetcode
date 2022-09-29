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
  bool findSubarrays(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 1, n = nums.size(); i < n; ++i) {
      const int sum = nums[i - 1] + nums[i];
      if (s.count(sum)) return true;
      s.insert(sum);
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
