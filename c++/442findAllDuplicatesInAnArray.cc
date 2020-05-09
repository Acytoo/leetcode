#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector <int> res;
    for (int i=0; i < nums.size(); ++i) {
      int index = abs(nums[i]) - 1;
      if (nums[index] < 0)
        res.push_back(abs(index+1));
      else
        nums[index] *= -1;
    }
    return res;
  }
};


int main() {
  Solution s;
  vector <int> a = {1,1,2,4,4,5,2,3,5};
  vector <int> b = s.findDuplicates(a);
  for(int i=0; i<b.size(); ++i)
    cout << b[i] << " " ;
  cout << endl;
  return 0;
}
