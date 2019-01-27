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
  int minimumTotal(vector<vector<int> > &triangle) {
    int height = triangle.size();
    vector<int> temp(triangle.back());
    for (int row = height-2; row >= 0; --row)
      for (int col = 0; col <= row; ++col)
        temp[col] = min(temp[col], temp[col+1]) + triangle[row][col];
    return temp[0];
  }
};

int main() {
  Solution s;
  vector<vector<int>> a = {{2}, {3,4}, {5,6,7}};
  cout << s.minimumTotal(a) << endl;
  return 0;
}
