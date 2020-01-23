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
  vector<int> getNoZeroIntegers(int n) {
    for (int a=1; a<n; ++a) {
      int b = n - a;
      if (to_string(a).find('0') == string::npos && to_string(b).find('0') == string::npos)
        return {a, b};
    }
    return {};
  }
};

int main() {
  Solution s;
  
  return 0;
}
