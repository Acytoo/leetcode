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
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    vector<int> lefts_idx;
    for (int i=0, stop=s.size(); i<stop;) {
      if (s[i] == ')') {
        if (lefts_idx.size() == 0) {
          s.erase(i, 1);
        } else {
          lefts_idx.pop_back();
          ++i;
        }
      } else if (s[i] == '(') {
        lefts_idx.push_back(i);
        ++i;
      } else {
        ++i;
      }
    }
    while (lefts_idx.size() > 0) {
      s.erase(lefts_idx.back(), 1);
      lefts_idx.pop_back();
    }
    return s;
  }
};

int main() {
  Solution s;
  cout << s.minRemoveToMakeValid("(a(b(c)d)") << endl;
  return 0;
}
