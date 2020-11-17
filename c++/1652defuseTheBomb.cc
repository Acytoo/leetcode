#include <iostream>
#include <sstream>
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
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    const int n = code.size();
    vector<int> res (n, 0);
    if (k == 0) return res;

    vector<int> tmp;
    tmp.insert(tmp.end(), code.begin(), code.end());
    tmp.insert(tmp.end(), code.begin(), code.end());

    if (k > 0) {
      int sum = accumulate(code.begin() + 1, code.begin() + 1 + k, 0);
      res[0] = sum;
      for (int i = 1; i < n; ++i)
        res[i] = sum = sum - tmp[i] + tmp[i + k];
    } else if (k < 0) {
      int sum = accumulate(code.rbegin() + 1, code.rbegin() + 1 - k, 0);
      res[n - 1] = sum;
      for (int i = n - 2; i >= 0; --i)
        res[i] = sum = sum - tmp[n + i] + tmp[n + i + k];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
