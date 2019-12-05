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
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res(2, 0);
    int len = nums.size();
    if (len <= 1) return res;
    unordered_map<int, int> dict;
    for (int i=0; i<len; ++i) {
      int num = nums[i];
      int val = target - num;
      auto it = dict.find(val);
      if (it != dict.end()) {
        res[0] = i;
        res[1] = it->second;
        return res;
      } else {
        dict.insert({num, i});
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<int> a = {2, 5, 11, 15};
  int tar = 16;
  vector<int> res = s.twoSum(a, tar);
  cout << res[0] << " " << res[1] << endl;
  return 0;
}
