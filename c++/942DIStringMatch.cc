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
  vector<int> diStringMatch(string S) {
    int lo = 0, hi = S.size();
    vector<int> res;
    res.reserve(hi + 1);
    for (const char c: S) {
      if (c == 'D')
        res.emplace_back(hi--);
      else
        res.emplace_back(lo++);
    }
    res.emplace_back(lo);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
