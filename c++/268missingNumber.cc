#include <iostream>
#include <vector>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int missingNumber(vector<int> nums) {
    const int n = nums.size();
    if (n == 0) return 0;
    int i = 0, res = nums[0];
    while (++i < n) {
      res = res ^ nums[i] ^ i;
    }
    return res ^ n;
  }
};

class Solution1 {
public:
  int missingNumber(vector<int>& nums) {
    int total = 0, n = nums.size();
    for (int i=0; i< n; ++i)
      total += nums[i];
    return n*(n+1)/2-total;
  }
};

int main() {
  vector <int> a = {4,2,1,0};
  Solution s;
  cout << s.missingNumber(a) << endl;
  return 0;
}
