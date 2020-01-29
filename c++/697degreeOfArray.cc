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
  int findShortestSubArray(vector<int>& nums) {
    if (nums.size() == 1)
      return 1;
    if (nums.size() == 2)
      if (nums[1] == nums[0])
        return 2;
      else
        return 1;

    int dic[50000] {0};
    for (int i: nums)
      ++dic[i];
    int max_num = 0;
    vector<int> maxs = {0};
    for (int i=1; i<50000; ++i) {
      if (dic[max_num] < dic[i]) {
        max_num = i;
        maxs = {i};
      } else if (dic[max_num] == dic[i]) {
        maxs.push_back(i);
      }
    }
    int res = findLen(nums, maxs[0]);
    for (int i=1, stop=maxs.size(); i<stop; ++i) {
      int tmp = findLen(nums, maxs[i]);
      if (tmp < res)
        res = tmp;
    }
    return res;
  }

 private:
  inline int findLen(vector<int>& nums, int n) {
    int start = 0;
    for (int stop = nums.size(); start<stop; ++start)
      if (nums[start] == n)
        break;
    for (int i=nums.size()-1; i>=start; --i)
      if (nums[i] == n)
        return i-start+1;
    return INT_MAX;
  }
};

int main() {
  Solution s;
  vector<int> a = {49999,0,0};
  cout << s.findShortestSubArray(a) << endl;
  return 0;
}
