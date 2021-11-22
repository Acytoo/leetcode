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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> s;
    while (s.find(n) == s.end()) {
      s.insert(n);
      int tmp = 0;
      while (n > 0) {
        const int digit = n % 10;
        tmp += digit * digit;
        n /= 10;
      }
      n = tmp;
    }
    return n == 1;
  }
};

class Solution_set {
 public:
  // set
  bool isHappy(int n) {
    unordered_set<int> s;
    while (n != 1) {
      int sum = 0;
      while (n) {
        int tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
      }
      n = sum;
      if (s.count(n)) break;
      s.insert(n);
    }
    // if (n != 1)
      // cout << n << endl;
    return n == 1;
  }
};

class Solution_OLD {
 public:
  // math: "happy number" will cycle with (1) or (4,16,37,58,89,145,42,20,4,...)
  bool isHappy(int n) {
    bitset<256> not_happy;
    not_happy[4] = 1; not_happy[16] = 1; not_happy[37] = 1;
    not_happy[58] = 1; not_happy[89] = 1; not_happy[145] = 1;
    not_happy[42] = 1; not_happy[20] = 1;
    while (n != 1) {
      if (n < 146 && not_happy[n])
        return false;
      int sum = 0;
      while (n) {
        int tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
      }
      n = sum;
    }
    return true;
  }
};

int main() {
  Solution s;
  // for (int i=0; i<10000; ++i)
    // s.isHappy(i);
  cout << s.isHappy(11123) << endl;
  return 0;
}
