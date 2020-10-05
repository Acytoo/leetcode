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
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    unordered_map<string, vector<int>> data;
    for (int i = 0, n = keyName.size(); i < n; ++i) {
      const int t = ((keyTime[i][0] - '0') * 10 + keyTime[i][1] - '0') * 60 +
                    (keyTime[i][3] - '0') * 10 + keyTime[i][4] - '0';
      data[keyName[i]].push_back(t);
    }
    vector<string> res;
    for (auto &[name, times]: data) {
      sort(times.begin(), times.end());
      for (int i = 2, n = times.size(); i < n; ++i)
        if (times[i] - times[i - 2] <= 60) {
          res.emplace_back(move(name));
          break;
        }
    }
    sort(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
