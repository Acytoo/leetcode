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
  // From huahua
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    const int n = apples.size();
    using P = pair<int, int>; // typedef rotten day --> index
    priority_queue<P, vector<P>, greater<P>> pq;
    int res = 0;
    for (int d = 0; d < n || !pq.empty(); ++d) {
      if (d < n && apples[d]) pq.emplace(d + days[d], d);
      while (!pq.empty() && (pq.top().first <= d || apples[pq.top().second] == 0)) pq.pop();
      if (pq.empty()) continue;
      --apples[pq.top().second];
      ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
