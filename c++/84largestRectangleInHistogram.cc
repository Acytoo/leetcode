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
//  From huahua
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    heights.emplace_back(0);
    const int n = heights.size();
    stack<int> s;
    int i = 0;
    while (i < n) {
      if (s.empty() || heights[i] >= heights[s.top()]) {
        s.push(i++);
      } else {
        const int h = heights[s.top()]; s.pop();
        const int w = s.empty() ? i: i - s.top() - 1;
        res = max(res, h * w);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
