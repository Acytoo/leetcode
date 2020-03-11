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
  int heightChecker(vector<int>& heights) {
    int res = 0;
    vector<int> dummy (heights);
    sort(dummy.begin(), dummy.end());
    for (int i=0, stop=dummy.size(); i<stop; ++i)
      if (dummy[i] != heights[i])
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
