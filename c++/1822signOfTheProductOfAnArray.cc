#include <iostream>
#include <sstream>
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
#include <cstring>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int negitive = 0;
    for (const int num : nums)
      if (num < 0)
        ++negitive;
      else if (num == 0)
        return 0;
    return (negitive & 1) ? -1 : 1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
