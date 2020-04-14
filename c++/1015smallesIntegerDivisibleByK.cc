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
// 17 -> 16
// 23 -> 22
class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    int last_digit = K % 10;
    if (!(last_digit == 1 || last_digit == 3 ||
          last_digit == 7 || last_digit == 9))
      return -1;
    bitset<100001> rem;
    int res = 1, N = 1;
    while (true) {
      N = N % K;
      if (N == 0)
        return res;
      if (rem[N])
        return -1;
      rem[N] = 1;
      N = N * 10 + 1;
      ++res;
    }
  }
};

int main() {
  Solution s;
  cout << s.smallestRepunitDivByK(17) << endl;
  return 0;
}
