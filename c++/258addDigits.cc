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

using namespace std;

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();

class Solution {
 public:
  int addDigits(int num) {
    // if(num == 0) return 0;
    return (num-1) % 9 + 1;
  }
};

int main() {
  Solution s;
  cout << s.addDigits(0) << endl;
  return 0;
}
