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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string S) {
    int n = S.size()-1;
    if (n < 2)
      return {};
    vector<vector<int>> res;
    for (int i=0, stop=n-2; i<=stop; ++i) {
      if (S[i] == S[i+1])
        if (S[i] == S[i+2]) {
          int last = i+3;
          while (last <= n && S[i] == S[last]) ++last;
          if (last <= n) {
            --last;
            res.emplace_back(vector<int>{i, last});
            i = last;
          } else {
            res.emplace_back(vector<int>{i, n});
            break;
          }
        } else {
          ++i;  // S[i+1] != S[i+2], so skip it
        }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
