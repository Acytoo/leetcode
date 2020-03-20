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
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Polar coordinate
class Solution {
 public:
  Solution(double r, double x, double y): r_(r), x_(x), y_(y) { }
  vector<double> randPoint() {
    double r = sqrt(rand() / static_cast<double>(RAND_MAX)) *  r_;
    double a = rand() / static_cast<double>(RAND_MAX) * M_PI * 2;
    return {x_+r*cos(a), y_+r*sin(a)};
  }
 private:
  double r_, x_, y_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main() {
  Solution s;
  
  return 0;
}
