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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int getKth(int lo, int hi, int k) {
    vector<int> nums (1002);
    for (int i=0; i<=1000; ++i)
      nums[i] = i;
    vector<int> pows (300000, -1);
    pows[1] = 1;
    function<int(int)> get_pow = [&pows](int a) -> int {
                                   int abk = a, res = 0;
                                   while (a != 1) {
                                     if (pows[a] > 0)
                                       return pows[abk] = pows[a] + res;
                                     if (a & 1) {  // odd
                                       a = (a << 1) + a + 1;
                                       // cout << a << endl;
                                     } else {
                                       a >>= 1;
                                     }
                                     ++res;
                                   }
                                   return pows[abk] = res;
                                 };
    sort(nums.begin()+lo, nums.begin()+hi+1, [&](const int a, const int b) {
                                               int aa = get_pow(a), bb = get_pow(b);
                                               return aa != bb? aa < bb: a < b;
                                             });
    // for (int i=lo; i<=hi; ++i)
    //   cout << nums[i] << endl;
    // delete pows;
    return nums[lo+k-1];
  }
};

int main() {
  Solution s;
  cout << s.getKth(1,1000,777) << endl;
  return 0;
}
