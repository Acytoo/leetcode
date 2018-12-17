#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// ~~~ 27 ---> 10
class Solution {
public:
  int titleToNumber(string s) {
    int res = 0;
    for (int j = 0, i = s.size() - 1; i != -1; --i, ++j) {
      res += (s[i] - 64) * pow(26, j); 
    }
    return res;
  }
};

int main() {
  Solution s;
  string a = "ZY";
  cout << s.titleToNumber(a) << endl;
  return 0;
}
