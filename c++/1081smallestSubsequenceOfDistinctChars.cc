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
  string smallestSubsequence(string text) {
    constexpr int kLen = 'z' + 1;
    string res;
    int dict[kLen];
    memset(dict, 0, sizeof(dict));
    for (const char c: text) ++dict[c];
    bitset<kLen> used;

    for (const char c: text) {
      --dict[c];
      if (res.empty()) {
        res.push_back(c);
        used[c] = 1;
        continue;
      }
      if (used[c]) continue;
      while (!res.empty() && c < res.back() && dict[res.back()] > 0) {
        used[res.back()] = 0;
        res.pop_back();
      }
      res.push_back(c);
      used[c] = 1;
    }

    return res;
  }
};

int main() {
  Solution s;
  string a = "dczcd";
  cout << s.smallestSubsequence(a) << endl;
  return 0;
}
