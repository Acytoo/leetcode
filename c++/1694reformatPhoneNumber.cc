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
  string reformatNumber(string number) {
    vector<char> nums;
    nums.reserve(number.size());
    for (const char c: number)
      if (c >='0')
        nums.emplace_back(c);
    const int n = nums.size();
    int i = 0;
    string res = "";
    while ((n - i) > 4) {
      res += nums[i];
      res += nums[++i];
      res += nums[++i];
      res += '-';
      ++i;
    }
    if (n - i == 4) {
      res += nums[i];
      res += nums[++i];
      res += '-';
      res += nums[++i];
      res += nums[++i];
    } else if (n - i == 3) {
      res += nums[i];
      res += nums[++i];
      res += nums[++i];
    } else {
      res += nums[i];
      res += nums[++i];
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
