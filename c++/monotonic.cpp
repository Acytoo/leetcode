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
  bool isMonotonic(vector<int>& A) {
    int n = A.size();
    if (n <= 2)
      return true;
    int i = 0, lastIter = n - 1;
    while (i != lastIter && A[i] == A[++i])
    if (i == lastIter)
      return true;
    --i;
    // i became the first iter of different values
    // cout << i << endl;

    if (A[i] < A[++i]) {
      while (i != lastIter) {
        if (A[i] > A[++i])
          return false;
      }
    }
    else {
      while (i != lastIter) {
        if (A[i] < A[++i])
            return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,1,2,2,3};
  cout << s.isMonotonic(a) << endl;
  return 0;
}
