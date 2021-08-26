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
  string addStrings(string num1, string num2) {
    if (num1.size() < num2.size())
      return addStrings(num2, num1);  // the first num is always longer
    string res = "";
    int i = num1.size() - 1, j = num2.size() - 1;
    constexpr int kBase = '0' + '0';
    int carry = 0;
    while (j >= 0) {
      int sum = num1[i] + num2[j] + carry - kBase;
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      res += (sum + '0');
      --i; --j;
    }
    while (i >= 0) {
      int sum = num1[i] + carry - '0';
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      res += (sum + '0');
      --i;
    }
    if (carry == 1) res += '1';
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  
  return 0;
}
