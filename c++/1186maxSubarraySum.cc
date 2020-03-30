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
class Solution {
 public:
  int maximumSum(vector<int>& arr) {
    const int n = arr.size();
    vector<int> all(n), part(n);
    int res = arr[0];
    all[0] = arr[0];
    part[0] = -1e5;

    for (int i=1; i<n; ++i) {
      all[i] = max(all[i-1] + arr[i], arr[i]);
      part[i] = max(part[i-1]+arr[i], all[i-1]);
      res = max({res, all[i], part[i]});
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a {1,-2,-2,3};
  cout << s.maximumSum(a) << endl;
  return 0;
}
