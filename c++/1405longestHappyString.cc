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

// Greedy
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua
class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    string res = "";
    vector<int> freq {a, b, c}, len {0, 0, 0};
    const int total = a + b + c;
    for (int _ = 0; _ < total; ++_)
      for (int i = 0; i < 3; ++i) {
        const int j = (i + 1) % 3,
                  k = (i + 2) % 3;
        if ((freq[i] >= freq[j] && freq[i] >= freq[k] && len[i] != 2) ||
            (freq[i] > 0 && (len[j] == 2 || len[k] == 2))) {
          res += 'a' + i;
          ++len[i];
          --freq[i];
          len[j] = len[k] = 0;
          break;
        }
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
