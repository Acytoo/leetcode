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
  int maximumWealth(vector<vector<int>>& accounts) {
    int res = 0;
    for (auto a: accounts)
      res = max(res, accumulate(a.begin(), a.end(), 0));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
