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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
public:
  Solution() {
    tmp_[0] = 1;
    tmp_[1] = 9;
    int base = 9, i = 2;
    while (i != 11) {
      tmp_[i] = tmp_[i-1] * base--;
      ++i;
    }
  }
  int countNumbersWithUniqueDigits(int n) {
    int res = 0;
    n = min(++n, 11);
    for (int i=0; i<n; ++i)
      res += tmp_[i];
    return res;
  }
private:
  int tmp_[11];
};

int main() {
  Solution s;
  cout << s.countNumbersWithUniqueDigits(11) << endl;
  return 0;
}
