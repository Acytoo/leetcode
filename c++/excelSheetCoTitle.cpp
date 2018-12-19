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
  string convertToTitle(int n) {
    string res;
    while (n > 0) {
      --n;
      res += 'A' + n % 26;
      n /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  cout << s.convertToTitle(702) << endl;
  return 0;
}
