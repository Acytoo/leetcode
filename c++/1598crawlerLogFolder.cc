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
  int minOperations(vector<string>& logs) {
    int res = 0;
    for (const string& log: logs)
      if (log[1] == '/')
        continue;
      else if (log[1] == '.')
        res = max(0, res - 1);
      else
        ++res;
    return res;
  }
};

class Solution1 {
 public:
  int minOperations(vector<string>& logs) {
    int res = 0;
    for (const string& log: logs)
      if (log == "./")
        continue;
      else if (log == "../")
        res = res == 0? res: res - 1;
      else
        ++res;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
