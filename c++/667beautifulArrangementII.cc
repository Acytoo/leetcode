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
// From grandyang
class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> res;
    int i = 1, j = n;
    while (i <= j)
      res.push_back(k > 1 ? (k-- % 2 ? i++ : j--) : i++);
    return res;
  }
};

class Solution_WRONG_ANSWER_BUT_ACCEPTED {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> res;
    res.reserve(n);
    int l = 0, r = n + 1;
    while (l < r)
      res.push_back(k == 1 ? ++l : (k-- & 1) ? ++l : --r);
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
