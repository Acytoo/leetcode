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
  int removeElement(vector<int>& nums, int val) {
    int i=0, stop = nums.size(), j=0;
    for (; i != stop; ++i)
      if (val != nums[i])
        nums[j++] = nums[i];
    return j;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3,4,5,3,3,6,7};
  int b = s.removeElement(a, 3);
  for (int i=0; i != b; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
