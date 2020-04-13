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
  int minDeletionSize(vector<string>& A) {
    int res = 0;
    const int m = A.size(), n = A[0].size();
    for (int j=0; j<n; ++j)
      for (int i=1; i<m; ++i)
        if (A[i][j] < A[i-1][j]) {
          ++res;
          break;
        }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> a = {"zyx","wvu","tsr"};
  a = {"a", "b"};
  cout << s.minDeletionSize(a) << endl;
  return 0;
}
