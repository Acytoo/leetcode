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
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, string> m;
    for (const auto &path: paths)
      m[path[0]] = path[1];
    string city = paths[0][0];
    while (m.count(city))
      city = m[city];
    return city;
  }
};

int main() {
  Solution s;
  
  return 0;
}
