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
  char findTheDifference(string s, string t) {
    int t1 = 0, t2 = 0, i = 0;
    for (int stop = s.size(); i < stop; ++i) {
      t1 += s[i];
      t2 += t[i];
    }
    return t2 + t[i] - t1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
