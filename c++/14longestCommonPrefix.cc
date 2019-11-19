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
  string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if (n == 0) return "";
    if (n == 1) return strs[0];

    // vector<int> lens(n);
    int len = INT_MAX;
    for (int i=0; i < n; ++i)
      len = min(len, (int)strs[i].size());

    string res = "";
    for (int i=0; i < len; ++i) {
      char tmp = strs[0][i];
      int j=1;
      while (j < n) {
        if (tmp != strs[j][i]) {
          return res;
        }
        ++j;
      }
      res += tmp;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> a = {"abc", "cbc"};
  cout << s.longestCommonPrefix(a) << endl;
  return 0;
}
