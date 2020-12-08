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
  string getSmallestString(int n, int k) {
    string res (n, 'a');
    k -= n;
    for (int i = n - 1; i >= 0; --i) {
      const int inc = min(k, 25);
      res[i] += inc;
      k -= inc;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
