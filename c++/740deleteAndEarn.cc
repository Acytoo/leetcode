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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// Reduce this plroblem to 198 rob house
// sort first, move houses with same amount of money to same house

class Solution{
public:
  int deleteAndEarn(vector<int>& nums) {
    const int n = nums.size();
    if (!n) return 0;
    const auto range = minmax_element(nums.begin(), nums.end());
    const int l = *(range.first);
    const int r = *(range.second);
    const int new_n = r - l + 1;
    vector<int> houses(new_n, 0); // r - l + x is the maximum of total "houses"
    for (const int& num : nums) {
      houses[num-l] += num;     // build the houses
    }
    mem_ = vector<int> (new_n, -1);
    return rob(houses, new_n-1);
  }
private:
  int rob(const vector<int>& nums, int n) {
    if (n < 0) return 0;
    if (mem_[n] >= 0) return mem_[n];
    return mem_[n] = max(rob(nums, n-2)+nums[n], rob(nums, n-1));
  }
  vector<int> mem_;

};

int main() {
  Solution s;
  vector<int> a = {1,300, 4, 1, 4, 3, 5, 6, 7, 8, 7, 7};
  cout << s.deleteAndEarn(a) << endl;
  return 0;
}
