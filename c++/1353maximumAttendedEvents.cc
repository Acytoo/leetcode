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
  int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end(), [](const auto& a, const auto& b) {return a[1] < b[1];});
    int res = 0;
    bool seen[100001] = {false};
    for (const auto& e: events) {
      for (int i=e[0]; i<=e[1]; ++i) {
        if (seen[i])
          continue;
        seen[i] = true;
        ++res;
        break;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
