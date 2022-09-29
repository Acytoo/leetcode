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
  int subarraysDivByK(vector<int>& nums, int k) {
    int res = 0, sum = 0;
    vector<int> c(k);
    c[0] = 1;
    for (int num : nums) {
      sum = (sum + num % k + k) % k;
      res += c[sum];
      ++c[sum];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
