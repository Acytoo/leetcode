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

static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
// From huahua
class Solution {
 public:
  string maximumBinaryString(string binary) {
    const int n = binary.size();
    int l = 0, z = 0;
    for (char &c: binary) {
      if (c == '0') {
        ++z;
      } else if (z == 0) {
        ++l;
      }
      c = '1';
    }
    if (l != n) binary[l + z - 1] = '0';
    return binary;
  }
};

int main() {
  Solution s;
  
  return 0;
}
