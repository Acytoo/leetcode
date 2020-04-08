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
  bool judgeSquareSum(int c) {
    long a = 0, b = static_cast<long>(sqrt(c));  // a can be 0, so c = b * b
    long cc = static_cast<long>(c);
    while (a <= b) {
      long sum = a * a + b * b;
      if (sum == cc) return true;
      if (sum < cc)
        ++a;
      else
        --b;
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
