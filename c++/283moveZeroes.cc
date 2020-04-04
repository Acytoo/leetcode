#include <iostream>
#include <vector>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  // Two pointers
  void moveZeroes(vector<int>& nums) {
    int p1 = 0, p2 = 0;
    const int n = nums.size();
    while (p2 < n) {
      if (nums[p2]) {
        nums[p1] = nums[p2];
        ++p1;
      }
      ++p2;
    }
    while (p1 < n) {
      nums[p1++] = 0;
    }
  }
};

class Solution1 {
 public:
  void moveZeroes(vector<int>& nums) {
    int amount = 0;
    for (vector<int>::iterator tail = nums.begin(); tail != nums.end(); ++tail)
      if (*tail == 0) {
        ++amount;
        tail = nums.erase(tail)-1;
      }
    for (int i=0; i < amount; ++i)
      nums.push_back(0);
  }
};

int main() {
  Solution s;
  vector <int> a = {1,0,2,0,3,4,5,6,0,6,7};
  s.moveZeroes(a);

  return 0;
}
