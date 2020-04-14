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
// max A[i] + A[j] + i - j --> (A[i] + i) + (A[j] - j) -x> xx(A[i] + i) + (A[j] + j) - 2*j
class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& A) {
    const int n = A.size();
    vector<int> cur_max (n);
    cur_max[0] = A[0];
    for (int i=1; i<n; ++i)
      cur_max[i] = max(cur_max[i-1], A[i]+i);
    int res = cur_max[0] + A[1] - 1;
    for (int i=2; i<n; ++i)
      res = max(res, cur_max[i-1] + A[i] - i);
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {8,1,5,2,6};
  cout << s.maxScoreSightseeingPair(a) << endl;
  return 0;
}
