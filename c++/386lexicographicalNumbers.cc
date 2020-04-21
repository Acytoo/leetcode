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
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> res (n);
    int cur = 1;
    for (int i=0; i<n; ++i) {
      res[i] = cur;
      if (cur*10 <= n) {
        cur *= 10;
      } else {
        if (cur >= n) cur /= 10;
        cur += 1;
        while (cur%10 == 0) cur /= 10;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  for (int i: s.lexicalOrder(133))
    cout << i << " ";
  cout << endl;
  return 0;
}
