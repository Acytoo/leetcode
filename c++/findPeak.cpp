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
  int findPeakElement(vector<int>& nums) {
    int i=0, stop = nums.size(), start = INT_MIN;
    while (i != stop) {
      if (nums[i] < start)
        return --i;
      else
        start = nums[i++];
    }
    return --i;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,6,4,5};
  cout << s.findPeakElement(a) << endl;
  return 0;
}
