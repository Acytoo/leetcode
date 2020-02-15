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
  bool rotateString(string A, string B) {
    if (A.size() != B.size())
      return false;
    int n = A.size();
    if (n == 0 || A == B)
      return true;
    for (int i=1; i<n; ++i)
      if (A[i] == B[0]) {
        string a (A);
        std::rotate(a.begin(), a.begin()+i, a.end());
        if (a == B)
          return true;
      }
    return false;
  }
};

int main() {
  Solution s;
  
  return 0;
}
