#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
//solution one: scan 3 times, <0 -> 0, > n -> pass, else -> neg, then first >0
//solution two scan 2 times switch
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 1;

    for(int i = 0; i < n;)
      if(nums[i] > 0 && nums[i] < n && nums[nums[i] - 1] != nums[i] && nums[i]-1!= i)
        swap(nums[i], nums[nums[i] - 1]);
      else
        ++i;

    for(int i = 0; i < n; )
      if(nums[i] != ++i)
        return i;

    return n + 1;
  }
};


// awsome solution from leetcode and run's 0ms !!! and then I changeeeeeeeeeee it...
class Solution1 {
public:
  int firstMissingPositive(vector<int>& nums) {
    if(nums.size() == 0) return 1;
    for(int i = 0;i<nums.size();){
      if(nums[i]>0 && nums[i]<nums.size() && nums[i]-1!= i && nums[nums[i]-1] != nums[i])//123 2
        {
          swap(nums[nums[i]-1],nums[i]);
        }else i++;
    }

    for(int i = 0;i<nums.size();i++){
      if(nums[i]-1 != i) return i+1;
    }
    if(nums[nums.size()-1] == nums.size()) return nums.size()+1;
    return 1;
  }
};

int main() {
  Solution s;
  vector<int> a = {-1, 4, 2, 1, 9, 10};
  cout << s.firstMissingPositive(a) << endl;
  return 0;
}
