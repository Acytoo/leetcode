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
  bool buddyStrings(string A, string B) {
    int i = 0, j = -1, m = A.size(), n = B.size(), move = 0;
    if (m <= 1 || m != n) return false;

    if (A == B) {
      int counts[26] = {0};
      for (int iter = 0; iter != m; ++iter) {
        int temp = A[iter] - 'a';
        ++counts[temp];
        if (counts[temp] == 2)
          return true;
      }
      return false;
    }

    while (i != m && move != 1) {
      if (A[i] == B[i]) {
        ++i;
        continue;
      }
      if (j != -1 && j != i) {
        swap(A[i], A[j]);
        move = 1;
        break;
      }
      j = i;
      ++i;
    }
    if (move && A == B)
      return true;
    return false;
  }
};

int main() {
  Solution s;
  string a = "aac", b = "aba";
  cout << s.buddyStrings(a, b) << endl;
  return 0;
}
