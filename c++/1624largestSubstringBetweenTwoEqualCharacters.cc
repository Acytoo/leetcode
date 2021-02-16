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
// 1 <= s.length <= 300
class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    vector<vector<int>> idxes('z' + 1);
    for (int i = 0, n = s.size(); i < n; ++i)
      idxes[s[i]].push_back(i);
    int res = -1;
    for (char c = 'a'; c <= 'z'; ++c)
      if (!idxes[c].empty())
        res = max(res, idxes[c].back() - idxes[c].front() - 1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
