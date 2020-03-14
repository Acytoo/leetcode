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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    const int n = points.size();
    double res = 0.0;
    for (int i=0; i<n; ++i)
      for (int j=i+1; j<n; ++j)
        for (int k=j+1; k<n; ++k) {
          const double a = dist(points[i], points[j]);
          const double b = dist(points[i], points[k]);
          const double c = dist(points[k], points[j]);
          const double s = (a + b + c) / 2;
          const double area = sqrt(s * (s-a) * (s-b) * (s-c));
          res = max(res, area);
        }
    return res;
  }
 private:
  static inline double dist(const vector<int>& p1, const vector<int>& p2) {
    return sqrt(pow(p1[0]-p2[0], 2)+pow(p1[1]-p2[1], 2));
  }
};

int main() {
  Solution s;
  
  return 0;
}
