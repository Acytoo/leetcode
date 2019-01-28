#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> numMap;
    pair<map<int, int>::iterator, bool> insertStat;
    for (int i=0, stop=nums.size(); i != stop; ++i) {
      insertStat = numMap.insert(pair<int, int>(nums[i], i));
      if (!insertStat.second){
        auto iter = numMap.find(nums[i]);
        if ((i - iter->second) <= k)
          return true;
        else
          iter->second = i;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<int> a = {1,0,1,1};
  cout << s.containsNearbyDuplicate(a, 1) << endl;
  return 0;
}
