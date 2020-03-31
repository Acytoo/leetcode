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
  int totalFruit(vector<int>& tree) {
    int res = 0, cur = 0;
    map<int, int> idx;  // fruit type --> last index
    for (int i=0, stop=tree.size(); i<stop; ++i) {
      if (!idx.count(tree[i]) && idx.size() == 2) {  // no basket for new fruit
        auto it = idx.begin();
        if (it->second == i-1) ++it;
        cur = i - it->second - 1;
        idx.erase(it);
      }
      idx[tree[i]] = i;
      ++cur;
      res = max(res, cur);
    }
    return res;
  }
};


int main() {
  Solution s;
  
  return 0;
}
