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
  int singleNumber(vector<int>& nums) {
    int res = 0;
    for (const int num: nums)
      res ^= num;
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3,4,5,4,3,2,1};
  cout << s.singleNumber(a) << endl;
  return 0;
}
