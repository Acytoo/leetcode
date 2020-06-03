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
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int res = 0;
    for (int i = 0, n = startTime.size(); i < n; ++i)
      if (startTime[i] <= queryTime && queryTime <= endTime[i])
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
