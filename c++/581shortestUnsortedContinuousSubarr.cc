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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    vector<int> bk (nums);
    sort(bk.begin(), bk.end());
    int i = 0, j = nums.size()-1;
    while (i<=j && nums[i]==bk[i]) ++i;
    while (j>=i && nums[j]==bk[j]) --j;
    return j - i + 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
