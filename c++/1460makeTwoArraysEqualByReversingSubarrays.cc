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
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    int nums[1001];
    memset(nums, 0, sizeof(nums));
    for (const int a: target) ++nums[a];
    for (const int a: arr) if (--nums[a] < 0) return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
