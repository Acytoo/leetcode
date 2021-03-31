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
  vector<int> movesToStamp(string stamp, string target) {
    const int ss = stamp.size(), ts = target.size();
    vector<int> res, seen(ts);
    int changed = 0;

    // return unstamped size
    auto unStamp = [&] (int s) -> int {
      int res = ss;
      for (int i = 0; i < ss; ++i) {
        if (target[s + i] == '*')
          --res;
        else if (target[s + i] != stamp[i])
          return 0;
      }
      if (res != 0)
        for (int i = s, stop = s + ss; i < stop; ++i)
          target[i] = '*';
      return res;
    };

    while (changed < ts) {
      bool found = false;
      for (int i = 0, stop = ts - ss; i <= stop; ++i) {
        if (seen[i]) continue;
        const int new_asterisk = unStamp(i);
        if (new_asterisk == 0) continue;
        changed += new_asterisk;
        res.push_back(i);
        found = true;
      }
      if (!found) return vector<int>();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
