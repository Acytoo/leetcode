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
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> counts {{0, 1}};
    int sum = 0, res = 0;
    for (int num: nums) {
      sum += num;
      res += counts[sum-k];
      ++counts[sum];
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,1,1,2,1,1,1};
  cout << s.subarraySum(a, 2) << endl;
  return 0;
}
