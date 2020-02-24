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
#include <bitset>
#include <numeric>


using namespace std;
// max(num.length) = 35; so first number or second number might overflow int
static int x = [] () {ios::sync_with_stdio(false); cin.tie(0); return 0;} ();
class Solution {
 public:
  bool isAdditiveNumber(string num) {
    int n = num.size();
    int n1_max_len = (n-1) >> 1;  // "1234", "12345"
    for (int i=1; i<=n1_max_len; ++i) {
      if (num[0] == '0' && 2<=i)
        break;
      // [0, i) first num, [i, j) second num, [j, n) second num
      // len(num3) >= max(len(num1), len(num2))
      for (int j=1, n2_max_len=n-(i<<1); j<=n2_max_len; ++j) {
        if (num[i] == '0') {
          long n1 = std::stol(num.substr(0, i));
          long n2 = 0;
          if (isAdditive(num.substr(i+j), n1, n2))
            return true;
          else
            break;
        } else {
          long n1 = std::stol(num.substr(0, i));
          long n2 = std::stol(num.substr(i, j));
          if (isAdditive(num.substr(i+j), n1, n2))
            return true;
        }
      }
    }
    return false;
  }
 private:
  bool isAdditive(string num, long n1, long n2) {
    if (num.empty())
      return true;
    long n3 = n1 + n2;
    string sum = std::to_string(n3);
    if (num.substr(0, sum.size()) != sum)
      return false;
    return isAdditive(num.substr(sum.size()), n2, n3);
  }
};

int main() {
  Solution s;
  string a = "112358";
  a = "199100199";
  // a = "1023";
  // a = "101";
  cout << s.isAdditiveNumber(a) << endl;
  return 0;
}
