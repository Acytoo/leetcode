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

class Solution {
public:
  bool isLongPressedName(string name, string typed) {
    int i=0, j=0, m=name.size(), n=typed.size();
    if (m > n)
      return false;
    if (m == n)
      return name == typed;
    if (name[0] != typed[0] || name[m-1] != typed[n-1])
      return false;

    while (i != m && j != n) {
      if (name[i] == typed[j]) {
        ++i;
        ++j;
        continue;
      }
      if (typed[j] == name[i-1]) {
        ++j;
        continue;
      }
      else
        return false;
    }

    if (i == m)
      while (j != n) {
        if (typed[j++] != name[m-1])
          return false;
      }
    else
      return false;
    return true;
  }
};

int main() {
  Solution s;
  cout << s.isLongPressedName("hello", "heelloo") << endl;
  return 0;
}
