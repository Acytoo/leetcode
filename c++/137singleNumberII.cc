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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    map<int, int> nums_map;
    for (auto i : nums)
      if (nums_map.find(i) == nums_map.end()) nums_map[i] = 1;
      else ++nums_map[i];

    for (auto it : nums_map)
      if (it.second != 3)  return it.first;

    return 0;
  }
};

int main() {
  Solution s;
  
  return 0;
}
