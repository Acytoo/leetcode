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
// ano solution
class Solution {
public:
  bool isPowerOfTwo(int n) {
    return n > 0 && ((n & (n-1)) == 0);
  }
};

int main() {
  Solution s;
  cout << s.isPowerOfTwo(2) << endl;
  return 0;
}
