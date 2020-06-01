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
  bool canConstruct(string s, int k) {
    const int n = s.size();
    if (n < k) return false;
    if (n == k) return true;

    vector<int> dict ('z' + 1);
    for (const char c: s) ++dict[c];
    int odd = 0;
    for (char c = 'a'; c <= 'z'; ++c)
      odd += (dict[c] & 1);
    return odd <= k;
  }
};

int main() {
  Solution s;
  
  return 0;
}
