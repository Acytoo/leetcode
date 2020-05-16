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
  int threeSumMulti(vector<int>& A, int target) {
    constexpr int kMod = 1e9 + 7;
    long count[101];  // 0 <= A[i] <= 100
    memset(count, 0, sizeof(count));
    for (const int a: A) ++count[a];
    long res = 0;

    for (int i = 0, stop = min(100, target); i <= stop; ++i) {
      if (count[i] == 0) continue;
      for (int j = i; j <= stop; ++j) {
        if (count[j] == 0) continue;
        const int k = target - i - j;
        if (k < 0 || k > 100 || count[k] == 0 || k < j) continue;
        if (i == j && i == k)
          res += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
        else if (i == j && i != k)
          res += count[i] * (count[i] - 1) / 2 * count[k];
        else if (i != j && j == k)
          res += count[i] * count[j] * (count[j] - 1) / 2;
        else
          res += count[i] * count[j] * count[k];
      }
    }

    return res % kMod;
  }
};

// same runtime, same memory
class Solution_same {
 public:
  int threeSumMulti(vector<int>& A, int target) {
    constexpr int kMod = 1e9 + 7;
    int count[101];  // 0 <= A[i] <= 100
    memset(count, 0, sizeof(count));
    for (const int a: A) ++count[a];
    long res = 0;

    for (int i = 0, stop = min(100, target); i <= stop; ++i) {
      if (count[i] == 0) continue;
      for (int j = i; j <= stop; ++j) {
        if (count[j] == 0) continue;
        const int k = target - i - j;
        if (k < 0 || k > 100 || count[k] == 0 || k < j) continue;
        if (i == j && i == k)
          res += static_cast<long>(count[i]) * (count[i] - 1) * (count[i] - 2) / 6;
        else if (i == j && i != k)
          res += static_cast<long>(count[i]) * (count[i] - 1) / 2 * count[k];
        else if (i != j && j == k)
          res += static_cast<long>(count[i]) * count[j] * (count[j] - 1) / 2;
        else
          res += static_cast<long>(count[i]) * count[j] * count[k];
      }
    }

    return res % kMod;
  }
};

int main() {
  Solution s;
  
  return 0;
}
