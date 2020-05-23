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
  vector<double> sampleStats(vector<int>& count) {
    vector<double> res (5);
    int l = 0, r = 255;
    while (count[l] == 0) ++l;
    while (count[r] == 0) --r;
    res[0] = static_cast<double>(l);  // min
    res[1] = static_cast<double>(r);  // max
    int total = 0, mode = r;
    unsigned long sum = 0;
    while (l <= r) {
      sum += r * count[r];
      total += count[r];
      if (count[r] > count[mode]) mode = r;
      --r;
    }
    res[2] = static_cast<double>(sum) / total;  // mean
    res[4] = static_cast<double>(mode);         // mode

    if (total & 1) {       // odd
      total >>= 1;
      while (total > count[l]) total -= count[l++];
      res[3] = static_cast<double>(l);
    } else {  // even
      total >>= 1;
      while (total > count[l]) total -= count[l++];
      if (total < count[l]) {
        res[3] = static_cast<double>(l);
      } else {
        int i = l + 1;
        while (count[i] == 0) ++i;
        res[3] = (static_cast<double>(l) + i) / 2;
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
