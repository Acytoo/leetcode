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
class Solution1 {
 public:
  // quick sort
  vector<int> sortArray(vector<int>& nums) {
    function<void(int, int)> quick_sort = [&](int l, int r) {
                                            if (l >= r)
                                              return ;
                                            int i = l, j = r, p = nums[i+rand()%(r-l+1)];
                                            while (i <= j) {
                                              while (nums[i] < p) ++i;
                                              while (p < nums[j]) --j;
                                              if (i <= j)
                                                swap(nums[i++], nums[j--]);
                                            }
                                            quick_sort(l, j);
                                            quick_sort(i, r);
                                          };
    quick_sort(0, nums.size()-1);
    return nums;
  }
};

int main() {
  Solution s;
  
  return 0;
}
