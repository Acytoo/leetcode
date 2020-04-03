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
// two pointers or STL???
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    return unique(nums.begin(), nums.end()) - nums.begin();
  }
};


int main() {
  Solution s;
  vector<int> a = {1,1,2,2,3,4,4,6,8,9,9};
  int b = s.removeDuplicates(a);
  cout << b << endl;
  for (int i=0; i != b; ++i)
    cout << a[i] << " ";
  cout << endl;

  return 0;
}
