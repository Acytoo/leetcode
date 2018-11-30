#include <iostream>
#include <vector>
using namespace std;

static int x =  []() {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int count = 0, lastNum = -10;
    for (auto iter = nums.cbegin(); iter != nums.cend();) {
      if (*iter != lastNum) {
	count = 0;
	lastNum = *iter;
	iter++;
      }
      else if (count < 1) {
	count++;
	iter++;
      }
      else {
	iter = nums.erase(iter);
      }
    }
    // for (auto it = nums.cbegin(); it != nums.cend(); it++)
    //   cout << *it << " " ;
    // cout << endl;
    return nums.size();
  }
};

int main() {
  vector<int> a = {1,1,1,1,1,2,3,4,4,4,4};
  Solution s;
  cout << s.removeDuplicates(a) << endl;
  return 0;
}
