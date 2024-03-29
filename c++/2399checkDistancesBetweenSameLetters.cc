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
  bool checkDistances(string s, vector<int>& distance) {
    vector<int> dis('z' + 1, -1);
    for (int i = 0, n = s.size(); i < n; ++i) {
      if (dis[s[i]] == -1) dis[s[i]] = i;
      else dis[s[i]] = i - 1 - dis[s[i]];
    }
    for (int i = 'a'; i <= 'z'; ++i)
      if (dis[i] != -1 && dis[i] != distance[i - 'a'])
        return false;
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
