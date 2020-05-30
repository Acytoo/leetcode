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
// From huahua
class Solution {
 public:
  int numberOfSubstrings(string s) {
    vector<int> last_idx{-1, -1, -1};
    int res = 0;
    for (int i = 0, stop = s.size(); i < stop; ++i) {
      last_idx[s[i] - 'a'] = i;
      res += 1 + min({last_idx[0], last_idx[1], last_idx[2]});
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
