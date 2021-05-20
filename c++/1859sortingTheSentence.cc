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
  string sortSentence(string_view s) {
    vector<string> data(10);
    int l = 0, r = 0;
    const int n = s.size();
    while (r < n) {
      while (r < n && s[r] != ' ') ++r;
      data[s[r - 1] - '1'] = s.substr(l, r - l - 1);
      l = ++r;
    }
    string res = data[0];
    for (int i = 1; i < 10 && data[i] != ""; ++i)
      res += " " + data[i];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
