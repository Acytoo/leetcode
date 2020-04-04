#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k %= len;
    if (k == 0)
      return;
    int temp[len] = {0};
    int i=0, j=0;
    for (int i=len - k; i != len; ++i)
      temp[j++] = nums[i];
    for (i=0; j != len; ++j, ++i)
      temp[j] = nums[i];
    for (i=0; i != len; ++i)
      nums[i] = temp[i];

  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3,4,5};
  s.rotate(a, 12);
  for (auto i = a.begin(), stop = a.end(); i != stop; ++i)
    cout << *i << " ";
  cout << endl;
  return 0;
}
