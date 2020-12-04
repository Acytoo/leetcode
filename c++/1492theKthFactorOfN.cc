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
// brute force
class Solution {
public:
  int kthFactor(int n, int k) {
    for (int i = 1; i <= n; ++i) {
      if (n % i != 0) continue;
      --k;
      if (k == 0) return i;
    }
    return -1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
