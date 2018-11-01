#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int total = 0, n = nums.size();
    for (int i=0; i< n; ++i)
      total += nums[i];
    return n*(n+1)/2-total;
  }
};

int main() {
  vector <int> a = {9,6,4,2,3,5,7,0,1};
  Solution s;
  cout << s.missingNumber(a) << endl;
  return 0;
}
