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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int a = 0, b = 0, ca = 0, cb = 0;
    for (const int num: nums) {
      if (num == a) {
        ++ca;
      } else if (num == b) {
        ++cb;
      } else if (ca == 0) {
        a = num;
        ca = 1;
      } else if (cb == 0) {
        b = num;
        cb = 1;
      } else {
        --ca; --cb;
      }
    }

    ca = 0; cb = 0;
    for (const int num: nums) {
      if (num == a) ++ca;
      else if (num == b) ++cb;
    }
    const int c = nums.size() / 3;
    vector<int> res;
    if (c < ca) res.push_back(a);
    if (c < cb) res.push_back(b);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
