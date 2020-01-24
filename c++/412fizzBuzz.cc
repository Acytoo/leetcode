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
  vector<string> fizzBuzz(int n) {
    vector<string> res;
    res.reserve(n);
    for (int i=1; i<=n; ++i) {
      string tmp = to_string(i);
      if (i%3 == 0) {
        tmp = "Fizz";
        if (i%5 == 0)
          tmp = "FizzBuzz";
      } else if (i%5 == 0) {
        tmp = "Buzz";
      }
      res.emplace_back(move(tmp));
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> res = s.fizzBuzz(15);
  for (string a: res)
    cout << a << endl;
  return 0;
}
