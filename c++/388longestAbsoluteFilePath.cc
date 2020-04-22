#include <iostream>
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

using namespace std;
// '\n' is one char, not '\' + 'n'
// using getline() function
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int lengthLongestPath(string input) {
    int res = 0;
    istringstream is (input);
    unordered_map<int, int> m;
    m.emplace(0,0);
    string line = "";

    while (getline(is, line)) {
      int level = line.find_last_of('\t') + 1;
      int len = line.substr(level).size();
      if (line.find('.') != string::npos)
        res = max(res, m[level] + len);
      else
        m[level + 1] = m[level] + len + 1;  // 1: /
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
