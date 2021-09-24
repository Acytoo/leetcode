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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>


using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int tribonacci(int n) {
    int res;
    if (n == 0)
      return 0;
    if (n <= 2)
      return 1;
    int a = 0, b = 1, c = 1;
    while (n-- >= 3) {
      int tmp = a + b + c;
      a = b;
      b = c;
      c = tmp;
    }
    return c;
  }
};

int main() {
  Solution s;
  
  return 0;
}
