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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findComplement(int num) {
    if (num == 0) return 1;

    bitset<32> bits;
    int i = -1, res = 0;
    while (num) {
      bits[++i] = !(num & 1);
      num >>= 1;
    }
    while (i && !bits[i]) --i;
    while (i >= 0)
      res = (res << 1) | bits[i--];
    return res;
  }
};

class Solution1 {
 public:
  int findComplement(int num) {
    if (num == 0) return 1;
    vector<int> bits (32);
    int i = -1;
    while (num) {
      int bi = num & 1;
      num >>= 1;
      bits[++i] = !bi;
    }
    while (i && bits[i] == 0) --i;
    int res = 0;
    for (int j=i; j>=0; --j) {
      res <<= 1;
      res |= bits[j];
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.findComplement(12345) << endl;
  return 0;
}
