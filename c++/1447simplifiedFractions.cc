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
  vector<string> simplifiedFractions(int n) {
    if (n == 1) return {};
    vector<string> res {"1/2"};
    for (int i = 3; i <= n; ++i) {
      res.emplace_back("1/" + to_string(i));
      for (int j = 2; j < i; ++j)
        if (gcd(j, i) == 1)
          res.emplace_back(to_string(j) + "/" + to_string(i));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
