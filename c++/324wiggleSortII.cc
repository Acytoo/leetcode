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
  void wiggleSort(vector<int>& nums) {
    vector<int> bk (nums);
    sort(bk.begin(), bk.end());
    for (int i=0, n=bk.size(), j=n, k=(n+1)>>1; i<n; ++i)
      nums[i] = i & 1? bk[--j] : bk[--k];
  }
};

int main() {
  Solution s;
  
  return 0;
}
