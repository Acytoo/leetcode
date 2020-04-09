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
class Solution {
 public:
  int flipLights(int n, int m) {
    if (m == 0) return 1;
    // if (n == 0) return m == 1? 3: 4;  // Don't know why, but you can test it in leetcode's console

    if (n == 1) return 2;
    if (n == 2) return m == 1? 3: 4;

    // n >= 3
    if (m == 1) return 4;
    return m == 2? 7: 8;
  }
};

int main() {
  Solution s;
  
  return 0;
}
