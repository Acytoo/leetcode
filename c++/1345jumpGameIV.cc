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

// BFS
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua
class Solution {
 public:
  int minJumps(vector<int>& arr) {
    const int n = arr.size(), nn = n - 1;
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) m[arr[i]].emplace_back(i);
    vector<int> seen (n);
    queue<int> q ({0});
    seen[0] = 1;
    int res = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int i = q.front(); q.pop();
        if (i == nn) return res;
        if (i - 1 >= 0 && !seen[i - 1]++) q.push(i - 1);
        if (i + 1 < n && !seen[i + 1]++) q.push(i + 1);
        auto it = m.find(arr[i]);
        if (it == m.end()) continue;
        for (const int next : it->second)
          if (!seen[next]++)
            q.push(next);
        m.erase(it);
      }
      ++res;
    }
    return nn;
  }
};

int main() {
  Solution s;
  
  return 0;
}
