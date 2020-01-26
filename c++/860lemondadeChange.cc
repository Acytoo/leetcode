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
  bool lemonadeChange(vector<int>& bills) {
    if (bills.size() == 0)
      return true;
    if (bills[0] != 5)
      return false;

    int b5 = 0, b10 = 0;
    for (int bill: bills) {

      if (bill == 5) {
        ++b5;
      } else if (bill == 10) {
        --b5;
        ++b10;
      } else if (bill == 20) {
        if (0 < b10) {
          --b10;
          --b5;
        } else {
          b5 -= 3;
        }
      }

      if (b5 < 0)
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  
  return 0;
}
