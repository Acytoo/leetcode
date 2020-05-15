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

// same as LeetCode 560
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numSubarraysWithSum(vector<int>& A, int S) {
    unordered_map<int, int> counts {{0, 1}};
    int sum = 0, res = 0;
    for (const int a: A) {
      sum += a;
      res += counts[sum - S];
      ++counts[sum];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
