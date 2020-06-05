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
// From huahua
class Solution {
 public:
  bool hasAllCodes(string_view s, int k) {  // hasAllCodes(string, int ) -> hasAllCodes(string_view, int)
    const int n = s.size();
    if ((n - k + 1) * k < (1 << k)) return false;
    unordered_set<string_view> c;
    for (int i = 0, stop = n - k; i <= stop; ++i)
      c.insert(s.substr(i, k));
    return c.size() == (1 << k);
  }
};

int main() {
  Solution s;
  cout << s.hasAllCodes("0000101001", 1) << endl;
  return 0;
}
