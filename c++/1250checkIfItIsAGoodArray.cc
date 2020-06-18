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

// Bézout's identity
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isGoodArray(vector<int>& nums) {
    // if (nums.size() == 1) return false;  // num = {1}
    int a = nums.front();
    for (const int num: nums)
      a = gcd(a, num);
    return a == 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
