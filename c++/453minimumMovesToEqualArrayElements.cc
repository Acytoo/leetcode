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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int minMoves(vector<int>& nums) {
    long sum = 0, mi = INT_MAX;
    const int n = nums.size();
    for (const int num: nums) {
      sum += num;
      if (num < mi) mi = num;
    }
    return sum - n * mi;
  }
};

class Solution1 {
 public:
  int minMoves(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0l) -
        nums.size() * *min_element(nums.begin(), nums.end());
  }
};

int main() {
  Solution s;
  
  return 0;
}
