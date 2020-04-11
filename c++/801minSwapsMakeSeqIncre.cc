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
  int minSwap(vector<int>& A, vector<int>& B) {
    int k1 = 0, s1 = 1;
    for (int i=1, n=A.size(); i<n; ++i) {
      int j = i - 1, k2 = INT_MAX, s2 = INT_MAX;
      if (A[i] > A[j] && B[i] > B[j]) {
        k2 = k1;
        s2 = s1 + 1;
      }
      if (B[i] > A[j] && A[i] > B[j]) {
        s2 = min(s1, k1 + 1);
        k2 = min(k2, s1);
      }
      s1 = s2; k1 = k2;
    }
    return min(s1, k1);
  }
};

class Solution1 {
 public:
  int minSwap(vector<int>& A, vector<int>& B) {
    const int n = A.size();
    vector<int> keep (n, INT_MAX), swap (n, INT_MAX);

    keep[0] = 0;
    swap[0] = 1;

    for (int i=1; i<n; ++i) {
      int j = i - 1;
      if (A[i] > A[j] && B[i] > B[j]) {
        keep[i] = keep[j];
        swap[i] = swap[j] + 1;
      }
      if (B[i] > A[j] && A[i] > B[j]) {
        swap[i] = min(swap[i], keep[j] + 1);
        keep[i] = min(keep[i], swap[j]);
      }
    }
    return min(swap.back(), keep.back());
  }
};

int main() {
  Solution s;
  
  return 0;
}
