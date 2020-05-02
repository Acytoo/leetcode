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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    auto dist =
        [] (const vector<int> &p1, const vector<int> &p2) {
          const int dx = p2[0] - p1[0], dy = p2[1] - p1[1];
          return dx*dx + dy*dy;
        };
    unordered_set<int> s {dist(p1, p2), dist(p1, p3), dist(p1, p4),
                          dist(p2, p3), dist(p2, p4), dist(p3, p4)};
    return s.count(0) == 0 && s.size() == 2;
  }
};


class Solution_WRONG {
 public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    auto dist =
        [] (const vector<int> &p1, const vector<int> &p2) {
          const int dx = p2[0] - p1[0], dy = p2[1] - p1[1];
          return dx*dx + dy*dy;
        };
    auto vertical =
        [] (const vector<int> &p1, const vector<int> &p3,
            const vector<int> &p2, const vector<int> &p4) {
          // return (p3[1]-p2[1]) * (p4[1]-p1[1]) == (p3[0]-p2[0]) * (p1[0]-p4[0]);
          return (p4[1]-p2[1]) * (p1[0]-p3[0]) == (p4[0]-p2[0]) * (p3[1]-p1[1]);
        };
    cout << vertical(p1, p2, p3, p4) << " vertical " << endl;
    return (vertical(p1, p2, p3, p4) && dist(p1, p2)==dist(p3, p4)) ||
        (vertical(p1, p3, p2, p4) && dist(p1, p3)==dist(p2, p4));
  }
};

int main() {
  Solution s;
  vector<int> p1={1, 0},
              p2={0, 1},
              p3={-1, 0},
              p4={0, -1};
  // p1 = {0, 0};
  // p2 = {1, 1};
  // p3 = {0, 1};
  // p4 = {1, 0};
  cout << s.validSquare(p1, p2, p3, p4) << endl;
  return 0;
}
