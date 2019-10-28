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
  bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
    int left = max(r1[0], r2[0]), right = max(min(r1[2], r2[2]), left),
      bottom = max(r1[1], r2[1]), top = max(min(r1[3], r2[3]), bottom);
    return (right>left)&&(top>bottom);

  }
};

int main() {
  Solution s;
  vector<int> a = {0,0,1,1}, b = {1,0,2,1};
  cout << s.isRectangleOverlap(a, b) << endl;
  return 0;
}
