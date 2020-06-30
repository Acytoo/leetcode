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
  vector<string> ambiguousCoordinates(string S) {
    vector<string> res;
    const int n = S.size() - 1;
    auto allValid = [&S] (int l, int r) -> vector<string> {
      if ((r - l > 1) && S[l] == '0') {
        if (S[r - 1] == '0')
          return {};
        return {"0." + S.substr(l + 1, r - l - 1)};
      }
      if (S[r - 1] == '0') return {S.substr(l, r - l)};
      vector<string> res {S.substr(l, r - l)};
      for (int i = l + 1; i < r; ++i)
        res.emplace_back(S.substr(l, i - l) + "." + S.substr(i, r - i));
      return res;
    };
    for (int i = 2, stop = S.size() - 1; i < stop; ++i) {
      vector<string> X = allValid(1, i), Y = allValid(i, stop);
      if (X.empty() || Y.empty()) continue;
      for (string x: X)
        for (string y: Y)
          res.emplace_back("(" + x + ", " + y + ")");
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
