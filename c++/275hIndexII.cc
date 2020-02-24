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


using namespace std;
// now citations are sorted in ascending order, time cimplexity rquired: O(logn)

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int l = 0, n = citations.size(), r = n - 1, res = 0;
    if (n == 0)
      return 0;
    while (l <= r) {
      int m = (l+r) >> 1;
      if (citations[m] >= (n-m)) {
        res = n - m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {0,1,3,5,6,9,9};
  cout << s.hIndex(a) << endl;
  return 0;
}
