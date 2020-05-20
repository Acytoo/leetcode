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
  // BFS
 public:
  vector<int> numsSameConsecDiff(int N, int K) {
    deque<int> dq {1,2,3,4,5,6,7,8,9};
    if (N == 1) dq.push_front(0);
    while (--N) {
      int tmp = dq.size();
      while (tmp--) {
        int cur = dq.front(),
     last_digit = cur % 10,
       new_base = cur * 10 + last_digit;
        dq.pop_front();

        if (last_digit + K < 10)
          dq.push_back(new_base + K);
        if (K != 0 && K <= last_digit)
          dq.push_back(new_base - K);
      }
    }
    return vector<int> (dq.begin(), dq.end());
  }
};

class Solution1 {
  // DFS
 public:
  vector<int> numsSameConsecDiff(int N, int K) {
    vector<int> res;
    function<void(int, int)> dfs =
        [&] (int cur, int n) {
          if (n == 0) {
            res.emplace_back(cur);
            return ;
          }
          int last_digit = cur % 10,
                new_base = cur * 10 + last_digit;

          if (last_digit + K < 10)
            dfs(new_base + K, n - 1);
          if (K != 0 && K <= last_digit)
            dfs(new_base - K, n - 1);
        };

    if (N == 1) res.emplace_back(0);
    for (int i = 1; i <= 9; ++i)
      dfs(i, N - 1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
