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
  int minStartValue(vector<int>& nums) {
    int sum = 0, min_sum = INT_MAX;
    for (int i = 0, stop = nums.size(); i < stop; ++i)
      min_sum = min(min_sum, sum += nums[i]);
    return max(1, 1 - min_sum);
  }
};

int main() {
  Solution s;
  
  return 0;
}
