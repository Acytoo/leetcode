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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 2 <= arr.length <= 500
// -10^3 <= arr[i] <= 10^3
class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    vector<bool> neg(2001, false);
    vector<bool> pos(2001, false);
    bool zero = false;
    for (int i: arr) {
      if (i < 0) {
        i = - i;
        if (neg[i])
          return true;
        neg[i<<1] = true;
        if ((i & 1) == 0)
          neg[i>>1] = true;
      } else if (0 < i) {
        if (pos[i])
          return true;
        pos[i<<1] = true;
        if ((i & 1) == 0)
          pos[i>>1] = true;
      } else {
        if (zero)
          return true;
        zero = true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
