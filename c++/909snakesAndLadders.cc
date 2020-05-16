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
class Solution {
 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    const int n = board.size(), nn = n * n;
    int res = 0, x = 0, y = 0;
    bitset<401> visited; // 2 <= m = n <= 20 --> N <= 400
    function<void(int)> to_index =
        [&x, &y, n] (const int num) {
          int tmp = (num + n - 1) / n;
          x = n - tmp;
          y = (num - 1) % n;
          if ((tmp & 1) == 0) y = n - y - 1;
        };
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
      int size_bk = q.size();
      ++res;
      while (size_bk--) {
        int cur = q.front(); q.pop();
        for (int next = cur + 1, stop = min(cur + 6, nn); next <= stop; ++next) {
          to_index(next);
          int nextt = next;
          if (board[x][y] != -1) nextt = board[x][y];
          if (visited[nextt]) continue;
          if (nn == nextt) return res;
          q.push(nextt);
          visited[nextt] = 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<vector<int>> a (6, vector<int> (6));
  cout << s.snakesAndLadders(a) << endl;
  return 0;
}
