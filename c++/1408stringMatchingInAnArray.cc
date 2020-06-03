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
  vector<string> stringMatching(vector<string>& words) {
    sort(words.begin(), words.end(), [] (const string &a, const string &b) {
                                       return a.size() < b.size();
                                     });
    vector<string> res;
    for (int i = 0, n = words.size(); i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        if (words[i].size() == words[j].size()) continue;
        if (words[j].find(words[i]) != string::npos) {
          res.emplace_back(move(words[i]));
          break;
        }
      }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
