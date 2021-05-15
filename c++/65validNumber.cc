#include <iostream>
#include <string>

using namespace std;

/*
  pre
  -1 : None
  0  : Number
  1  : -
  2  : +
  3  : .
  4  : e

  + == -
*/

static int x = [](){ std::ios::sync_with_stdio(false); std::cin.tie(0); return 0; } ();
class Solution {
 public:
  bool isNumber(string s) {
    int pre = -1;
    //empty = 0, hasNum = 0, hasSpace = 0, hasSym = 0, hasE = 0, hasDot = 0, pre = -1;
    bool empty = false, hasNum = false, hasSpace = false, hasSym = false, hasE = false, hasDot = false, stat = false;
    // stat = all those flags
    for (char &c : s) {

      if (c == ' ') {
        if (!stat)
          empty = true;
        else
          hasSpace = true;
        continue;
      }

      if (hasSpace)
        return false;

      if (c > 47 && c < 58) {

        stat = true;
        pre = 0;
        hasNum = true;
        continue;
      }

      if (c == '+' || c == '-') {
        if (hasSym)
          return false;
        if (pre == 0)
          return false;
        if (pre > 0 && pre < 4)
          return false;
        stat = true;
        hasSym = true;
        pre = 2;
        continue;
      }
      /*
        if (c == '-') {
        if (hasSym)
        return false;
        if (pre == 0)
        return false;
        if (pre > 0 && pre < 4)
        return false;
        stat = true;
        hasSym = true;
        pre = 1;
        continue;
        }*/

      if (c == '.') {
        if (hasE)
          return false;
        if (hasDot)
          return false;
        if (pre == 3)
          return false;
        stat = true;
        hasDot = true;
        pre = 3;
        continue;
      }

      if (c == 'e' || c == 'E') {
        if (pre != 0 && pre != 3)
          return false;
        if (!hasNum)
          return false;
        if (hasE)
          return false;
        stat = true;
        hasE = true;
        pre = 4;
        hasSym = false;
        continue;
      }
      // others
      return false;
    }
    if (pre == 0 || pre == 3)
      return hasNum;
    return false;
  }
};

int main() {
  Solution s;
  string a = ".e8";
  cout << s.isNumber(a) << endl;
  return 0;
}
