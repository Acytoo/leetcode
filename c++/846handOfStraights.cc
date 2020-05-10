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
  bool isNStraightHand(vector<int>& hand, int W) {
    map<int, int> counts;
    for (const int h: hand) ++counts[h];
    while (!counts.empty()) {
      auto it = counts.begin();
      int start = it->first;
      for (int i = 0; i < W; ++i) {
        if (it == counts.end() || it->first != start + i) return false;
        auto bk = it++;
        if (--(bk->second) == 0) counts.erase(bk);
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
