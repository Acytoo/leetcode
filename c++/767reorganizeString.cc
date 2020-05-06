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
  string reorganizeString(string S) {
    const int n = S.size();
    vector<pair<int, char>> dict ('z' + 1);
    for (char i = 'a'; i <= 'z'; ++i) dict[i].second = i;

    for (const char c: S) ++dict[c].first;
    sort(dict.rbegin(), dict.rend() - 'a');
    if ((n >> 1) + (n & 1) < dict['a'].first) return "";

    int idx = 'a', j = 0;
    for (int i = 0; i < n; ++i) {
      while (dict[idx].first == 0) ++idx;
      S[j] = dict[idx].second;
      --dict[idx].first;
      j += 2;
      if (j >= n) j = 1;
    }
    return S;
  }
};

int main() {
  Solution s;
  cout << s.reorganizeString("aabccbb") << endl;
  return 0;
}
