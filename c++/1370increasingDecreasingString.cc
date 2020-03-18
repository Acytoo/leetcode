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
  string sortString(string s) {
    string res;
    vector<int> counts('z'+1, 0);
    for (const char c: s)
      ++counts[c];
    int n = s.size();
    while (res.size() != n) {
      for (char c='a'; c<='z'; ++c)
        if (counts[c] > 0) {
          res += c;
          --counts[c];
        }
      for (char c='z'; c>='a'; --c)
        if (counts[c] > 0) {
          res += c;
          --counts[c];
        }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
