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
  string thousandSeparator(int n) {
    if (n == 0) return "0";
    int dig = 0;
    string res;
    while (n) {
      ++dig;
      if (dig == 4) {
        res += '.';
        dig = 1;
      }
      res += n % 10 + '0';
      n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
