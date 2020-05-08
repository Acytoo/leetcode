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
  int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string> s(words.begin(), words.end());
    for (const auto &word: words)
      for (int i = word.size() - 1; i > 0; --i)
        s.erase(word.substr(i));
    int res = 0;
    for (const auto &word: s)
      res += word.size() + 1;
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
