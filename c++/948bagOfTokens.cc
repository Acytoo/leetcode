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
  int bagOfTokensScore(vector<int>& tokens, int P) {
    if (tokens.empty() || P == 0) return 0;
    sort(tokens.begin(), tokens.end());
    if (P < tokens[0]) return 0;

    int res = 0, l = 0, r = tokens.size() - 1, cur = 0;
    while (l <= r) {
      if (tokens[l] <= P) {
        ++cur;
        res = max(res, cur);
        P -= tokens[l];
        ++l;
      } else if (cur > 0) {
        --cur;
        P += tokens[r];
        --r;
      } else {
        break;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
