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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    sort(points.begin(), points.end(),
         [&] (const vector<int> &a, const vector<int> &b) {
           return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
         });
    return vector<vector<int>> (points.begin(), points.begin()+K);
  }
};

int main() {
  Solution s;
  
  return 0;
}
