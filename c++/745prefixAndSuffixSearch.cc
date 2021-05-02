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
// From huahua
class WordFilter {
 public:
  WordFilter(vector<string>& words) {
    int index = 0;
    for (const string & a : words) {
      string prefix ="";
      for (int i = 0, n = a.size(); i < n; ++i) {
        prefix += a[i];
        string suffix = "";
        for (int j = n - 1; j >= 0; --j) {
          suffix = a[j] + suffix;
          m_[prefix + '_' + suffix] = index;
        }
      }
      ++index;
    }
  }

  int f(string prefix, string suffix) {
    const string key = prefix + "_" + suffix;
    if (m_.count(key) != 0)
      return m_[key];
    return -1;
  }
  unordered_map<string, int> m_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main() {
  Solution s;
  
  return 0;
}
