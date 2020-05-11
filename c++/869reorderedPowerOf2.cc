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
  bool reorderedPowerOf2(int N) {
    auto getDigits = [] (int n) {
                       map<int, int> res;
                       while (n) {
                         ++res[n % 10];
                         n /= 10;
                       }
                       return res;
                     };
    auto target = getDigits(N);
    for (int i = 0; i < 31; ++i)
      if (target == getDigits(1 << i))
        return true;
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
