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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) return false;
    if (k == 0) {
      for (int i=0, stop=nums.size()-1; i<stop; ++i)
        if (nums[i] == 0 && nums[i+1] == 0)
          return true;
    } else {
      unordered_map<int, int> m {{0, -1}};
      int sum = 0;
      for (int i=0, stop=nums.size(); i<stop; ++i) {
        sum += nums[i];
        int rem = sum % k;
        cout << "rem " << rem << endl;
        if (m.count(rem)) {
          if (i-m[rem]>1)
            return true;
        } else {
          m[rem] = i;
        }
      }
    }
    return false;
  }
};

class Solution_WRONG_ANSWER {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) return false;
    if (k == 0) {
      for (int i=0, stop=nums.size()-1; i<stop; ++i)
        if (nums[i] == 0 && nums[i+1] == 0)
          return true;
    } else {
      unordered_set<int> s;
      int sum = 0, pre = INT_MAX;
      for (int i=0, stop=nums.size()-1; i<=stop; ++i) {
        if (nums[i] == 0)
          if ((i<stop && nums[i+1] == 0) || pre == 0)
            return true;
          else
            continue;

        sum += nums[i];
        int rem = sum % k;
        cout << "rem " << rem << endl;
        if (s.count(rem))  // unordered_set contains(): c++20
          return true;
        s.insert(pre);
        pre = rem;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> a = {0, 1, 0};

  a = {1,1};
  // a = {1,2,12};
  cout << s.checkSubarraySum(a, -1) << endl;
  return 0;
}
