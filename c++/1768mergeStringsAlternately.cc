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
  string mergeAlternately(string word1, string word2) {
    const int m = word1.size(), n = word2.size();
    string res;
    int i = 0;
    for (int stop = min(m, n); i < stop; ++i) {
      res.push_back(word1[i]);
      res.push_back(word2[i]);
    }
    if (m < n) {
      for (int i = m; i < n; ++i) res.push_back(word2[i]);
    } else if (m > n) {
      for (int i = n; i < m; ++i) res.push_back(word1[i]);
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
