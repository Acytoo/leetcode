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
  int maximumCandies(vector<int>& candies, long long k) {
    int l = 0, r = *max_element(candies.begin(), candies.end()) + 1; // O(n)
    while (l < r) {
      const int m = l + (r - l) / 2;
      if (m == 0) return 0;
      long long  total = 0;
      for (const int c : candies)
        total += (c / m);
      if (total >= k)
        l = m + 1;
      else
        r = m;
    }
    return l - 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
