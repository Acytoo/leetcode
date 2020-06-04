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
  string arrangeWords(string text) {
    text[0] ^= 0x20;
    string res = "";
    map<int, vector<string>> m;
    int i = 0, n = text.size(), start = 0;
    while (i < n) {
      while (i < n && text[i] != ' ') ++i;
      m[i - start].emplace_back(text.substr(start, i - start));
      start = ++i;
    }
    for (const auto &[len, words]: m)
      for (const string &word: words)
        res += word + ' ';
    res[0] ^= 0x20;
    res.pop_back();
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
