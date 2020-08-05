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
  string restoreString(string s, vector<int>& indices) {
    string res (s);
    for (int i = 0, stop = s.size(); i < stop; ++i) res[indices[i]] = s[i];
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
