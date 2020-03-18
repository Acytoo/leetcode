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
// only a and b, return 0, 1, 2
class Solution {
 public:
  int removePalindromeSub(string s) {
    if (s.empty())
      return 0;
    if (s == string(s.rbegin(), s.rend()))
      return 1;
    return 2;
  }
};

int main() {
  Solution s;
  
  return 0;
}
