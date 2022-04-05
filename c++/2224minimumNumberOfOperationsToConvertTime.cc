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
  int convertTime(string current, string correct) {
    int h1, m1, h2, m2;
    sscanf(current.c_str(), "%d:%d", &h1, &m1);
    sscanf(correct.c_str(), "%d:%d", &h2, &m2);
    if (m2 < m1) {
      --h2;
      m2 += 60;
    }
    int res = h2 - h1;
    while (m2 - m1 >= 15) {
      ++res;
      m1 += 15;
    }
    while (m2 - m1 >= 5) {
      ++res;
      m1 += 5;
    }
    return res + m2 - m1;
  }
};

int main() {
  Solution s;
  
  return 0;
}
