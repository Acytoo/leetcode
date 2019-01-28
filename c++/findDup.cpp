#include <iostream>
#include <vector>
#include <set>

using namespace std;

static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();

// O(1) space
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    for (int i=0; i < nums.size(); i++) {
      if (nums[abs(nums[i])] > 0) {
        nums[abs(nums[i])] = - nums[abs(nums[i])];
      }
      else
	return abs(nums[i]);
    }
    return -1;
  }
};

// not O(1) space
class Solution1 {
public:
  int findDuplicate(vector<int>& nums) {
    set<int> myset;
    pair<set<int>::iterator,bool> ret;
    for (auto it = nums.cbegin(); it != nums.cend(); it++) {
      ret = myset.insert(*it);
      if (ret.second == false)
	return *it;
    }
    return -1;
  }
};

int main() {
  vector<int> a = {3,1,3,4,2};
  Solution1 s;
  cout << s.findDuplicate(a) << endl;
  return 0;
}
