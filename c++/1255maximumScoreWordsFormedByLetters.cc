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
#include <array>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxScoreWords(vector<string>& words,
                    vector<char>& letters, vector<int>& score) {
    const int m = words.size(), n = letters.size();
    array<int, 26> dict;
    dict.fill(0);
    for (const char c: letters) ++dict[c - 'a'];
    vector<int> scores (m);
    for (int i = 0; i < m; ++i)
      for (int j = 0, stop = words[i].size(); j < stop; ++j)
        scores[i] += score[words[i][j] - 'a'];

    int res = 0;
    function<void(int, int)> dfs =
        [&] (const int idx, const int cur) {
          if (res < cur) res = cur;

          for (int i = idx; i < m; ++i) {
            int j = -1, stop = words[i].size();
            array<int, 26> bk (dict);
            while (++j < stop)
              if (--dict[words[i][j] - 'a'] < 0) break;
            if (j == stop) dfs(i + 1, cur + scores[i]);
            swap(bk, dict);
          }
        };
    dfs(0, 0);
    return res;
  }
};

class Solution_WRONGGGGGGGGGGGGGGGG_____ {
 public:
  int maxScoreWords(vector<string>& words,
                    vector<char>& letters, vector<int>& score) {
    const int n = letters.size();
    array<int, 26> dict;
    dict.fill(0);
    for (const char c: letters) ++dict[c - 'a'];
    int res = 0;
    for (const auto word: words) {
      int cur = 0, j = -1, m = word.size();
      if (m > n) continue;
      array<int, 26> bk (dict);
      while (++j < m) {
        int idx = word[j] - 'a';
        if (--bk[idx] < 0) break;
        cur += score[idx];
      }
      if (j == m) res = max(res, cur);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
