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

// stupid solution: merge and sort
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i=0; i != n; ++i)
      nums1[m+i] = nums2[i];
    sort(nums1.begin(), nums1.begin() + m + n);
  }
};

int main() {
  Solution s;
  vector<int> a = {1,2,3,4, 8,9,0, 1}, b = {5,6,7};
  s.merge(a, 4, b, 3);
  for (int i=0; i != 7; ++i)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}
