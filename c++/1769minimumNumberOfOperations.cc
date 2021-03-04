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
// DP
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    vector<int> res;
    res.reserve(boxes.size());
    int l = 0, r = 0, cur = 0;  // cur: res[i], l: '1's on the left, r: '1's on the right
    for (int i = 1, n = boxes.size(); i < n; ++i)
      if (boxes[i] == '1')  {
        cur += i;
        ++r;
      }
    res.emplace_back(cur);
    for (int i = 1, n = boxes.size(); i < n; ++i) {
      cur -= r;
      if (boxes[i] == '1') --r;
      if (boxes[i - 1] == '1') ++l;
      cur += l;
      res.emplace_back(cur);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
