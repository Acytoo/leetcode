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
// Brute force-TLE, sliding window:
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    const int l1 = s1.size(), l2 = s2.size();
    vector<int> c1 (26), c2 (26);
    for (const char c: s1)
      ++c1[c-'a'];
    for (int i=0; i<l2; ++i) {
      if (i >= l1) --c2[s2[i-l1]-'a'];
      ++c2[s2[i]-'a'];
      if (c1 == c2) return true;
    }
    return false;
  }
};

class Solution_same {
 public:
  bool checkInclusion(string s1, string s2) {
    const int l1 = s1.size(), l2 = s2.size();
    vector<int> c1 ('z'+1), c2 ('z'+1);
    for (const char c: s1)
      ++c1[c];
    for (int i=0; i<l2; ++i) {
      if (i >= l1) --c2[s2[i-l1]];
      ++c2[s2[i]];
      if (c1 == c2) return true;
    }
    return false;
  }
};

int main() {
  Solution s;
  string s1 = "abc", s2 = "lfdjcsbfcab";
  cout << s.checkInclusion(s1, s2) << endl;
  return 0;
}
