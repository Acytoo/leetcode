#include <iostream>
#include <vector>
#include <set>

using namespace std;

static int x = [] () {std::ios::sync_with_stdio(false); std::cin.tie(0); return 0;} ();
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    bitset<100000> occ;
    for (const int a : nums)
      if (occ[a]) return a;
      else occ[a] = 1;
    return -1;
  }
};

class Solution2 {
  // Binary search
 public:
  int findDuplicate(vector<int>& nums) {
    int l = 1, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      int count = 0;
      for (const int num : nums)
        if (num <= m) ++count;
      if (count <= m)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};

class Solution1 {
  // two pointers
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;  // indexes
    while (true) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) break;
    }
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};



// O(1) space, but modified the array
class Solution_BAD {
 public:
  int findDuplicate(vector<int>& nums) {
    for (int i=0; i < nums.size(); i++)
      if (nums[abs(nums[i])] > 0)
        nums[abs(nums[i])] = - nums[abs(nums[i])];
      else
        return abs(nums[i]);
    return -1;
  }
};

// not O(1) space
class Solution_BAD1 {
 public:
  int findDuplicate(vector<int>& nums) {
    set<int> myset;
    pair<set<int>::iterator,bool> ret;
    for (auto it = nums.cbegin(); it != nums.cend(); it++) {
      ret = myset.insert(*it);
      if (ret.second == false)
        return *it;
    }
    return -1;
  }
};

int main() {
  vector<int> a = {3,1,3,4,2};
  Solution1 s;
  cout << s.findDuplicate(a) << endl;
  return 0;
}
