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
class Solution {
 public:
  int countOperations(int num1, int num2) {
    if (num1 == 0 || num2 == 0) return 0;
    // if (num1 == 1 || num2 == 1) return max(num1, num2);
    if (num1 < num2) return 1 + countOperations(num1, num2 - num1);
    return 1 + countOperations(num1 - num2, num2);
  }
};

int main() {
  Solution s;
  
  return 0;
}
