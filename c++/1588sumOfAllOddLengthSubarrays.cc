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
  int sumOddLengthSubarrays(vector<int>& arr) {
    int res = 0;
    for (int i = 0, n = arr.size(); i < n; ++i)
      res += ((i + 1) * (n - i) + 1) / 2 * arr[i];
    return res;
  }
};

class Solution1 {  // Brute force
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int res = 0;
    for (int i = 0, stop = arr.size(); i < stop; ++i) {
      int cur = 0;
      for (int j = i; j < stop; ++j) {
        cur += arr[j];
        if ((j - i + 1) & 1) res += cur;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
