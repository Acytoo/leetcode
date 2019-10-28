#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& c) {
    int n = c.size();
    // cout << n << endl;
    if (n == 2)
      return true;
    double k = (double)(c[1][1] - c[0][1]) / (c[1][0] - c[0][0]);
    // cout << k << endl;
    for (int i=2; i<n; ++i) {
      double temp = (double)(c[i][1] - c[0][1]) / (c[i][0] - c[0][0]);
      if (temp != k)
        return false;
    }
    return true;
  }
};


int main() {
  Solution s;
  vector<vector<int>> a = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
  // for (auto col : a)
  //   for (auto row : col)
  //     cout << row << endl;
  cout << s.checkStraightLine(a) << endl;
  return 0;
}
