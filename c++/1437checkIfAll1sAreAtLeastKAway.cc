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
  bool kLengthApart(vector<int>& nums, int k) {
    if (k == 0) return true;
    int last1 = -1e6;
    for (int i = 0, stop = nums.size(); i < stop; ++i)
      if (nums[i] == 1) {
        if (i - last1 <= k) return false;
        last1 = i;
      }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
