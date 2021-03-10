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
  int minOperations(vector<int>& nums) {
    int minu = 0, div = 0;
    for (auto a : nums) {
      int cur_div = 0;
      while (a > 0) {
        if (a & 1) {
          ++minu;
          --a;
        }
        if (a > 0) {
          ++cur_div;
          a >>= 1;
        }
      }
      div = max(div, cur_div);
    }
    return div + minu;
  }
};


int main() {
  Solution s;
  
  return 0;
}
