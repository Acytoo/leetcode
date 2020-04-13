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

// A[2 * i + 1] = 2 * A[2 * i] for every 0 <= i < len(A) / 2
// A[1] = 2 * A[0]
// A[3] = 2 * A[2]
// A[5] = 2 * A[4]

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool canReorderDoubled(vector<int>& A) {
    map<int, int> m;  // num --> count
    for (const int a: A)
      if (a & 1)
        m[a*2] -= 1;
      else
        m[a] += 1;

    for (auto it=m.begin(); it!=m.end(); ++it) {
      if (it->second < 0) return false;
      if (it->second == 0) continue;
      if (it->first > 0)
        m[(it->first)*2] -= it->second;
      else
        m[(it->first)/2] -= it->second;
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> a = {-2,-2,1,-2,-1,2};
  // a = {-2, -4};
  cout << s.canReorderDoubled(a) << endl;
  return 0;
}
