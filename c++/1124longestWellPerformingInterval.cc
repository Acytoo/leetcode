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
  int longestWPI(vector<int>& hours) {
    int res = 0, sum = 0;
    unordered_map<int, int> m;
    for (int i = 0, stop = hours.size(); i < stop; ++i) {
      sum += hours[i] > 8? 1: -1;
      if (sum > 0) {
        res = i + 1;
        continue;
      }
      if (m.count(sum) == 0)
        m[sum] = i;
      if (m.count(sum - 1) == 1)
        res = max(res, i - m[sum - 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
