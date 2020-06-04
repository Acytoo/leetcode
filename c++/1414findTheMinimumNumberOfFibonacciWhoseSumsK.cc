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
// From huahua
class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    if (k == 0) return 0;
    int f1 = 1, f2 = 1;
    while (f2 <= k) {
      swap(f1, f2);
      f2 += f1;
    }
    return 1 + findMinFibonacciNumbers(k - f1);
  }
};

int main() {
  Solution s;
  
  return 0;
}
