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
  double knightProbability(int N, int K, int r, int c) {
    vector<vector<double>> dp0 (N, vector<double> (N, 0.0));
    dp0[r][c] = 1.0;
    vector<vector<int>> dirs = {{2, 1}, {2, -1}, {1, -2}, {-1, -2},
                                {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}};
    for (int k=0; k<K; ++k) {
      vector<vector<double>> dp1 (N, vector<double> (N, 0.0));
      for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
          for (const auto &dir: dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x<0 || x>=N || y<0 || y>=N) continue;
            dp1[i][j] += dp0[x][y];
          }
      swap(dp0, dp1);
    }
    double total = 0.0;
    for (int i=0; i<N; ++i)
      for (int j=0; j<N; ++j)
        total += dp0[i][j];
    cout << total << endl;
    cout << pow(8, K) << endl;
    return total / pow(8, K);
  }
};


int main() {
  Solution s;
  cout << s.knightProbability(3, 2, 0, 0) << endl;
  return 0;
}
