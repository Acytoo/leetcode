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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int m = s.size(), n = p.size();
    vector<int> res;
    vector<int> vs(26, 0);
    vector<int> vp(26, 0);
    for (const char c : p)
      ++vp[c-'a'];
    for (int i=0; i<m; ++i) {
      if (i>=n)
        --vs[s[i-n]-'a'];
      ++vs[s[i]-'a'];
      if (vs == vp)
        res.push_back(i+1-n);
    }
    return res;
  }
};

int main() {
  Solution s;
  for (const auto i : s.findAnagrams("abab", "ab"))
    cout << i << " ";
  cout << endl;
  return 0;
}
