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
  int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    vector<pair<int, int>> unsatis;  // unsatisfied number -> time
    int res = 0;
    for (int i = 0, stop = customers.size(); i < stop; ++i)
      if (grumpy[i] == 0)
        res += customers[i];
      else
        unsatis.emplace_back(customers[i], i);
    if (unsatis.empty()) return res;

    --X;  // convert time duration to index diff
    int cur = unsatis[0].first, max_c = cur;
    for (int i = 0, j = 1, stop = unsatis.size(); j < stop; ++j)
      if (unsatis[j].second <= unsatis[i].second + X) {
        cur += unsatis[j].first;
      } else {
        max_c = max(max_c, cur);
        while (unsatis[i].second + X < unsatis[j].second) cur -= unsatis[i++].first;
        cur += unsatis[j].first;
      }
    return res + max(max_c, cur);
  }
};

int main() {
  Solution s;
  
  return 0;
}
