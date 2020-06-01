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

// 1 <= n <= 10^4 -> 9999 -> 36
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countLargestGroup(int n) {
    vector<int> sums (37);
    for (int i = 1; i <= n; ++i) {
      int num = i, sum = 0;
      while (num) {
        sum += num % 10;
        num /= 10;
      }
      ++sums[sum];
    }
    return count(sums.begin(), sums.end(), *max_element(sums.begin(), sums.end()));
  }
};

int main() {
  Solution s;
  
  return 0;
}
