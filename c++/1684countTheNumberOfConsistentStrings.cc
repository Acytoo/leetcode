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
  int countConsistentStrings(string allowed, vector<string>& words) {
    bool chars['z' + 1];
    memset(chars, 0, sizeof(chars));
    for (const char c: allowed) chars[c] = true;
    int res = 0;
    for (const string& word: words) {
      const int n = word.size();
      int i = 0;
      while (i < n) {
        if (!chars[word[i]]) break;
        ++i;
      }
      if (i == n) ++res;
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
