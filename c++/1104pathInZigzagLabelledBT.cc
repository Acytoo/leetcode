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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  // From Huahua: zxi.mytechroad.com
  vector<int> pathInZigZagTree(int label) {
    vector<int> res;
    while (label) {
      res.push_back(label);
      int h = 31 - __builtin_clz(label);
      label = ((1 << h) + (1 << (h+1)) - 1 - label) >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
