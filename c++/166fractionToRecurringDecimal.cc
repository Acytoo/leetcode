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
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    bool neg = (numerator ^ denominator) < 0;
    long above = abs(static_cast<long>(numerator));
    long below = abs(static_cast<long>(denominator));
    long quo = above / below, rem = above % below;
    string res = neg? "-"+to_string(quo): to_string(quo);
    if (rem == 0) return res;
    res += '.';
    unordered_map<long, int> m;
    int pos = res.size();
    while (rem != 0) {
      if (m.count(rem) != 0) {
        res.insert(m[rem], "(");
        return res+")";
      }
      m[rem] = pos;
      rem *= 10;
      res += to_string(rem/below);
      rem %= below;
      ++pos;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.fractionToDecimal(-6, 5) << endl;
  return 0;
}
