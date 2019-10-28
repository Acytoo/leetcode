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

static int _ = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
  struct Point {
    int x;
    int y;
  };
  struct Rect {
    Point p_l;                  // Point at bottom left
    Point p_r;                  // Point at top right
  };
  // Thanks to https://leetcode.com/problems/rectangle-area/discuss/62149/Just-another-short-way
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left = max(A,E), right = max(min(C,G), left);
    int bottom = max(B,F), top = max(min(D,H), bottom);
    return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
  }
};

int main() {
  Solution s;
  int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
  cout << s.computeArea(A, B, C, D, E, F, G, H) << endl;
  return 0;
}
