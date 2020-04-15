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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    const int n = pattern.size();
    vector<bool> res;
    res.reserve(queries.size());
    auto match =
        [&] (const string &word) -> bool {
          int i = 0, j = 0, m = word.size();
          for (i=0; i<m; ++i) {
            if (j == n && word[i] <= 'Z') return false;
            if ((j == n || pattern[j] <= 'Z') && word[i] >= 'a') continue;
            if ((pattern[j] <= 'Z' || word[i] <='Z') && pattern[j] != word[i]) return false;
            if (pattern[j] >= 'a' && word[i]!=pattern[j]) continue;
            ++j;
          }
          return i == m && j == n;
        };
    for (const string &q: queries)
      res.push_back(match(q));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
