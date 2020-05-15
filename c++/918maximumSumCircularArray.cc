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
// From lee215
class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& A) {
    int sum = 0, sum_max = -30000, cur_max = 0, sum_min = 3000, cur_min = 0;
    for (const int a: A) {
      sum += a;
      cur_min = min(cur_min + a, a);
      sum_min = min(sum_min, cur_min);
      cur_max = max(cur_max + a, a);
      sum_max = max(sum_max, cur_max);
    }
    return sum_max > 0? max(sum_max, sum - sum_min): sum_max;
  }
};

int main() {
  Solution s;

  return 0;
}
