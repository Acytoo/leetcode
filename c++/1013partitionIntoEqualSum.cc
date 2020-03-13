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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool canThreePartsEqualSum(vector<int>& A) {
    int n = A.size() - 1;
    for (int i=1; i<=n; ++i)
      A[i] += A[i-1];
    if ((A[n] % 3) != 0)
      return false;
    int one = A[n] / 3, two = one<<1;
    bool has_one = false;
    for (int i=0; i<=n; ++i) {
      if (has_one && A[i] == two && i != n)
        return true;
      if (A[i] == one)
        has_one = true;
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
