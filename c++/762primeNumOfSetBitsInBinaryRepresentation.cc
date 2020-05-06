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

using namespace std;
// max int 2147483647
// L, R will be integers L <= R in the range [1, 10^6], less than 32 bit
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int countPrimeSetBits(int L, int R) {
    bitset<32> prime;
    prime[2] = 1; prime[3] = 1; prime[5] = 1; prime[7] = 1; prime[11] = 1; prime[13] = 1;
    prime[17] = 1; prime[19] = 1; prime[23] = 1; prime[29] = 1; prime[31] = 1;
    int res = 0;
    for (int i = L; i <= R; ++i) {
      int n = i, count = 0;
      while (n) {
        ++count;
        n &= n - 1;
      }
      if (prime[count]) ++res;
    }
    return res;
  }
};

class Solution1 {
 public:
  int countPrimeSetBits(int L, int R) {
    bitset<32> prime;
    prime[2] = 1; prime[3] = 1; prime[5] = 1; prime[7] = 1; prime[11] = 1; prime[13] = 1;
    prime[17] = 1; prime[19] = 1; prime[23] = 1; prime[29] = 1; prime[31] = 1;
    int res = 0;
    for (int i = L; i <= R; ++i) {
      int n = i, count = 0;
      while (n) {
        count += n & 1;
        n >>= 1;
      }
      if (prime[count]) ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.countPrimeSetBits(6, 15) << endl;
  return 0;
}
