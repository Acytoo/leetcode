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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool checkRecord(string s) {
    int a = 1, l = 2;
    for (char c: s) {
      if (c == 'L') {
        --l;
        if (l<0)
          return false;
      } else {
        l = 2;
        if (c == 'A') {
          --a;
        if (a<0)
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  string a = "LALL";
  cout << s.checkRecord(a)<< endl;
  return 0;
}
