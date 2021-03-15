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
  bool areAlmostEqual(string s1, string s2) {
    vector<int> diffs;
    for (int i = 0, n = s1.size(); i < n; ++i)
      if (s1[i] != s2[i])
        diffs.emplace_back(i);
    const int dif = diffs.size();
    if (dif == 0) return true;
    if (dif != 2) return false;
    if (s1[diffs[0]] == s2[diffs[1]] && s1[diffs[1]] == s2[diffs[0]])
      return true;
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
