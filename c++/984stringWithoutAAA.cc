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
  string strWithout3a3b(int A, int B) {
    string res = "";
    while (A>0 || B>0) {
     while (A > B && B > 0) {
        res += "aab";
        A -= 2;
        --B;
      }

      while (A < B && A > 0) {
        res += "bba";
        --A;
        B -= 2;
      }

      while (A == B && A > 0) {
        res += "ab";
        --A;
        --B;
      }

      while (A-- > 0)
        res += "a";

      while (B-- > 0)
        res += "b";
    }
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
