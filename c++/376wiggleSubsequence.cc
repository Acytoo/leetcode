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
  int wiggleMaxLength(vector<int>& nums) {
    int p = 1, q = 1;
    const int n = nums.size();
    for (int i=0, stop=n-1; i<stop; ) {
      int tmp = nums[i] - nums[++i];
      if (tmp < 0)
        p = q + 1;
      else if (0 < tmp)
        q = p + 1;
    }
    return min(n, max(p, q));
  }
};

int main() {
  Solution s;
  vector<int> a = {1,17,5,10,13,15,10,5,16,8};
  a = {1,2,3,4,5,6,7,8,9};
  a = {1,7,4,9,2,5};
  a = {1,1,1,1,1,1};
  a = {1,2,2,2,2,3};
  a = {1,17,5,10,13,15,10,5,16,8};
  a = {3,3,3,2,5};
  cout << s.wiggleMaxLength(a) << endl;
  return 0;
}
