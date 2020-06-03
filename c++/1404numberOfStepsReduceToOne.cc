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
  int numSteps(string s) {
    bitset<500> num (s);
    int res = 0;
    bool carry = false;
    for (int i = 0, n = s.size() - 1; i < n; ++i) {
      if (num[i] ^ carry) {
        res += 2;
        carry = true;
      } else {
        ++res;
      }
    }
    return res + carry;
  }
};

int main() {
  Solution s;
  
  return 0;
}
