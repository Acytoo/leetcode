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
  string getPermutation(int n, int k) {
    constexpr int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    vector<int> num {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string res;
    res.reserve(n);
    --k;
    while (n--) {
      int d = k / fact[n];
      k %= fact[n];
      res.push_back(num[d] + '0');
      for (int i = d + 1; i <= 9; ++i) num[i - 1] = num[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
