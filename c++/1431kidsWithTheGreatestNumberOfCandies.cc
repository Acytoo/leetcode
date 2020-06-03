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
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    const int max_cans = *max_element(candies.begin(), candies.end()),
                     n = candies.size();
    vector<bool> res;
    res.reserve(n);
    for (const int can: candies)
      res.emplace_back(can + extraCandies >= max_cans);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
