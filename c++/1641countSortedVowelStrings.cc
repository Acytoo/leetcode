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
  int countVowelStrings(int n) {
    vector<int> res = {1, 1, 1, 1, 1};
    for (int i = 1; i < n; ++i)
      for (int j = 3; j >= 0; --j)
        res[j] = res[j] + res[j + 1];
    return accumulate(res.begin(), res.end(), 0);
  }
};

int main() {
  Solution s;
  
  return 0;
}
