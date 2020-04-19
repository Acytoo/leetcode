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
  int maxProduct(vector<string>& words) {
    const int n = words.size();
    vector<int> mask(n);
    int res = 0;
    for (int i=0; i<n; ++i) {
      for (const char c: words[i])
        mask[i] |= 1 << (c-'a');

      for (int j=0; j<i; ++j)
        if (!(mask[j] & mask[i]))
          res = max(res, static_cast<int>(words[i].size() * words[j].size()));
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
