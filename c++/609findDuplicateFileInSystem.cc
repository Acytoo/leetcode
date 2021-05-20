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
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> m;
    for (string &path : paths) {
      istringstream is(path);
      string pre = "", t = "";
      is >> pre;
      while (is >> t) {
        const int idx = t.find_last_of('(');
        const string path = pre + "/" + t.substr(0, idx);
        const string content = t.substr(idx + 1, t.size() - idx - 2);
        m[content].push_back(path);
      }
    }
    vector<vector<string>> res;
    for (auto &[_, path] : m)
      if (path.size() > 1)
        res.push_back(path);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
