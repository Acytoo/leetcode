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
  int numFactoredBinaryTrees(vector<int>& arr) {
    constexpr int kMod = 1e9 + 7;
    sort(arr.begin(), arr.end());  // already unique
    unordered_map<int, long> m;
    for (int i = 0, n = arr.size(); i < n; ++i) {
      m[arr[i]] = 1;
      for (int j = 0; j < i; ++j) {
        if (arr[i] % arr[j] == 0 && m.count(arr[i] / arr[j]) != 0)
          m[arr[i]] += m[arr[j]] * m[arr[i] / arr[j]];
      }
    }
    long res = 0;
    for (auto &[k, v] : m) res += v;
    return static_cast<int>(res % kMod);
  }
};

int main() {
  Solution s;
  
  return 0;
}
