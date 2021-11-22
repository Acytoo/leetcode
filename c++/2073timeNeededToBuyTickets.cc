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
  int timeRequiredToBuy(vector<int>& tickets, int k) {
    int res = 0;
    while (tickets[k] != 1) {
      for (auto &a : tickets)
        if (--a >= 0) ++res;
    }
    for (int i = 0; i <= k; ++i)
      if (tickets[i] > 0) ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
