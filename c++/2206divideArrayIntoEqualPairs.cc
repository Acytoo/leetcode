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
  bool divideArray(vector<int>& nums) {
    int a[512];
    memset(a, 0, sizeof a);
    for (const int num : nums) ++a[num];
    for (int i = 0; i < 501; ++i)
      if (a[i] & 1) return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
