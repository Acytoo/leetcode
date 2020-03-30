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
  int minimumSwap(string s1, string s2) {
    const int n = s1.size();
    int xy = 0, yx = 0;
    for (int i=0; i<n; ++i)
      if (s1[i] == 'x' && s2[i] == 'y')
        ++xy;
      else if (s1[i] == 'y' && s2[i] == 'x')
        ++yx;
    // cout << xy << " xy yx " << yx << endl;
    if ((xy+yx) & 1) return -1;
    int min_ = min(xy, yx), max_ = max(xy, yx), res = 0;
    if (min_ & 1)
      res += min_ - 1 + 2;
    else
      res += min_;

    res += (max_-min_) >> 1;
    return res;
    // if (min is even)
    //   res += min;
    // else if (min is odd)
    //   res += even_min + min_left<<1 (2);
    // return (min_ << 1) + ((max_-min_) >> 1);
  }
};

int main() {
  Solution s;
  string s1 = "xxyyxyxyxx", s2 = "xyyxyxxxyx";
  cout << s.minimumSwap(s1, s2) << endl;
  return 0;
}
