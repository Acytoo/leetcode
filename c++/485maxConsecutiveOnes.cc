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
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0, l = -1, i = 0;
    bool has_one = false;
    for (int stop=nums.size(); i<stop; ++i) {
      if (nums[i] == 0) {
        if (has_one)
          res = max(res, i - l - 1);
        l = i;
        has_one = false;
      } else {
        has_one = true;
      }
    }
    return max(res, i - l - 1);
  }
};

int main() {
  Solution s;
  vector<int> a  = {1,0,1};
  cout << s.findMaxConsecutiveOnes(a) << endl;
  return 0;
}
