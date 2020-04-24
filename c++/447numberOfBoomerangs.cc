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
// From Huahua
class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    const int n = points.size();
    vector<int> dist (n);
    int res = 0;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<n; ++j) {
        int dx = points[i][0] - points[j][0],
            dy = points[i][1] - points[j][1];
        dist[j] = dx*dx+dy*dy;
      }
      sort(dist.begin(), dist.end());
      for (int j=1; j<n; ++j) {
        int k = 1;
        while (j<n && dist[j]==dist[j-1]) {++j; ++k;}
        res += k * (k - 1);
      }
    }
    return res;
  }
};

class Solution1 {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    for (int i=0, stop=points.size(); i<stop; ++i) {
      unordered_map<int, int> m (stop);  // since unordered_map is implemented using buckets
      for (int j=0; j<stop; ++j) {
        int dx = points[i][0] - points[j][0],
            dy = points[i][1] - points[j][1];
        ++m[dx*dx+dy*dy];
      }
      for (const auto &kv: m)
        res += kv.second * (kv.second-1);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
