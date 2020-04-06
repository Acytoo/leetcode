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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    char c_res[200];
    int m, n, p, q;
    sscanf(a.c_str(), "%d+%di", &m, &n);
    sscanf(b.c_str(), "%d+%di", &p, &q);
    sprintf(c_res, "%d+%di", (m*p-n*q), (n*p+m*q));
    return string(c_res);
  }
};

int main() {
  Solution s;
  
  return 0;
}
