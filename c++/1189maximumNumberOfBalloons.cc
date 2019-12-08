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
// b a l*2 o*2 n
class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    if (text.size() < 7) return 0;
    vector<int> counting(5, 0);
    for (const char& c: text) {
      switch (c) {
        case 'b': ++counting[0]; break;
        case 'a': ++counting[1]; break;
        case 'l': ++counting[2]; break;
        case 'o': ++counting[3]; break;
        case 'n': ++counting[4]; break;
        default:;
      }
    }
    counting[2] /= 2;
    counting[3] /= 2;
    int res = INT_MAX;
    for (int i: counting) {
      res = min(res, i);
    }
    return res;
  }
};

int main() {
  Solution s;
  string a = "blloon";
  cout << s.maxNumberOfBalloons(a) << endl;
  return 0;
}
