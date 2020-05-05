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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (newColor == oldColor) return image;

    const int m = image.size(), n = image[0].size();
    vector<int> dirs = {1, 0, -1, 0, 1};
    function<void(int, int)> dfs =
        [&] (int x, int y) {
          if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] != oldColor) return ;
          image[x][y] = newColor;
          for (int i = 0; i < 4; )
            dfs(x + dirs[i], y + dirs[++i]);
        };
    dfs(sr, sc);
    return image;
  }
};

int main() {
  Solution s;
  
  return 0;
}
