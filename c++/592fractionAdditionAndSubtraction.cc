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
  string fractionAddition(string expression) {
    istringstream is (expression);
    int num1 = 0, dem1 = 0, num = 0, dem = 1;
    char c = '/';
    while (is >> num1 >> c >> dem1) {
      num = num * dem1 + num1 * dem;
      dem = dem * dem1;
      int tmp = gcd(dem, num);  // gcd() c++17
      num /= tmp;
      dem /= tmp;
    }
    return to_string(num) + "/" + to_string(dem);
  }
};

int main() {
  Solution s;
  string a = "-1/2+1/2+1/3";
  a = "1/3-1/2";
  cout << s.fractionAddition(a) << endl;
  return 0;
}
