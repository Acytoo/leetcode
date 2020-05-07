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
  int numRabbits(vector<int>& answers) {
    int m = *max_element(answers.begin(), answers.end());
    int counts [m + 1];
    memset(counts, 0, sizeof(counts));
    for (const int ans: answers) ++counts[ans];
    int res = 0;
    for (int i = 0; i <= m; ++i)
      res += (counts[i] + i) / (i + 1) * (i + 1);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
