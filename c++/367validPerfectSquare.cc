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
  bool isPerfectSquare(int num) {
    int last_digit = num % 10;
    if (last_digit == 2 || last_digit == 3 || last_digit == 7 || last_digit == 8)
      return false;
    int root = static_cast<int>(sqrt(num) + 0.5);
    return num == root * root;
  }
 private:
  static double sqrt(double n) {
    constexpr double kPrec = 1e-3;
    double l = .0, r = n, m = .0, square = .0;
    while (r - l > kPrec) {
      m = (l + r) / 2;
      square = m * m;
      if (square > n)
        r = m;
      else
        l = m;
    }
    return (l + r) / 2;
  }
};

int main() {
  Solution s;
  cout << s.isPerfectSquare(17) << endl;
  return 0;
}
