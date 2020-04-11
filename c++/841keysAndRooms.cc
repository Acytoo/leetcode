#include <iostream>
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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    const int n = rooms.size();
    bitset<1001> open;
    int count = 0;
    function<void(int)> dfs =
        [&] (int key) {
          if (open[key] == 1) return ;
          open[key] = 1;
          ++count;
          for (int new_key: rooms[key])
            dfs(new_key);
        };

    dfs(0);
    return count == n;
  }
};

int main() {
  Solution s;
  
  return 0;
}
