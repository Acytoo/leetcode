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
// we may ***rearrange*** the substring s[left], ..., s[right], and then choose up to k
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    const int n = s.size();
    vector<bool> res;
    res.reserve(queries.size());
    vector<vector<int>> count(n + 1, vector<int> (26));
    for (int i = 0; i < n; ++i) {
      ++count[i][s[i] - 'a'];
      count[i + 1] = count[i];
    }
    for (const auto &q: queries) {
      int odd = 0;
      for (int i = 0; i < 26; ++i) {
        int c = count[q[1]][i] - (q[0] == 0? 0:  count[q[0] - 1][i]);
        odd += (c & 1);
      }
      res.push_back((odd >> 1) <= q[2]);
    }
    return res;
  }
};

class Solution_TLE {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    const int n = queries.size();
    vector<bool> res;
    res.reserve(n);
    auto canPali = [&s] (int l, int r, int k) ->bool {
                     k <<= 1;
                     int dict['z' + 1];
                     memset(dict, 0, sizeof(dict));
                     for (int i = l; i <= r; ++i)
                       ++dict[s[i]];
                     for (char c = 'a'; c <= 'z'; ++c)
                       if (dict[c] & 1) --k;
                     int len = r - l + 1;
                     if (len & 1)
                       return k >= -1;
                     else
                       return k >= 0;
                   };

    for (const auto &q: queries)
      res.push_back(q[1] - q[0] <= q[2] ||
                    canPali(q[0], q[1], q[2]));
    return res;
  }
};


class Solution_WRONG {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    const int n = queries.size();
    vector<bool> res;
    res.reserve(n);
    auto canPali = [&s] (int l, int r, int k) ->bool {
                     while (l < r) {
                       if (k < 0) return false;
                       if (s[l] != s[r])
                         --k;
                       ++l;
                       --r;
                     }
                     return k >= 0;
                   };

    for (const auto &q: queries)
      if (q[1] - q[0] <= q[2])
        res.emplace_back(true);
      else
        res.push_back(canPali(q[0], q[1], q[2]));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
