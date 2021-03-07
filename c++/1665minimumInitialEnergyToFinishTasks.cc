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
  int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [&] (const auto &a, const auto &b) {
      return (a[1] - a[0]) > (b[1] - b[0]);
    });
    int res = tasks.back()[1];
    for (int i = tasks.size() - 2; i >= 0; --i)
      res = max(res + tasks[i][0], tasks[i][1]);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
