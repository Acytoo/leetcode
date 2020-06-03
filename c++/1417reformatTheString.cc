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
  string reformat(string s) {
    const int len = s.size();
    vector<char> digits, letters;
    digits.reserve(len);
    letters.reserve(len);
    for (const char c: s)
      if (isdigit(c))
        digits.emplace_back(c);
      else
        letters.emplace_back(c);
    const int m = digits.size(), n = letters.size();
    if (abs(m - n) > 1) return "";
    if (m > n) {  // more digits than letters
      for (int i = 0, idx = -1; i < len; i += 2)
        s[i] = digits[++idx];
      for (int i = 1, idx = -1; i < len; i += 2)
        s[i] = letters[++idx];
    } else {
      for (int i = 1, idx = -1; i < len; i += 2)
        s[i] = digits[++idx];
      for (int i = 0, idx = -1; i < len; i += 2)
        s[i] = letters[++idx];
    }
    return s;
  }
};

int main() {
  Solution s;
  
  return 0;
}
