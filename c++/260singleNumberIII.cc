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
  vector<int> singleNumber(vector<int>& nums) {
    int axorb = 0;
    for (const int num: nums)
      axorb ^= num;
    int flag = axorb & -axorb;
    vector<int> res (2);
    for (const int num: nums)
      if (num & flag) res[0] ^= num;
      else res[1] ^= num;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
