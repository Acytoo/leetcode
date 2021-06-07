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
// Basketwang
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    const int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n3 != n1 + n2) return false;

    vector<vector<bool>> match (n1 + 1, vector<bool>(n2 + 1));
    match[0][0] = true;
    for (int idx = 0; idx < n3; ++idx)
      for (int l1 = 0, stop = idx + 1; l1 <= stop && l1 <= n1; ++l1) { // l1: length of current s1
        const int l2 = stop - l1;  // idx + 1 - l1 = l2, length of current s2
        if (l2 > n2) continue;
        if ((l1 > 0 && s3[idx] == s1[l1 - 1] && match[l1 - 1][l2]) ||
            (l2 > 0 && s3[idx] == s2[l2 - 1] && match[l1][l2 - 1]))
          match[l1][l2] = true;
      }
    return match.back().back();
  }
};

int main() {
  Solution s;
  
  return 0;
}
