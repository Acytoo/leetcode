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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  int monotoneIncreasingDigits(int N) {
    string s = to_string(N);
    const int n = s.size();
    int i = n - 1, j = n;

    while (i) if (s[i] < s[--i]) --s[j = i];
    while (++j < n) s[j] = '9';

    return stoi(s);
  }
};

int main() {
  Solution s;
  cout << s.monotoneIncreasingDigits(332) << endl;
  return 0;
}
