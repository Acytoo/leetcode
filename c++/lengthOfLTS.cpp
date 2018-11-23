#include <iostream>
#include <vector>
#include <set>
using namespace std;

static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
// solution from leetcode 10 9 2 6 7 3 4 5 8 101
class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (!n)
      return 0;
    set<int> s;
    for(int i = 0; i < n; i++){
      auto re = s.insert(nums[i]);
      set<int>::iterator it;
      if(re.second){
	it = re.first;
	it++;
	if(it != s.end())
	  s.erase(it);
      }
    }
    return s.size();
  }
};
// Mine
class Solution2 {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (!nums.size())
      return 0;
    int res=0, lengths[nums.size()] = {0};
    for (int i=0; i < nums.size(); i++)
      for (int j=0; j < i; j++)
	if (nums[i] > nums[j]) {
	  lengths[i] = max(lengths[i], lengths[j] + 1);
	  res = max(lengths[i], res);
	}
    return res + 1;
  }
};

// test which way is faster
class Solution1 {
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
  Solution1 s;
  vector<int> a = {10,9,2,6,7,3,4,5,8,101,18, 56};
  cout << s.lengthOfLIS(a) << endl;
  return 0;
}
