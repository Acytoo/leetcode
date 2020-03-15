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
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  string generateTheString(int n) {
    string res = "";
    if ((n & 1) == 0) {
      res += 'b';
      --n;
    }
    while (n-- > 0)
      res += 'a';
    return res;
  }
};

int main() {
  Solution s;
  cout << s.generateTheString(3) << endl;
  return 0;
}
