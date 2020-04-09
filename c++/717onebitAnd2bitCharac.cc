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
using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// every bit after a "0" belongs to a new character
class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    const int n = bits.size()-1;
    if (bits[n] == 1) return false;
    // last bit is 0
    if (n == 0) return true;
    int i = n;
    while (--i >= 0) {
      if (bits[i] == 0)
        break;
    }
    int num = n - i - 1;  // num of 1s between the end 0 and one start of new character
    return !(num & 1);
  }
};

int main() {
  Solution s;
  vector<int> a = {1,0,0,1,1,1,1,1,0};
  cout << s.isOneBitCharacter(a) << endl;
  return 0;
}
