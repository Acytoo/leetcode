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
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    int l = 0, r = n;
    while (l <= r) {
      const int m = l + ((r - l) >> 1);
      const int g = guess(m);
      if (g > 0) {
        l = m + 1;
      } else if (g < 0) {
        r = m - 1;
      } else {
        return m;
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
