#include <iostream>
#include <vector>
using namespace std;



static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution {
public:
  bool canJump(vector<int>& nums) {
    
    int n = nums.size() - 1;
    if (n < 1)
      return true;
    
    if (nums[0] == 0)
      return false;

    --n;
    
    while (n) {
      while (n > -1 && nums[n--] > 0);
      if (n < 1)
	return nums[1]+nums[0]-1;
      int temp = 1;
      while (n > -1 && nums[n--] < ++temp);
      if (n < 0)
	return nums[0] >= temp;
    }
    return true;
  }
};

int main() {
  
  vector <int> a = {1,0,2};
  Solution s;
  cout << s.canJump(a) << endl;
  return 0;
}
