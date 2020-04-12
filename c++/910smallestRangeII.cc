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
  int smallestRangeII(vector<int>& A, int K) {
    const int n = A.size();
    sort(A.begin(), A.end());
    // int sum = accumulate(A.begin(), A.end(), 0);
    // int ave = sum / n;
    // for (int &a: A) {
    //   if (a <= ave) {
    //     a += K;
    //   } else {
    //     a -= ave;
    //   }
    // }
    // [1,2,3,4,5,987651234]: ...
    int res = A.back() - A.front();
    for (int i=1; i<n; ++i) {
      int l = min(A.front() + K, A[i] - K);
      int h = max(A.back() - K, A[i-1] + K);
      res = min(res, h-l);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
