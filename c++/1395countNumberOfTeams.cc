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
// 1 <= n <= 200
// 1 <= rating[i] <= 10^5
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int res = 0;
    for (int i = 0, n = rating.size(); i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        for (int k = j + 1; k < n; ++k)
          if (rating[i] < rating[j] && rating[j] < rating[k] ||
              rating[i] > rating[j] && rating[j] > rating[k])
            ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
