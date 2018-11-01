#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector <int> res;
    for (int i=0; i < nums.size(); i++) {
      while (nums[i] != i+1 && nums[i] <= nums.size()-1) {
	int index = nums[i]-1;
	swap(nums[i], nums[index]);
      }
      
      for (int i=0; i < nums.size(); i++) {
	if (nums[i] != i+1)
	  res.push_back(nums[i]);
      }
    }
    return res;
  }
};
int main() {
  Solution s;
  vector <int> a = {5,6,3,2,1,7,7,5};
  vector <int> b = s.findDisappearedNumbers(a);
  for (int i=0; i < b.size(); i++)
    cout << b[i] << " ";
  cout << endl;
  return 0;
}
