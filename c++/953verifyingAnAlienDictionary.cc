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
  bool isAlienSorted(vector<string>& words, string_view order) {
    vector<int> charMap('z' + 1);
    for (int i = 0; i < 26; ++i)
      charMap[order[i]] = i;
    function<bool(string_view, string_view)> unsorted =
        [&] (const string_view &a, const string_view &b) {
          const int m = a.size(), n = b.size();
          for (int i = 0, stop = min(m, n); i < stop; ++i)
            if (a[i] != b[i])
              return charMap[a[i]] > charMap[b[i]];
          return n < m;
        };
    for (int i = 0, n = words.size() - 1; i < n; )
      if (unsorted(words[i], words[++i]))
        return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
