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
  int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    int match_idx = 0;
    if (ruleKey == "color") {
      match_idx = 1;
    } else if (ruleKey == "name") {
      match_idx = 2;
    }
    int res = 0;
    for (const auto &item: items)
      if (item[match_idx] == ruleValue)
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
