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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    long sum = 0;
    int n = nums.size();
    for (int i=0; i<k; ++i)
      sum += nums[i];
    long res = sum;
    for (int i=k, stop=nums.size(); i<stop; ++i) {
      sum = sum-nums[i-k]+nums[i];
      res = max(res, sum);
    }
    return (double)res / k;
  }
};

int main() {
  Solution s;
  
  return 0;
}
