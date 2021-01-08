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
  // Brute force
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    const int n = customers.size();
    long waiting_total = customers[0][1], finish = customers[0][0] + waiting_total;
    for (int i = 1; i < n; ++i) {
      if (customers[i][0] < finish) {
        finish = finish + customers[i][1];
        waiting_total += finish - customers[i][0];
      } else {
        finish = customers[i][0] + customers[i][1];
        waiting_total += customers[i][1];
      }
    }
    return static_cast<double>(waiting_total) / n;
  }
};

int main() {
  Solution s;
  
  return 0;
}
