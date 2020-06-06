#include <iostream>
#include <sstream>
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
#include <functional>
#include <bitset>
#include <numeric>
#include <deque>
#include <mutex>
#include <utility>
#include <memory>
#include <cstring>

using namespace std;

// a: changing the first none-9 num to 9; b: changing the first none-1 num to 1
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int maxDiff(int num) {
    string a = to_string(num), b = a;
    const int n = a.size();
    if (n == 1)  return 8;
    auto change = [&] (string &snum, char t, int i = 0) {
                    while (i < n && snum[i] == t) ++i;
                    if (i != n) {
                      char bk = snum[i];
                      snum[i] = t;
                      while (++i < n)
                        if (snum[i] == bk)
                          snum[i] = t;
                    }
                  };
    change(a, '9');
    if (b[0] == '1') {
      int i = 0;
      while (i < n && (b[i] == '1' || b[i] == '0')) ++i;
      if (i < n)
        change(b, '0', i);
    } else {
      change(b, '1');
    }
    return stoi(a) - stoi(b);
  }
};

int main() {
  Solution s;
  cout << s.maxDiff(111) << endl;
  return 0;
}
