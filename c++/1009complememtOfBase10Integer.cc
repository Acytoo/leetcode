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
  int bitwiseComplement(int N) {
    if (N == 0) return 1;

    bitset<32> bits;
    int i = -1, res = 0;
    while (N) {
      bits[++i] = !(N & 1);
      N >>= 1;
    }
    while (i && !bits[i]) --i;
    while (i >= 0)
      res = (res << 1) | bits[i--];
    return res;
  }
};

int main() {
  Solution s;
  cout << s.bitwiseComplement(7) << endl;
  return 0;
}
