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
  string orderlyQueue(string S, int K) {
    if (K > 1) {
      sort(S.begin(), S.end());
      return S;
    }
    string res (S);
    for (int i = 1, stop = S.size(); i < stop; ++i)
      res = min(res, S.substr(i) + S.substr(0, i));
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
