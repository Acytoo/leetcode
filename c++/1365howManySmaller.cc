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


using namespace std;
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100
// So this question is much more easier
class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> dic (101, 0);
    for (int i: nums)
      ++dic[i];
    // using function in <numeric>
    partial_sum(dic.begin(), dic.end(), dic.begin());
    for (int& i: nums)
      i = i == 0? 0: dic[i-1];
    return nums;
  }
};

class Solution1 {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> dic (101, 0);
    for (int i: nums)
      ++dic[i];
    vector<int> dicc (101, 0);
    for (int i=1; i<101; ++i) {
      dicc[i] = dicc[i-1] + dic[i-1];
    }
    int n = nums.size();
    vector<int> res (n, 0);
    for (int i=0; i<n; ++i)
      res[i] = dicc[nums[i]];
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,3,4,6};
  vector<int> res = s.smallerNumbersThanCurrent(a);
  for (int i: res)
    cout << i << " ";
  cout << endl;
  return 0;
}
