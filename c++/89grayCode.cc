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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// It's not mentioned in question's description, but max n is 21
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> res {0};
    res.reserve(1 << n);
    for (int i=0; i<n; ++i)
      for (int j=res.size()-1; j>=0; --j) {
        int tmp = 1 << i;
        res.push_back(res[j] | tmp);
      }
    return res;
  }
};

int main() {
  Solution s;
  int a;
  while (cin >> a)
    s.grayCode(a);
  return 0;
}
