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
class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    set<int> s;
    for (int num: nums) {
      s.insert(num);
      if (3 < s.size())
        s.erase(s.begin());
    }
    return s.size() < 3? *s.rbegin(): s.begin();
  }
};

int main() {
  Solution s;
  
  return 0;
}
