#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    const int n = A.size();
    if (n < 3) return false;
    int i = 0, lastIter = n - 1;
    while (i != lastIter && A[i] < A[++i]) continue;
    --i;
    if (i == 0 || A[i] == A[i - 1]) return false;
    while (i != lastIter)
      if (A[i] <= A[++i]) return false;
    return true;
  }
};

int main() {
  vector<int> a = {3,2,1};
  Solution s;
  cout << s.validMountainArray(a) << endl;
  return 0;
}
