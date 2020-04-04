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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int res = nums[0], count = 1;
    for (int i=1, stop=nums.size(); i<stop; ++i) {
      if (nums[i] == res) {
        ++count;
      } else {
        --count;
        if (count == 0) {
          res = nums[i];
          count = 1;
        }
      }
    }
    return res;
  }
};

class Solution1 {
 public:
  int majorityElement(vector<int>& nums) {
    int i=0;
    map <int, int> map_count;
    map <int, int>::iterator iter;
    for (; i < nums.size(); ++i) {
      iter = map_count.find(nums[i]);
      if (iter != map_count.end()) {
        //find, then add one
        iter->second++;
      }
      else {
        //insert new one
        map_count[nums[i]] = 1;
      }
    }
    int num, max_count = 0;
    for (auto iter : map_count) {
      if (max_count < iter.second) {
        max_count = iter.second;
        num = iter.first;
      }
    }
    return num;
  }
};


int main() {
  Solution s;
  
  return 0;
}
