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
  int minElements(vector<int>& nums, int limit, int goal) {
    const long sum = accumulate(nums.begin(), nums.end(), 0l);
    const long needed = abs(goal - sum);
    const int res = (needed / limit) + (needed % limit != 0);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
