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
  int numSpecialEquivGroups(vector<string>& A) {
    unordered_set<string> s;
    for (string &str: A) {
      int i = -1, n = str.size();
      string even = "", odd = "";
      for (int j = 0, stop = n >> 1; j < stop; ++j) {
        odd += str[++i];
        even += str[++i];
      }
      if (n & 1) odd += str.back();
      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());
      s.emplace(even + odd);
    }
    return s.size();
  }
};

int main() {
  Solution s;
  
  return 0;
}
