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
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    int l = -1, r = s.size();
    while (++l < --r) {
      while (l < r && !isalnum(s[l])) ++l;
      while (l < r && !isalnum(s[r])) --r;
      if (tolower(s[l]) != tolower(s[r])) return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
