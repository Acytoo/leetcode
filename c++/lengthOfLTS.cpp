#include <iostream>
#include <vector>
using namespace std;

static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (!nums.size())
      return 0;
    int res=0, lengths[nums.size()] = {0};
    for (auto i = nums.cbegin(); i !=nums.cend(); i++) {
      for (auto j = nums.cbegin(); j != i; j++) {
	if (*i > *j) {
	  lengths[i-nums.cbegin()] = max(lengths[i-nums.cbegin()], lengths[j-nums.cbegin()]+1);
	  res = max(res, lengths[i-nums.cbegin()]);
	}
      }
    }
    return res+1;
  }
};

int main() {
  Solution s;
  vector<int> a = {10,9,2,5,3,7,101,18, 56};
  cout << s.lengthOfLIS(a) << endl;
  return 0;
}
