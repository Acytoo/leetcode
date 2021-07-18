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
// From huahua
class Solution {
 public:
  vector<int> threeEqualParts(vector<int>& arr) {
    string s(arr.begin(), arr.end());
    int ones = accumulate(s.begin(), s.end(), 0);
    if (ones % 3 != 0) return {-1, -1};
    if (ones == 0) return {0, static_cast<int>(arr.size()) - 1};
    ones /= 3;
    int right = arr.size() - 1;
    while (ones)
      if (arr[right--])
        --ones;
    string suffix(s.begin() + right + 1, s.end());
    int l = suffix.size();
    int left = s.find(suffix);
    if (left == string::npos) return {-1, -1};
    int mid = s.find(suffix, left + l);
    if (mid == string::npos || mid + 2 * l > s.size())
      return {-1, -1};
    return {left + l - 1, mid + l};
  }
};

int main() {
  Solution s;
  
  return 0;
}
