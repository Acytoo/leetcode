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
  string getHint(string secret, string guess) {
    const int n = secret.size();
    vector<int> sec ('9'+1), gue ('9'+1);
    int match = 0, miss = 0;
    for (int i=0; i<n; ++i)
      if (secret[i] == guess[i]) {
        ++match;
      } else {
        ++sec[secret[i]];
        ++gue[guess[i]];
      }

    for (int i='0'; i<='9'; ++i)
      if (gue[i] > 0)
        miss += min(gue[i], sec[i]);
    return to_string(match) + "A" + to_string(miss) + "B";
  }
};

int main() {
  Solution s;
  cout << s.getHint("1123", "0111") << endl;
  return 0;
}
